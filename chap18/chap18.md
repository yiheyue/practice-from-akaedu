# x86 汇编程序基础

## 最简单的汇编程序

汇编与链接的命令：
```
// 汇编
$ as foo.s -o foo.o

// 链接
$ ld foo.o -o foo
```

汇编器（Assembler） `as` 可以将汇编程序中的助记符翻译成机器指令（二进制），生成目标文件。然后用链接器（Linker） `ld` 把目标文件链接成可执行文件。

链接主要有两个作用：
1. 修改目标文件中的信息，对地址做重定位
2. 把多个目标文件合并成一个可执行文件

分析下面的简单汇编程序 `hello.s`：
```s
# Simple example

	.section	.data

	.section	.text
	.globl	_start
_start:
	movl	$1, %eax
	movl	$4, %ebx
	int	$0x80
```
- `#` 表示单行注释。

- 以 `.` 开头的名称并不是指令的助记符，不会被翻译成机器指令，而是给汇编器一些特殊指示，称为汇编指示（Assembler Directive）或伪操作（Pseudo-operation）。

- `.section` 指示把代码划分成若干个段（Section）。

- 程序被操作系统加载执行时，每个段被加载到不同的地址，操作系统对不同的页面设置不同的读、写、执行权限。

- `.data` 段保存程序的数据，是可读可写的，相当于 C 程序的全局变量。上例中没有定义数据，所以 `.data` 段是空的。

- `.text` 段保存代码，是只读和可执行的。后面的那些指令都属于 `.text` 段。

- `_start` 是一个符号（Symbol），符号在汇编程序中代表一个地址，可以用在指令中。汇编程序经过汇编器的处理后，所有的符号都被替换成它所代表的地址值。`_start` 类似于 C 程序中的 `main` 函数一样特殊，是整个程序的入口。链接器在链接时会查找目标文件中的 `_start` 符号代表的地址，把它设置成整个程序的入口地址，所以每个汇编程序都要提供一个 `_start` 符号并且用 `.globl` 声明。

- 在 C 语言中我们通过变量名访问一个变量，其实就是读写某个地址的内存单元；我们通过函数名调用一个函数，其实就是跳转到该函数的第一条指令所在的地址，所以变量名和函数名都是符号，本质上是代表内存地址的。

- `.globl` 指示告诉汇编器，`_start` 这个符号要被链接器用到，所以要在目标文件的符号表中标记它是一个全局符号。如果一个符号没有用 `.globl` 声明，就表示这个符号不会被链接器用到。

- `_start:` 定义了 `_start` 符号，当汇编器看到一个符号定义时，就把它后面的一条指令的地址作为这个符号所代表的地址。

- `movl	$1, %eax` 是一条数据传送指令，这条指令要求 CPU 内部产生一个立即数 1 并保存到 eax 寄存器中。`movl` 的后缀 l 表示 long，说明是32位的传送指令。

- 在汇编程序中，立即数前面要加 `$`，寄存器名前面要加 `%`。

- 在 AT&T 汇编语法中，第一个操作数是 源操作数（src），第二个操作数是 目标操作数（dest）。

- `movl	$4, %ebx` 这条指令要求 CPU 内部产生一个立即数 4 并保存到 ebx 寄存器中。

- `int` 指令称为软中断指令，可以用这条指令故意产生一个异常。异常的处理和中断类似，CPU 从用户模式切换到特权模式，然后跳转到内核代码中执行异常处理程序。

- `0x80` 是一个参数，在异常处理程序中要根据这个参数决定如何处理，在 Linux 内核中 `int 0x80` 这种异常称为系统调用（System Call）。

- eax 和 ebx 的值是传递给系统调用的两个参数。
	- eax 的值是系统调用号，Linux 的各种系统调用都是由 `int $0x80` 指令引发的，内核需要通过 eax 判断用户要调哪个系统调用，`_exit` 的系统调用号是 1。
	- ebx 的值是传给 `_exit` 的参数，表示退出状态。
	- 大多数系统调用完成之后会返回用户空间继续执行后面的指令，而 `_exit` 系统调用比较特殊，它会中止掉当前进程，而不是返回用户空间继续执行。

- 上例采用的是 AT&T 的 x86 汇编语法，UNIX 平台的汇编器一直使用这种语法。而 intel 和 Microsoft 使用 intel 语法。

## x86 的寄存器

- eax - 通用寄存器

- ebx - 通用寄存器

- ecx - 通用寄存器

- edx - 通用寄存器

- edi - 通用寄存器

