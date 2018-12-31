# 汇编与 C 之间的关系

## 函数调用

如果在编译时加上 `-g` 选项，那么用 `objdump` 反汇编时可以把 C 代码和汇编代码穿插起来显示。命令如下：
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

注意函数调用和返回过程中的这些规则：
- 参数压栈传递，并且是从右向左依次压栈。
- ebp 寄存器总是指向当前栈帧的栈底。
- 返回值通过 eax 寄存器传递。

上述的规则并不是体系结构所强加的，ebp 寄存器并不是必须这么用，函数的参数和返回值也不是必须要这么传，只是操作系统和编译器选择了以这样的方式实现 C 代码中的函数调用，这称为 Calling Convention，Call Convention 是操作系统二进制接口规范（ABI，Application Binary Interface）的一部分。

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

整个程序的入口点是 `ctr1.o` 中提供的 `_start`，它先做一些初始化工作，然后调用 C 代码中提供的 `main` 函数。

```
$ ld /usr/lib/ctr1.o /usr/lib/ctri.o main.o -o main -lc -dynamic-linker /lib/ld-linux.so.2
```
上述链接过程：
1. 操作系统在加载执行程序时，首先查看它有没有需要动态链接的未定义符号。
2. 如果需要做动态链接，就查看这个程序指定了哪些共享库（上述的例子使用 `-lc` 指定了 libc）以及用什么动态链接器（上述的例子使用了 `-dynamic-linker /lib/ld-linux.so.2` 指定了动态链接器）来做动态链接。
3. 动态链接器在共享库中查找这些符号的定义，完成链接过程。

函数多传了参数而不用是没有问题的；少传了参数而用了会出问题。

程序从启动到结束：
1. 启动例程调用 main 函数，main 函数 return 时仍返回启动例程中，main 函数的返回值被启动例程得到。
2. 启动例程得到 main 函数的返回值后，会立即用它做参数调用 exit 函数（需要包含头文件 stdlib.h）。
3. exit 函数先做一些清理工作，然后调用 `_exit` 系统调用终止进程。
4. main 函数的返回值最终被传给了 `_exit` 系统调用，称为进程的退出状态。

退出状态只有8位，而且被 shell 解释为无符号数。

## 变量的存储布局

```c
const int a = 12;
```
- 变量 a 用 `const` 修饰，表示 a 是只读的，不可修改。
- 变量 a 在定义时必须初始化。因为只有初始化时才有机会给它一个值，一旦定义之后就不能再赋值了。

```c
static int b = 10;
```
- `static` 修饰变量 b，导致它成为了一个 LOCAL 符号，不被链接器处理。
- 函数前也可以加 `static`，表明这个函数名符号是 LOCAL 的。
- `static` 变量不初始化，则初值为0。

函数的参数和局部变量是分配在栈上的，数组也一样，也是分配在栈上的。

虽然栈是从高地址向低地址增长的，但是数组总是从低地址向高地址排列的。

```c
register int c = 14;
```
- `register` 关键字指示编译器尽可能分配一个寄存器来存储这个变量。

C 语言作用域：
- 函数作用域（Function Scope）
- 文件作用域（File Scope）
- 块作用域（Block Scope）
- 函数原型作用域（Function Prototype Scope）

命名空间：
- 语句标号单独属于一个命名空间。
- `struct`、`enum` 和 `union` 的类型 Tag 属于一个命名空间。
- `struct` 和 `union` 的成员名属于一个命名空间。
- 所有其他标识符属于一个命名空间。

标识符的链接属性（Linkage）有三种：
1. 外部链接（External Linkage）
2. 内部链接（Internal Linkage）
3. 无链接（No Linkage）

存储类修饰符（Storage Class Specifier），可以修饰变量或函数声明：
- `static` 用它修饰的变量的存储空间是静态分配的，用它修饰的文件作用域的变量或函数具有 Internal Linkage。
- `auto` 用它修饰的变量在函数调用时自动在栈上分配存储空间，函数返回时自动释放。`auto` 不能修饰文件作用域的变量。
- `register` 用它修饰的变量编译器会尽可能分配给其一个存储器存储它。
- `typedef` 不是用来修饰变量的，而是定义一个类型名。

