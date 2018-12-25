# 数据类型详解

## 整型

C 语言规定了 `signed` 和 `unsigned` 两个关键字。

C 标准的 Rationale 之一：优先考虑效率，而可移植性尚在其次。

`char` 型有符号还是无符号是 Implementation Defined。编译器可以定义 `char` 型是无符号的，也可以定义为有符号的。在该编译器所对应的体系结构上哪种实现效率高就可以采用哪种实现，x86 平台的 gcc 定义 `char` 型是有符号的。

### Implementation Defined、Unspecified 和 Undefined

在 C 标准中没有明确规定的地方会用 Implementation Defined、Unspecified 和 Undefined 来表述。

- Implementation Defined：C 语言要求编译器必须对此做出明确的规定，并写在编译器的文档中。

- Unspecified：C 语言没有明确规定编译器按哪种方式来处理，由编译器自己决定。

- Undefined：C 语言没有明确规定，编译器可能也没有规定。比如数组访问越界就是 Undefined。

C 标准明确规定，除了 `char` 型以外其他类型如果没有明示 `unsigned` 或 `signed` 关键字则表示 `signed`。

在 C 语言中，整数常量有十进制的、八进制和十六进制的。八进制整数常量以 0 开头，十六进制的整数常量以 0x 开头。整数常量还可以在末尾加 u 表示 "unsigned"，加 l 表示 "long"，加 ll 表示 "long long"。但这些后缀和 `unsigned`、`long`、`long long` 关键字不是一一对应的。

整数类型：
```
Type		Signed			Unsigned		Abbr
-------------------------------------------------------------------------
char		signed char		unsigned char
short int	signed short int	unsigned short int	short
int		signed int		unsigned int
long int	signed long int		unsigned long int	long
long long int	signed long long int	unsigned long long int	long long
```

## 浮点型

浮点类型：
- float
- double
- long double

浮点数的后缀和类型之间的对应关系比较简单：
- 没有后缀是 double 型
- 有 f 后缀的是 float 型
- 有 l 后缀的是 long double 型

## 类型转换

### Integer Promotion

在一个表达式中，凡是可以使用 int 或 unsigned int 类型做右值的地方也可以都使用有符号或无符号的 char 型、short 型和 Bit-field。
- 如果原始类型的取值范围都能用 int 型表示，则其类型被提升为 int。
- 如果原始类型的取值范围用 int 型表示不了，则提升为 unsigned int。

适用的情况：
1. 如果一个函数的形参类型未知，或者是函数的参数列表中有...，那么调用函数时要对相应的实参做 Integer Promotion。
2. 算术运算中的类型转换。有符号或无符号的 char 型、short 型和 Bit-field 在做算术运算之前要先做 Integer Promotion，然后才能参与计算。

### Usual Arithmetic Conversion

两个算术类型的操作数做算术运算，如果两边操作数的类型不同，编译器会自动做类型转换，使两边类型相同之后才做运算，这称为 Usual Arithmetic Conversion。

### 由赋值产生的类型转换

如果赋值或初始化时等号两边的类型不相同，则编译器会把等号右边的类型转换成等号左边的类型再做赋值。这个适用于函数传递参数和返回函数的返回值。

### 强制类型转换

以上三种情况统称为隐式类型转换（Implicit Conversion）。程序员可以通过使用类型转换运算符（Cast Operator）自己规定某个表达式要转换成何种类型。这称为显示类型转换（Explicit Conversion）或强制类型转换（Type Cast）。

注意：操作数必须是标量类型，转换之后的类型必须是标量类型或者是 void 型。
