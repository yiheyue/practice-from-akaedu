# x86 汇编程序基础

## 最简单的汇编程序

1. 编写汇编文件 `hello.s`，用汇编器（Assembler）as 把汇编程序中的助记符翻译成机器指令，生成目标文件 `hello.o`。
```
$ as hello.s -o hello.o
```

2. 然后用链接器（Linker）ld 把目标文件链接成可执行文件 `hello`。
```
$ ld hello.o -o hello
```

链接主要有两个作用：
1. 修改目标文件中的信息，对地址做重定位
2. 把多个目标文件合并成一个可执行文件

```s
  .section  .data
```
- 在汇编程序中，#号表示单行注释。以 `.` 开头的名称并不是指令的助记符，不会被翻译成机器指令，而是给汇编器一些特殊指示，称为汇编指示（Assembler Directive）或伪操作（Pseudo-operation）。
- `.section` 指示把代码划分成若干个段（Section），`.data` 段保存程序的数据，是可读可写的，相当于 C 程序的全局变量。

```s
  .section  .text
```
- `.text` 段保存代码，是只读和可执行的。

```s
  .globl  _start
```
- `_start` 是一个符号（Symbol），符号在汇编程序中代表一个地址，可以用在指令中。
- `.globl` 指示告诉汇编器，`_start` 这个符号要被链接器用到，所以要在目标文件的符号表中标记它是一个全局符号。

```s
_start:
```
- 这里定义了 `_start` 符号，当汇编器看到一个符号定义时，就把它后面的一条指令的地址作为这个符号所代表的地址。

```s
  movl  $1, %eax
```
- 这是一条数据传送指令，这条指令要求 CPU 内部产生一个立即数 1 并保存到 eax 寄存器中。
- `movl` 的后缀 l 表示 long，说明是32位的传送指令。
- 在汇编程序中，立即数前面要加 `$`，寄存器名前面要加 `%`。
- 第一个操作数是 源操作数（src），第二个操作数是 目标操作数（dest）。

```s
 movl  $4, %ebx
```
- 这条指令要求 CPU 内部产生一个立即数 4 并保存到 ebx 寄存器中。

```s
  int  $0x80
```
- `int` 指令称为软中断指令，可以用这条指令故意产生一个异常。
- `int` 指令中的立即数 `0x80` 是一个参数，在异常处理程序中要根据这个参数决定如何处理，在 Linux 内核中 `int 0x80` 这种异常称为系统调用（System Call）。
- eax 和 ebx 的值是传递给系统调用的两个参数。eax 的值是系统调用号，Linux 的各种系统调用都是由 `int $0x80` 指令引发的，内核需要通过 eax 判断用户要调哪个系统调用，`_exit` 的系统调用号是 1。ebx 的值是传给 `_exit` 的参数，表示退出状态。
- 大多数系统调用完成之后会返回用户空间继续执行后面的指令，而 `_exit` 系统调用比较特殊，它会中止掉当前进程，而不是返回用户空间继续执行。

x86 汇编的两种语法：
- intel 语法
- AT&T 语法

## x86 的寄存器

x86 的通用寄存器有 `eax  ebx  ecx  edx  edi  esi`。

x86 的特殊寄存器有 `ebp  esp  eip  eflags`。

## 第二个汇编程序

```s
data_items:
  .long 3, 67, 34, 222, 45, 75, 54, 34, 44, 33, 22, 11, 66, 0
```
- `.long` 指示声明一组数，每个数占32位，相当于 C 语言中的数组。除了 `.long` 之外，常用的数据声明还有：
	- `.byte` 也是声明一组数，每个数占8位
	- `.ascii` 例如 `.ascii "Hello world\0"` 声明 11 个数，取值为相应的 ASCII 码。

```s
_start:
  movl  $0, %edi
```
- 初始化 `edi`，指向数组的第0个元素。

比较指令通常和跳转指令配合使用。

## 寻址方式

内存寻址在指令中的通用格式：`ADDRESS_OR_OFFSET(%BASE_OR_OFFSET, %INDEX, MULTIPLIER)`

通用格式表示的最终地址为：`FINAL_ADDRESS = ADDRESS_OR_OFFSET + BASE_OR_OFFSET + MULTIPLIER * INDEX`

其中 `ADDRESS_OR_OFFSET` 和 `MULTIPLIER` 必须是常数，`BASE_OR_OFFSET` 和 `INDEX` 必须是寄存器。在有些寻址方式中会省略这 4 项中的某些项，相当于这些项是 0。

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

- 目标文件需要链接器做进一步处理，所以一定要有 Section Header Table
- 可执行文件需要加载器加载运行，所以一定要有 Program Header Table
- 共享库既要加载运行，又要在加载时做动态链接，所以既要有 Section Header Table，又要有 Program Header Table

### 目标文件

读取目标文件中的 ELF Header 和 Section Header Table。
```
$ readelf -a foo.o
```

打印目标文件的所有字节。
```
$ hexdump -C foo.o
```

反汇编
```
$ objdump -d foo.o
```
