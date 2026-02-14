# ================================================================================
# AI 协作自动化备份脚本
# ================================================================================
# 用途：自动同步本地 Git 仓库与远程 GitHub 仓库
# 特性：代码变更检测、Skills 目录守卫、自动提交推送
# ================================================================================

# ================================================================================
# 用户配置区域 - 请根据项目修改以下变量
# ================================================================================

# 项目根目录（建议使用绝对路径）
$PROJECT_PATH = "E:\Buggy_project"

# AI Skills 目录路径（相对于项目根目录或绝对路径）
$SKILLS_PATH = "E:\Buggy_project\skills"

# GitHub 远程仓库名称（如：origin）
$REMOTE_TARGET = "origin"

# 提交信息中的修改说明（可留空，脚本会提示输入）
$MODIFICATION_DESCRIPTION = ""

# ================================================================================
# 函数定义
# ================================================================================

# 日志记录函数
function Write-Log {
    param (
        [string]$Message,
        [string]$Level = "INFO"
    )
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $logMessage = "[$timestamp] [$Level] $Message"
    Write-Host $logMessage
    return $logMessage
}

# 检查 Git 是否初始化
function Test-GitRepository {
    $gitDir = Join-Path $PROJECT_PATH ".git"
    return Test-Path $gitDir
}

# 检查是否有变更
function Test-HasChanges {
    Push-Location $PROJECT_PATH
    $status = git status --porcelain
    Pop-Location
    return -not [string]::IsNullOrWhiteSpace($status)
}

# 检查 Skills 目录是否有变更
function Test-SkillsHasChanges {
    Push-Location $PROJECT_PATH
    $status = git status --porcelain $SKILLS_PATH
    Pop-Location
    return -not [string]::IsNullOrWhiteSpace($status)
}

# 获取变更摘要
function Get-ChangeSummary {
    Push-Location $PROJECT_PATH
    $changes = git status --short
    Pop-Location
    return $changes
}

# ================================================================================
# 主程序逻辑
# ================================================================================

# 日志文件路径
$LOG_DIR = Join-Path $PROJECT_PATH "log"
if (-not (Test-Path $LOG_DIR)) {
    New-Item -ItemType Directory -Path $LOG_DIR -Force | Out-Null
}
$LOG_FILE = Join-Path $LOG_DIR "backup_log_$(Get-Date -Format 'yyyyMMdd').txt"

# 启动日志记录
$logEntries = @()
$logEntries += Write-Log "=== 自动备份脚本启动 ==="

try {
    # 验证项目路径
    if (-not (Test-Path $PROJECT_PATH)) {
        throw "项目路径不存在：$PROJECT_PATH"
    }
    $logEntries += Write-Log "项目路径：$PROJECT_PATH"

    # 验证 Skills 路径
    if (-not (Test-Path $SKILLS_PATH)) {
        throw "Skills 目录不存在：$SKILLS_PATH"
    }
    $logEntries += Write-Log "Skills 目录：$SKILLS_PATH"

    # 检查 Git 仓库
    if (-not (Test-GitRepository)) {
        throw "项目未初始化 Git 仓库"
    }
    $logEntries += Write-Log "Git 仓库检测完成"

    # 变更检测
    $hasChanges = Test-HasChanges
    if (-not $hasChanges) {
        $logEntries += Write-Log "检测到无变更，无需备份"
        Write-Host "✓ 无变更，跳过备份"
        exit 0
    }
    $logEntries += Write-Log "检测到代码有变更"

    # 获取变更摘要
    $changeSummary = Get-ChangeSummary
    $logEntries += Write-Log "变更详情：`n$changeSummary"

    # Skills 目录守卫检查
    $skillsHasChanges = Test-SkillsHasChanges
    if ($hasChanges -and -not $skillsHasChanges) {
        $logEntries += Write-Log "⚠ 触发强制同步守卫：代码已更新但 Skills 未更新" "WARNING"
        
        Write-Host "`n========================================" -ForegroundColor Yellow
        Write-Host "⚠ 警告：检测到代码已更新，但 AI Skills 提示词未同步" -ForegroundColor Yellow
        Write-Host "========================================`n" -ForegroundColor Yellow
        
        Write-Host "请选择操作："
        Write-Host "  1. 手动更新 Skills 后重新运行脚本"
        Write-Host "  2. 输入无需更新的原因，继续备份`n"
        
        $choice = Read-Host "请输入选择 (1 或 2)"
        
        if ($choice -eq "1") {
            $logEntries += Write-Log "用户选择：手动更新 Skills 后重新运行"
            Write-Host "`n请更新 Skills 文件后重新运行脚本。"
            exit 0
        }
        elseif ($choice -eq "2") {
            $reason = Read-Host "请输入无需更新 Skills 的原因"
            $MODIFICATION_DESCRIPTION = "$MODIFICATION_DESCRIPTION [Skills Sync Confirmed/Reason: $reason]"
            $logEntries += Write-Log "用户输入的无需更新原因：$reason"
        }
        else {
            $logEntries += Write-Log "用户输入无效，退出脚本" "ERROR"
            Write-Host "`n✗ 无效选择，退出脚本"
            exit 1
        }
    }

    # 获取修改说明
    if ([string]::IsNullOrWhiteSpace($MODIFICATION_DESCRIPTION)) {
        $MODIFICATION_DESCRIPTION = Read-Host "请输入本次修改的说明"
    }
    $logEntries += Write-Log "修改说明：$MODIFICATION_DESCRIPTION"

    # 生成提交信息
    $commitMessage = "[Auto-Sync] $(Get-Date -Format 'yyyy-MM-dd HH:mm') | 修改说明: $MODIFICATION_DESCRIPTION"
    $logEntries += Write-Log "提交信息：$commitMessage"

    # 本地提交
    Push-Location $PROJECT_PATH
    Write-Host "`n正在添加文件..."
    git add .
    $logEntries += Write-Log "执行 git add ."

    Write-Host "正在提交..."
    git commit -m $commitMessage
    $logEntries += Write-Log "执行 git commit"
    Pop-Location

    # 远程推送
    Write-Host "`n正在推送到远程仓库..."
    Push-Location $PROJECT_PATH
    $pushResult = git push $REMOTE_TARGET 2>&1
    $pushExitCode = $LASTEXITCODE
    Pop-Location

    if ($pushExitCode -ne 0) {
        $logEntries += Write-Log "推送失败！错误信息：$pushResult" "ERROR"
        Write-Host "`n✗ 推送失败！请检查网络连接或远程仓库配置" -ForegroundColor Red
        Write-Host "错误详情：`n$pushResult"
        
        # 保存日志
        $logEntries | Out-File -FilePath $LOG_FILE -Encoding UTF8 -Append
        exit 1
    }

    $logEntries += Write-Log "推送成功"
    Write-Host "`n✓ 备份成功！" -ForegroundColor Green

} catch {
    $logEntries += Write-Log "脚本执行失败：$($_.Exception.Message)" "ERROR"
    Write-Host "`n✗ 脚本执行失败：" -ForegroundColor Red
    Write-Host "$($_.Exception.Message)"
    
    # 保存日志
    $logEntries | Out-File -FilePath $LOG_FILE -Encoding UTF8 -Append
    exit 1
}

# 保存日志
$logEntries += Write-Log "=== 脚本执行完成 ==="
$logEntries | Out-File -FilePath $LOG_FILE -Encoding UTF8 -Append

Write-Host "`n日志已保存至：$LOG_FILE"