类型限定符（Type Qualifier）：
- `const`
- `restrict`
- `volatile`

变量的生存期（Storage Duration，Lifetime）：
- 静态生存期（Static Storage Duration）
- 自动生存期（Automatic Storage Duration）
- 动态分配生存期（Allocated Storage Duration）

## 结构体和联合体

- 虽然栈是从高地址向低地址增长的，但是结构体成员也是从低地址向高地址增长的，这一点和数组类似。

- 但是结构体和数组有一点不同，结构体成员并不是一个紧挨一个排列的，中间有空隙，称为填充（Padding）。

- 大多数计算机体系结构对于访问内存的指令是由限制的，在32位平台上，访问4字节的指令所访问的内存地址应该是4的整数倍；访问2字节的指令所访问的内存地址应该是2的整数倍。这称为对齐（Alignment）。

合理设计结构体成员的排列顺序可以节省存储空间：
```c
struct {
	char a;
	char b;
	short c;
	int d;
} s;
```

结构体中可以使用 bit-field 语法定义只占用几个 bit 的成员。

## C 内联汇编

gcc 提供了一种扩展语法可以在 C 代码中使用内联汇编（Inline Assembly）。最简单的格式是 `__asm__("assembly code");`，例如 `__asm__("nop");`，`nop` 这条指令什么都不做，只是让 CPU 空转一个指令执行周期。如果需要执行多条汇编指令，则应该用 `\n\t` 将各条指令分隔开，例如：
```c
__asm__("movl	$1, %eax\n\t"
	"movl	$4, %ebx\n\t"
	"int	$0x80");
```

通常 C 代码中的内联汇编需要和 C 的变量建立关联，需要用到完整的内敛汇编格式：
```c
__asm__(assembly template
	: output operands		/* optional */
	: input operands		/* optional */
	: list of clobbered registers	/* optional */
	);
```
- 这种格式由4部分组成，第一部分是汇编指令，第二部分和第三部分是约束条件，第四部分是在汇编指令中被修改过的寄存器列表，指示编译器哪些寄存器的值在执行这条 `__asm__` 语句时会改变。

- 第二部分指示汇编指令的运算结果要输出到哪些 C 操作数中，C 操作数应该是左值表达式。

- 第三部分指示汇编指令需要从哪些 C 操作数获得输入。

- 后三个部分都是可选的，如果有就填写，没有就空着，只写个 `:` 号，例如：
```c
#include <stdio.h>

int main(void)
{
	int a = 10;
	int b;

	__asm__("movl	%1, %%eax\n\t"
		"movl	%%eax, %0\n\t"
		: "=r"(b)
		: "r"(a)
		: "%eax"
		);

	printf("Result: %d, %d\n", a, b);

	return 0;
}
```
- 这个程序将变量 a 的值赋给 b。

- `"r"(a)` 指示编译器分配一个寄存器保存变量 a 的值，作为汇编指令的输入，也就是指令中的 `%1` （按照约束条件的顺序，b 对应 `%0`，a 对应 `%1`），至于 `%1` 究竟代表哪个寄存器则由编译器自己决定。

## volatile 限定符

设备寄存器具有以下特性：
- 设备寄存器中的数据不需要改写就可以自己发生变化，每次读上来的值都可能不一样。
- 连续多次向设备寄存器中写数据并不是在做无用功，而是有特殊意义的。

在 C 语言可以用 `volatile` 限定符修饰变量，就是告诉编译器，即使在编译时指定了优化选项，每次读这个变量仍然要老老实实从内存读取，每次写这个变量也仍然要老老实实写回内存，不能省略任何步骤。

除了设备寄存器需要用 `volatile` 限定之外，当一个全局变量被同一进程中的多个控制流程访问时也要用 `volatile` 限定，比如信号处理函数和多线程。
