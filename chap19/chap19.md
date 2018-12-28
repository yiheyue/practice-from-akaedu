# 汇编与 C 之间的关系

## 函数调用

反汇编
```
$ gcc -g foo.c -o app
$ objdump -dS app
```

gdb 命令：
```
/* 反汇编当前函数或者指定的函数 */
(gdb) disassemble

/* 一条指令一条指令地单步执行 */
(gdb) si

/* 显示所有寄存器的当前值 */
(gdb) info registers

/* 打印寄存器的值 */
(gdb) p $esp
```

在执行程序时，操作系统为进程分配一块栈空间来保存函数栈帧，esp 寄存器总是指向栈顶，在 x86 平台上这个栈是从高地址向低地址增长的。

## main 函数和启动例程

gcc 的命令选项：
```
/* 生成经过预处理的源文件 */
$ gcc -E main.c -o main.i

/* 编译生成汇编文件 */
$ gcc -S main.c -o main.s

/* 生成目标文件 */
$ gcc -c main.c -o main.o

/* 生成可执行文件 */
$ gcc main.c -o main
```

查看符号表：
```
$ nm /usr/lib/ctr1.o
```

## 变量的存储布局

## 结构体和联合体

## C 内联汇编

## volatile 限定符
