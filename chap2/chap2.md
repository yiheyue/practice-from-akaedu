# 常量、变量和表达式

添加注释的方式：
1. /* comment */
2. // comment - 从 C++ 中借鉴的语法，在 C99 中被标准化

C 语言标准的三个阶段
1. Old Style C
2. C89/C90
3. C99

## 常量 - Constant

- 字符常量 character
- 整数常量 integer
- 浮点数常量 floating point
- 枚举常量

### 转义序列 转换说明

转义序列在 编译时 处理，转换说明在 运行时 处理。

- source file

"I am %d years old.\n"

- after compile

"I am %d years old.[LF]"

转义序列 - Escape Sequence

转换说明 - Conversion Specification

## 变量 - Variable

### 声明 定义

声明 - Declaration：
- 变量声明
- 函数声明
- 类型声明

定义 - Definition：
如果声明变量或者函数时，需要编译器为其分配存储空间，则可以称为定义变量或定义函数。类型声明不分配存储空间。

### 标识符 - Identifier

需要程序员取名的语法元素

规则：以 下划线 或者 字母 开头，其后可以是 下划线、字母 和 数字。

- 关键字 - Keyword
- 保留字 - Reserverd Word

关键字和保留字不能用作标识符。

## 赋值 - Assign

给变量赋值，就是将一个值保存到这块存储空间中。

### 初始化 - Initialization

定义和赋值一步完成称为变量的 初始化

初始化是一种特殊的声明，而不是一种赋值语句。

声明可以在{}之外，而语句只能在{}之中。

## 表达式 - Expression

操作数（Operand）或者是由操作数和运算符（Operator）组成的算式称为表达式。

任何表达式都有 值 和 类型 两个基本的概念。

有的表达式既可以做左值也可以做右值，而有的表达式只能做右值。

表达式做左值时表示一个存储位置。

运算符有 优先级 - Precedence 和 结合性 - Associativity。

C 语言中整数除法是 向零取整 的。

char 型本质上是整数类型。