- esi - 通用寄存器

- ebp - 特殊寄存器 - 维护函数调用的栈帧

- esp - 特殊寄存器 - 维护函数调用的栈帧

- eip - 特殊寄存器 - 程序计数器

- eflags - 特殊寄存器 - 保存计算过程中产生的标志位

## 第二个汇编程序

第二个汇编程序如下：
```
	.section	.data
data_items:
	.long	3, 67, 34, 222, 45, 75, 54, 11, 0

	.section	.text
	.globl	_start
_start:
	movl	$0, %edi
	movl	data_items(, %edi, 4), %eax
	movl	%eax, %ebx

start_loop:
	cmpl	$0, %eax
	je	loop_exit
	incl	%edi
	movl	data_items(, %edi, 4), %eax
	cmpl	%ebx, %eax
	jle	start_loop
	movl	%eax, %ebx
	jmp	start_loop

loop_exit:
	movl	$1, %eax
	int	$0x80
```
- `data_items:` 定义了一个符号，它的地址是下面 `.long` 数组的首地址。

- `.long` 指示声明一组数，每个数占32位，相当于 C 语言中的数组。除了 `.long` 之外，常用的数据声明还有：
	- `.byte` 也是声明一组数，每个数占8位
	- `.ascii` 例如 `.ascii "Hello world\0"` 声明 11 个数，取值为相应的 ASCII 码。

- `movl $0, %edi` 初始化 `edi`，指向数组的第0个元素。

- `movl data_items(, %edi, 4), %eax` 把数组的第0个元素送到 eax 寄存器中。

- 比较指令一般和跳转指令一起配合使用。

## 寻址方式

内存寻址在指令中的通用格式：`ADDRESS_OR_OFFSET(%BASE_OR_OFFSET, %INDEX, MULTIPLIER)`

通用格式表示的最终地址为：`FINAL_ADDRESS = ADDRESS_OR_OFFSET + BASE_OR_OFFSET + MULTIPLIER * INDEX`

其中 `ADDRESS_OR_OFFSET` 和 `MULTIPLIER` 必须是常数，`BASE_OR_OFFSET` 和 `INDEX` 必须是寄存器。在有些寻址方式中会省略这 4 项中的某些项，相当于这些项是 0。

x86 常用的几种寻址方式：

- 直接寻址（Direct Addressing Mode），只使用 `ADDRESS_OR_OFFSET` 寻址。

- 变址寻址（Indexed Addressing Mode）

- 间接寻址（Indirect Addressing Mode），只使用 `BASE_OR_OFFSET` 寻址。

- 基址寻址（Base Pointer Addressing Mode），只使用 `ADDRESS_OR_OFFSET` 和 `BASE_OR_OFFSET` 寻址。

- 立即数寻址（Immediate Mode）

- 寄存器寻址（Register Addressing Mode）

## ELF 文件

ELF 文件格式是一个开放标准，各种 UNIX 系统的可执行文件都采用 ELF 格式，它有三种不同的类型：
- 可重定位的目标文件（Relocatable，或者 Object File）
- 可执行文件（Executable）
- 共享库（Shared Object，或者 Shared Library）

汇编程序从汇编到运行的整个过程：
1. 编写一个汇编程序 `max.s`

2. 汇编器读取这个文本文件转换成目标文件 `max.o`，目标文件由若干个 Section 组成，我们在汇编程序中声明的 `.section` 会成为目标文件中的 Section，此外汇编器还会自动添加一些 Section。

3. 然后链接器把目标文件中的 Section 合并成几个 Segment，生成可执行文件 `max`。

4. 最后加载器（Loader）根据可执行文件中的 Segment 信息加载运行这个程序。

链接器把 ELF 文件看成是 Section 的集合，而加载器把 ELF 文件看成是 Segment 的集合。

Section Header Table & Program Header Table：
- 目标文件需要链接器做进一步处理，所以一定要有 Section Header Table
- 可执行文件需要加载器加载运行，所以一定要有 Program Header Table
- 共享库既要加载运行，又要在加载时做动态链接，所以既要有 Section Header Table，又要有 Program Header Table

### 目标文件 与 可执行文件

本小节使用的命令：
```
// 读取 ELF 文件中的信息
$ readelf -a foo.o

// 打印二进制文件
$ hexdump -C foo.o

// 反汇编
$ objdump -d foo.o
```
目标文件和可执行文件的详细区别可对照 `max.o_elfinfo` `max.o_disasm` `max_elfinfo` `max_disasm`。
