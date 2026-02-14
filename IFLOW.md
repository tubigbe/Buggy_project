# IFLOW.md - 项目上下文说明

## 🚨 重要提醒：执行任务前的必读流程

**在执行任何任务之前，AI 助手必须先浏览 `skills/` 文件夹中的所有内容！**

### 执行任务前的标准流程

1. **第一步：浏览 Skills 文件夹**
   - 读取 `skills/` 目录下的所有 `.md` 和 `.json` 文件
   - 特别关注：
     - `project_background_and_goals.md` - 项目背景、目标和角色定位
     - `project_progress.md` - 当前项目进展和状态
     - `document_readability_requirements.md` - 文档可读性要求
     - `json_formatting_standards.md` - JSON 格式化标准
     - `git_folder_restrictions.md` - Git 文件夹操作限制（最高优先级）
     - `pin_settings.json` - 引脚配置文件

2. **第二步：理解项目当前状态**
   - 确认项目当前所处阶段（新手/进阶/完成）
   - 了解已完成和待完成的任务
   - 理解核心职责和目标

3. **第三步：遵循规范执行任务**
   - 严格遵守 Git 文件夹操作限制
   - 遵循文档可读性和 JSON 格式化标准
   - 根据项目进展选择合适的实现方式

4. **第四步：检查项目设置与 Skills 同步**
   - **必须检查**：项目实际设置与 `skills/pin_settings.json` 中的配置是否一致
   - **重点检查项**：
     - 引脚配置（TRISA, TRISC, ANSELA, ANSELC 等）
     - ADC 通道配置（ADC_CHANNEL_ANA0, ADC_CHANNEL_ANC2）
     - PWM 配置（PWM1/CCP1 和 PWM5 的初始占空比）
     - 定时器配置（TMR0, TMR2 的时钟频率和最大计数值）
     - 应用逻辑（中断处理函数、ADC-PWM 转换公式）
   - **同步规则**：
     - 如果项目设置与 Skills 不同，**按照项目实际设置修改 Skills**
     - 每次修改后，必须告知用户修改了哪些地方
     - 确保 `skills/pin_settings.json` 始终反映项目的最新配置
   - **为什么重要**：
     - Skills 文件夹是项目配置的"真相来源"
     - 确保 AI 助手基于最新的项目配置工作
     - 避免因配置不一致导致的错误

### Skills 文件夹核心约束

| 文件 | 核心要求 | 优先级 |
|------|---------|--------|
| `git_folder_restrictions.md` | 严禁读取/修改/删除 `.git` 文件夹 | ⭐⭐⭐ 最高 |
| `document_readability_requirements.md` | 所有文档必须高可读性 | ⭐⭐⭐ 高 |
| `json_formatting_standards.md` | JSON 使用 2 空格缩进，格式化 | ⭐⭐⭐ 高 |
| `project_background_and_goals.md` | 理解项目是自主寻线小车，使用电感感应+闭环控制 | ⭐⭐ 中 |
| `project_progress.md` | 当前处于新手阶段，已完成环境配置 | ⭐⭐ 中 |
| `pin_settings.json` | 引脚配置参考，保持同步 | ⭐ 中 |

---

本文档提供 Buggy 项目（基于 PIC16F18326 微控制器的智能小车）的完整上下文信息，用于指导 AI 助手进行代码开发和维护。

---

## Skills 文件夹内容概览

`skills/` 文件夹包含 AI 助手执行任务时必须遵循的规范和项目上下文信息：

### 1. 文件列表

| 文件名 | 类型 | 内容描述 |
|--------|------|---------|
| `project_background_and_goals.md` | Markdown | 项目背景、核心职责、技术要点 |
| `project_progress.md` | Markdown | 项目进展、当前阶段、下一步计划 |
| `document_readability_requirements.md` | Markdown | 文档可读性规范（JSON 和 Markdown） |
| `json_formatting_standards.md` | Markdown | JSON 文件格式化详细标准 |
| `git_folder_restrictions.md` | Markdown | Git 文件夹操作限制（最高优先级） |
| `pin_settings.json` | JSON | 引脚配置、模块配置、应用逻辑 |

### 2. 核心项目信息（来自 Skills）

**项目性质**：自主寻线小车
- **核心技术**：电感感应 + 闭环控制
- **执行逻辑**：时间触发调度（50ms 中断周期）
- **数据流向**：传感器输入 → ADC 读取 → 控制算法 → PWM 输出 → 电机驱动

**当前状态**（截至 2026-02-10）：
- ✅ 开发环境配置已完成
- 🔄 基础理论学习进行中（30%）
- ⏳ 接口配置待开始
- ⏳ 控制算法实现待开始
- ⏳ 系统集成测试待开始

