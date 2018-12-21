# 结构体

## 复合类型和结构体

- 基本类型（Primitive Type）：最基本的、不可再分的数据类型（例如整型、浮点型）
- 复合类型（Compound Type）：根据语法规则由基本类型组合而成的类型（例如字符串由很多字符组成）

学习一门新的编程语言需要注意的三个方面：
1. 这门语言提供了哪些 Primitive，比如基本类型，比如基本运算符，表达式和语句。
2. 这门语言提供了哪些组合规则，比如基本类型如何组合成复合类型，比如简单的表达式和语句如何组成复杂的表达式和语句。
3. 这门语言提供了哪些抽象机制，包括数据抽象和过程抽象。

```c
/* 定义结构体 */
struct foo_struct {
	int x;
	double y;
	char z;
};
```
在 C 语言中上述的 `foo_struct` 称为 Tag。

`struct foo_struct { ... }` 可以看作一种类型名，类似于 int，只不过是复合类型。

使用复合类型定义变量可以使用以下的方式。
```c
/* Type A */
struct foo_struct {
	int x;
	int y;
} x, y;

/* Type B */
struct foo_struct x, y;
```
类型定义也是一种声明，声明都要以;号结尾。

只要定义了 Tag，以后可以直接用`struct foo_struct`来代替类型名。

访问结构体成员，可以用.运算符来访问。

在定义时初始化结构体：
```c
struct foo_struct x = { 3, 4 };
```
- 如果 Initializer 中的数据比结构体的成员多，则编译器报错。
- 如果只是末尾多个逗号不算错。
- 如果 Initializer 中的数据比结构体的成员少，未指定的成员将用 0 来初始化。

C89：只允许使用常量表达式来初始化结构体变量。
C99：允许当结构体变量为局部变量时，使用另一个变量来初始化结构体成员。
C99：Designated Initializer 用于初始化稀疏结构体和数组。

结构体变量之间可以相互赋值和初始化（被初始化的结构体变量必须是局部变量），也可以当作函数的参数和返回值来传递。

由.运算符组成的表达式能不能做左值取决于.运算符左边的表达式能不能做左值。
- x.something 可以
- foo(x, x).something 不可以

## 数据抽象

组合使得系统可以任意复杂，而抽象使得系统的复杂性是可以控制的，任何改动都只局限在某一层，而不会波及整个系统。

## 数据类型标志

```c
enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a;
	double b;
};
```
- enum 关键字的作用和 struct 关键字类似，把 `coordinate_type` 这个标识符定义为 Tag。
- `struct complex_struct` 表示一个结构体类型。
- `enum coordinate_type` 表示一个枚举（Enumeration）类型。
- 枚举类型的成员是常量，它们的值由编译器自动分配。如上例中的 RECTANGULAR 就表示常量 0，POLAR 表示常量 1。
- 如果不希望从 0 开始分配，可以以下方式：
```c
enum coordinate_type { RECTANGULAR = 1, POLAR }; /* RECTANGULAR 表示常量 1，POLAR 表示常量 2 */
```
- 结构体成员名和变量名不在同一个命名空间中，但是枚举成员名和变量名在同一个命名空间中。

## 嵌套结构体

结构体也是一种递归定义，嵌套定义如下所示：
```c
struct segment {
	struct complex_struct start;
	struct complex_struct end;
};
```

初始化嵌套结构体的方式：
```c
/* 嵌套初始化 */
struct segment s = {{ 1.0, 2.0 }, { 3.0, 4.0 }};

/* 平坦初始化 Flat */
struct segment s = { 1.0, 2.0, 3.0, 4.0 };

/* C99 Memberwise Initialization*/
struct segment s = { .start.x = 1.0, .end.y = 2.0 };
```

访问嵌套结构体的方式：
```c
s.start.t = RECTANGULAR;
s.end.b = 2.3;
```
