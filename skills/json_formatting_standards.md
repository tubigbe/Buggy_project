# JSON 文件格式化标准

## 概述
本项目中的 JSON 配置文件（如 `pin_settings.json`）必须保持高可读性，以便于人类阅读、编辑和维护。

## 格式化要求

### 1. 缩进
- 使用 **2 空格** 缩进
- 不使用制表符（Tab）

### 2. 换行
- 每个键值对（key-value pair）单独占一行
- 数组元素必须分行显示
- 对象（object）内的元素分行显示
- 层次嵌套使用换行和缩进清晰展示

### 3. 间距
- 冒号（`:`）后必须有一个空格
- 逗号（`,`）前不要空格，后不要空格（除非是数组/对象末尾的逗号）

### 4. 示例

#### 正确格式（高可读性）
```json
{
  "project_name": "Super_Fast_Buggy",
  "chip": "PIC16F18326",
  "pins": [
    {
      "pin_name": "RA0",
      "direction": "INPUT",
      "mode": "ANALOG"
    },
    {
      "pin_name": "RA2",
      "direction": "OUTPUT",
      "mode": "DIGITAL"
    }
  ]
}
```

#### 错误格式（低可读性）
```json
{"project_name":"Super_Fast_Buggy","chip":"PIC16F18326","pins":[{"pin_name":"RA0","direction":"INPUT","mode":"ANALOG"},{"pin_name":"RA2","direction":"OUTPUT","mode":"DIGITAL"}]}
```

## 工具使用

### 格式化命令（Python）
```bash
python -c "import json; data = json.load(open('文件路径.json', 'r', encoding='utf-8')); open('文件路径.json', 'w', encoding='utf-8').write(json.dumps(data, ensure_ascii=False, indent=2))"
```

### 注意事项
- 使用 `ensure_ascii=False` 保留中文字符的可读性
- 使用 `indent=2` 确保一致的 2 空格缩进
- 指定 `encoding='utf-8'` 避免编码问题

## 应用场景
此标准适用于项目中所有 JSON 配置文件，包括但不限于：
- `pin_settings.json` - 引脚配置文件
- 其他可能新增的 JSON 配置文件

## 验证标准
合格的 JSON 文件应该：
- ✅ 可以直接在文本编辑器中阅读
- ✅ 层次结构一目了然
- ✅ 无需工具即可理解内容
- ✅ 便于手动修改和更新