**控制算法目标**：
- P / PI / PID 控制算法实现
- 参数整定以优化性能
- 实现自主路径跟踪

### 3. 关键约束

- **Git 安全**：严禁操作 `.git` 文件夹（`git_folder_restrictions.md`）
- **JSON 格式**：使用 2 空格缩进，确保高可读性（`json_formatting_standards.md`）
- **文档规范**：统一格式，保持同步更新（`document_readability_requirements.md`）
- **设置同步**：⚠️ **必须确保 `skills/pin_settings.json` 与项目实际设置完全一致**，如有差异按项目设置更新 Skills

---

## 项目概述

**项目名称**: Super Fast Buggy

**项目类型**: 嵌入式系统 / 微控制器项目

**核心平台**: Microchip PIC16F18326 微控制器

**项目目的**: 开发一个基于 PIC16F18326 的智能小车系统，具备电机控制、传感器反馈和中断驱动的实时控制功能。

**主要技术栈**:
- **微控制器**: PIC16F18326 (8位 PIC 微控制器)
- **开发环境**: MPLAB X IDE
- **代码生成工具**: MPLAB Code Configurator (MCC) v5.8.4
- **编程语言**: C 语言
- **构建系统**: Make (MPLAB X 项目配置)

**项目结构**:
```
Buggy_project/
├── files/
│   └── Super_Fast_Buggy.X/        # 主项目文件夹
│       ├── main.c                 # 主程序入口
│       ├── Makefile               # 构建配置
│       ├── Super_Fast_Buggy.mc3   # MCC 项目配置文件
│       ├── mcc_generated_files/   # MCC 自动生成的驱动文件
│       │   ├── adc/               # ADC 模块驱动
│       │   ├── pwm/               # PWM 模块驱动 (CCP1, PWM5)
│       │   ├── system/            # 系统配置 (pins, clock, interrupt)
│       │   └── timer/             # 定时器模块 (TMR0, TMR2, TMR6)
│       ├── build/                 # 构建输出目录
│       ├── debug/                 # 调试输出目录
│       └── dist/                  # 发布输出目录
├── guidence/                      # 项目文档和参考资料
│   ├── control_system/            # 控制系统文档
│   ├── motor/                     # 电机控制文档
│   ├── sensor/                    # 传感器电路文档
│   ├── Current Voltage.pdf        # 电流电压参考资料
│   └── EEE2008_Guidance_Notes_2025_2026.pdf
├── log/                           # 日志目录
├── skills/                        # AI Skills 目录（提示词管理）
├── auto_backup.ps1                # 自动备份脚本
└── IFLOW.md                      # 本文件
```

---

## 核心功能模块

### 1. 主程序 (main.c)

主程序实现了以下核心功能：

- **中断驱动的定时控制**: 使用 TMR0 定时器中断进行周期性控制
- **ADC 采样**: 通过 ADC_CHANNEL_ANC2 读取传感器数据
- **PWM 电机控制**: 根据 ADC 值动态调整 PWM5 占空比控制电机速度
- **数字 I/O 控制**: 使用 IO_RC1 进行数字信号输出（翻转控制）

**关键代码逻辑**:
```c
void timer_Interrupt_Routine(void)
{
    IO_RC1_Toggle();                          // 翻转 RC1 引脚状态
    ADCresult = ADC_ChannelSelectAndConvert(ADC_CHANNEL_ANC2);  // ADC 采样
    DutyCycle = ((uint32_t)((uint32_t)ADCresult*596))/1024;    // 计算占空比
    PWM5_LoadDutyValue(DutyCycle);           // 设置 PWM 占空比
}
```

### 2. 硬件模块配置

#### 定时器模块 (Timer)
- **TMR0**: 主定时器，用于周期性中断控制
- **TMR2**: 辅助定时器
- **TMR6**: 辅助定时器

#### PWM 模块
- **PWM5**: 电机速度控制输出
- **CCP1**: 捕获/比较/PWM 模块

#### ADC 模块
- **ADC_CHANNEL_ANC2**: 模拟输入通道（传感器数据采集）

#### 中断管理
- 全局中断使能
- 外设中断使能
- TMR0 溢出中断回调注册

### 3. MCC 生成的驱动文件

所有外设驱动文件由 MPLAB Code Configurator 自动生成，位于 `mcc_generated_files/` 目录：

