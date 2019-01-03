# 链接详解

## 多目标文件的链接

一步编译：
```
$ gcc main.c stack.c -o main
```

多步编译：
```
$ gcc -c main.c
$ gcc -c stack.c
$ gcc main.o stack.o -o main
```

链接的过程是由一个链接脚本控制的。

默认链接脚本可以用 `ld --verbose` 命令查看。

## 定义和声明

`extern` 关键字表示被修饰的标识符具有 External Linkage。

标识符具有 External Linkage 表示：如果在多个源文件中声明了该标识符，那么这些声明指的是同一个函数，链接之后是一个 `GLOBAL` 符号，代表同一个地址。

函数声明中的 `extern` 也可以省略不写，不写 `extern` 的函数声明也表示这个函数具有 External Linkage。

`static` 关键字表示被修饰的标识符具有 Internal Linkage。

凡是被多次声明的变量或函数，必须有且仅有一个声明是定义，或者一个定义也没有，链接器就无法完成链接。

`external int top;` 这是变量声明，而不是变量定义，因为它不分配存储空间（`top` 在定义它的源文件中分配）。

函数声明的 `extern` 可写可不写，而变量声明如果不写 `extern` 意思就变了。

如果变量属于模块内部，用 `static` 修饰它，能阻止外界访问变量。

### 头文件

示例（stack.h）：
```c
#ifndef STACK_H
#define STACK_H
extern void push(char);
extern char pop(void);
extern int is_empty(void);
#endif
```

gcc 的头文件查找顺序：
- 尖括号（`#include <stdio.h>`）
	1. 首先查找 `-I` 选项指定的目录
	2. 查找系统的头文件目录
- 双引号（`#include "stack.h"`）
	1. 首先查找包含头文件的 `.c` 文件所在的目录
	2. 然后查找 `-I` 选项指定的目录
	3. 然后查找系统的头文件目录

头文件中出现的变量或函数声明一定不能是定义。

## 静态库

打包一个静态库的步骤：
1. 将模块编译成目标文件 - `$ gcc -c stack/stack.c stack/push.c stack/pop.c stack/is_empty.c`。
2. 打包一个静态库 `ar rs libstack.a stack.o push.o pop.o is_empty.o`。

库文件名都是以 `lib` 开头的，静态库以 `.a` 作为后缀，表示 Archive。

将库文件和 `main.c` 编译链接到一起 `$ gcc main.c -L. -lstack -Istack -o main`。
- `-L.` 选项告诉编译器去哪里找需要的库文件
- `-lstack` 选项告诉编译器要链接 `libstack.a` 库
- `-I` 选项告诉编译器要去哪里找头文件

即使库文件就在当前目录，编译器默认也不会去找的。

编译器默认会找的目录可以使用 `$ gcc -print-search-dirs` 查看。

编译器是优先考虑共享库的。

## 共享库

## 虚拟内存管理
















