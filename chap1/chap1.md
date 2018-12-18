# 程序的基本概念

## 程序和编程语言

程序由一系列指令（Instruction）组成。

指令通常包含以下几类：

1. 输入
2. 输出
3. 基本运算
4. 测试和分支
5. 循环

编程语言（Programming Language）分为低级语言（Low-level Language）和高级语言（High-level Language）。

- 低级语言：机器语言（Machine Language）和汇编语言（Assembly Language）
- 高级语言：C、C++、Java、Python 

低级语言直接使用 计算机指令 写程序。
高级语言使用 语句（Statement） 写程序。

## 自然语言和形式语言

自然语言（Natural Language）是人类讲的语言。
形式语言（Formal Language）是人类为了特定的应用而设计的语言。

形式语言有严格的语法（Syntax）规则。

- Syntax

语法 由 符号 和 结构 的规则所组成。
Syntax = Token + Structure

- Token

即合法的标识符，类似于自然语言中的单词和标点。

Token 的规则称为 词法（Lexical） 规则。

- Structure

指 Token 的排列方式。

Structure 的规则称为 语法（Grammar） 规则。

- Parse

分析句子结构的过程称为 解析。

## 程序的调试

BUG：

- 编译时错误

无法通过编译，无法生成可执行文件。

- 运行时错误

编译通过，可生成可执行文件。在运行时出错而程序崩溃。

- 逻辑错误和语义错误

编译通过，可生成可执行文件。但是程序干了别的事情。

## 第一个程序

```c
#include <stdio.h>

/* main: generate some simple output */

int main(void)
{
	printf("Hello, world.\n");
	return 0;
}
```

使用 gcc 编译源代码的方式：
1. `gcc main.c`
2. `gcc main.c -o app`
3. `gcc main.c -o app -Wall`