- **system/pins.h**: GPIO 引脚定义和控制宏
- **system/clock.h**: 时钟配置
- **system/interrupt.h**: 中断管理
- **adc/**: ADC 模块驱动（adc.h, adc.c）
- **pwm/**: PWM 模块驱动（pwm5.h, ccp1.h）
- **timer/**: 定时器模块驱动（tmr0.h, tmr2.h, tmr6.h）

---

## 构建和运行

### 构建项目

在项目根目录 `E:\Buggy_project\files\Super_Fast_Buggy.X\` 下执行：

```bash
# 构建项目
make build

# 清理构建文件
make clean

# 完全清理（包括所有配置）
make clobber

# 构建所有配置
make all

# 显示帮助信息
make help
```

### 开发环境要求

- **MPLAB X IDE**: Microchip 的官方集成开发环境
- **XC8 编译器**: 8位 PIC 微控制器 C 编译器
- **PICKit 3/4 或 ICD 3/4**: 编程器/调试器

### 编程和调试

1. 在 MPLAB X IDE 中打开项目 `Super_Fast_Buggy.X`
2. 选择正确的编程器（PICKit 3/4 或 ICD 3/4）
3. 点击"Build Project"图标构建项目
4. 点击"Make and Program Device"图标编译并烧录到目标设备
5. 使用调试器进行在线调试

---

## 开发约定

### 代码风格

- **语言**: 标准 C 语言
- **注释**: 使用 Microchip MCC 生成的标准注释格式
- **命名约定**:
  - 函数名: 大驼峰命名法（如 `ADC_ChannelSelectAndConvert`）
  - 变量名: 大驼峰命名法（如 `ADCresult`, `DutyCycle`）
  - 宏定义: 全大写，下划线分隔（如 `ADC_CHANNEL_ANC2`）

### 修改 MCC 配置

**重要**: MCC 生成的文件（`mcc_generated_files/` 目录下的所有文件）不应手动编辑。

如需修改硬件配置：
1. 在 MPLAB X IDE 中打开 `Super_Fast_Buggy.mc3` 文件
2. 使用 MCC 界面修改配置
3. MCC 会自动重新生成所有驱动文件
4. 确认更改后，重新构建项目

### 自定义代码位置

- **主程序逻辑**: `main.c` 文件
- **自定义中断处理**: 在 `main.c` 中定义中断回调函数
- **应用层功能**: 建议在 `main.c` 中添加新的功能函数

### 引脚定义

所有引脚的宏定义在 `mcc_generated_files/system/pins.h` 中。使用宏操作引脚：

```c
// 设置引脚为高电平
IO_RC1_SetHigh();

// 设置引脚为低电平
IO_RC1_SetLow();

// 翻转引脚状态
IO_RC1_Toggle();

// 读取引脚状态
value = IO_RA0_GetValue();

// 设置引脚为数字输出
IO_RA0_SetDigitalOutput();

// 设置引脚为数字输入
IO_RA0_SetDigitalInput();
```

---

## 文档和参考资料

项目包含详细的技术文档，位于 `guidence/` 目录：

### 控制系统文档
- `PIC Getting Started Guide_v1.3.pdf`: PIC 开发入门指南
- `PIC Programmer Connections.pdf`: 编程器连接指南
- `PIC16F18326_Datasheet.pdf`: 微控制器数据手册（核心参考）
- `PIC16F18326_Errata.pdf`: 微控制器勘误表

### 电机控制文档
- `1N5819_Datasheet.pdf`: 肖特基二极管数据手册
- `BriefIntroductionToHBridge.pdf`: H 桥电路简介
- `IPP80P03P4L_04_Datasheet.pdf`: P沟道 MOSFET 数据手册
- `IRFB7440_Datasheet.pdf`: N沟道 MOSFET 数据手册
- `IRL40B215_Datasheet.pdf`: N沟道 MOSFET 数据手册
- `New H Bridge v2.pdf`: H 桥电路设计文档
- `TC4426CPA_Datasheet.pdf`: MOSFET 驱动器数据手册

### 传感器文档
- `Edited_Op-Amp_Circuit.pdf`: 运算放大器电路文档
- `EEE2008_Sensor_Circuit_Introduction_25_26.pdf`: 传感器电路介绍
- `TL974_Datasheet.pdf`: 运放数据手册

### 其他参考资料
- `Current Voltage.pdf`: 电流电压参考资料
- `EEE2008_Guidance_Notes_2025_2026.pdf`: 课程指导笔记

---

## 自动化工具

### 自动备份脚本 (auto_backup.ps1)

项目包含一个 PowerShell 自动备份脚本，用于：

- 检测 Git 仓库变更
- Skills 目录守卫检查（确保代码更新时 Skills 同步更新）
- 自动提交和推送到远程 GitHub 仓库
- 详细的日志记录

**使用方法**:
```powershell
# 在项目根目录执行
.\auto_backup.ps1
```

**配置项**（在脚本开头）:
- `$PROJECT_PATH`: 项目根目录
- `$SKILLS_PATH`: AI Skills 目录路径
- `$REMOTE_TARGET`: Git 远程仓库名称（默认：origin）
- `$MODIFICATION_DESCRIPTION`: 修改说明（可留空，运行时提示输入）

---

## Git 工作流

**当前分支**: (使用 `git status` 查看)

**远程仓库**: https://github.com/tubigbe/Buggy_project.git

**常用 Git 命令**:
```bash
# 查看当前状态
git status

# 添加所有更改
git add .

# 提交更改
git commit -m "描述修改内容"

# 推送到远程仓库
git push origin <branch-name>

# 拉取最新更改
git pull origin <branch-name>

# 查看提交历史
git log -n 3
```

**提交消息格式**:
```
[Auto-Sync] YYYY-MM-DD HH:mm | 修改说明: <详细说明>
```

---

## 常见任务

> **提醒**：在执行以下任何任务之前，请确保已经浏览了 `skills/` 文件夹中的所有文件，特别是 `project_progress.md` 和 `project_background_and_goals.md`，以了解项目当前状态和目标。

### 同步项目设置到 Skills

**目的**：确保 `skills/pin_settings.json` 与项目实际配置保持一致

**检查步骤**：
1. 读取 `files/Super_Fast_Buggy.X/mcc_generated_files/system/src/pins.c` 获取引脚配置
2. 读取 `files/Super_Fast_Buggy.X/mcc_generated_files/timer/tmr0.h` 和 `tmr2.h` 获取定时器配置
3. 读取 `files/Super_Fast_Buggy.X/mcc_generated_files/pwm/ccp1.c` 和 `pwm5.h` 获取 PWM 配置
4. 读取 `files/Super_Fast_Buggy.X/mcc_generated_files/adc/adc.h` 获取 ADC 配置
5. 读取 `files/Super_Fast_Buggy.X/main.c` 获取应用逻辑
6. 对比 `skills/pin_settings.json` 中的配置
7. 如有差异，按照项目实际设置更新 `skills/pin_settings.json`
8. 告知用户修改了哪些地方

**为什么重要**：
- Skills 文件夹是项目配置的权威参考
- 避免配置不一致导致的开发错误
- 确保 AI 助手基于正确的配置工作

### 添加新的传感器输入

1. 在 MCC 中配置新的 ADC 通道
2. 在 `main.c` 中使用 `ADC_ChannelSelectAndConvert(ADC_CHANNEL_XXX)` 读取数据
3. 根据需要在定时器中断中添加采样逻辑

### 调整电机控制参数

- 修改 `DutyCycle` 计算公式中的系数（当前为 `596`）
- 该系数决定 ADC 值到 PWM 占空比的映射关系
- 测试调整后的参数以确保期望的电机行为

### 添加新的中断服务程序

1. 在 MCC 中配置所需的外设中断
2. 在 `main.c` 中定义中断回调函数
3. 使用相应的回调注册函数注册回调（如 `TMR0_OverflowCallbackRegister`）
4. 确保全局中断和外设中断已使能

### 修改定时器频率

1. 在 MCC 中打开定时器配置（TMR0/TMR2/TMR6）
2. 调整预分频器和周期值以获得所需的频率
3. MCC 会自动更新相关的驱动代码
4. 重新构建项目

---

## 注意事项

1. **任务执行前的必读流程**: ⚠️ 在执行任何任务之前，必须先浏览 `skills/` 文件夹中的所有内容！
2. **不要手动编辑 MCC 生成的文件**: 任何硬件配置修改都应通过 MCC 界面进行
3. **保持 Git 同步**: 使用 `auto_backup.ps1` 脚本或手动提交更改到 Git 仓库
4. **Skills 目录守卫**: 如果代码更新但 Skills 未同步，备份脚本会警告并阻止提交
5. **Git 文件夹安全**: 严禁读取、修改或删除 `.git` 文件夹及其任何内容（最高优先级）
6. **文档和 JSON 格式**: 遵循 `skills/` 中的可读性要求和格式化标准
7. **硬件安全**: 在烧录代码前，确保硬件连接正确，避免损坏器件
8. **数据手册参考**: 进行硬件修改前，请参考 `PIC16F18326_Datasheet.pdf`
9. **测试验证**: 每次代码修改后，都要在硬件上进行充分测试

---

## 联系和支持

如有问题或需要技术支持，请参考以下资源：

- Microchip 官方文档: https://www.microchip.com
- MPLAB X IDE 文档: MPLAB X IDE 内置帮助
- 项目 Git 仓库: https://github.com/tubigbe/Buggy_project

---

**文档版本**: 1.0

**最后更新**: 2026年2月14日

**维护者**: iFlow CLI 助手