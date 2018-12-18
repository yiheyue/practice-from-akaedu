# 简单函数

## 数学函数

`log(1.0)`，在 C 语言中：
- 1.0 是参数（Argument）
- log 是函数（Function）
- log(1.0) 是函数调用（Function Call）

函数调用是一种表达式，`log(1.0)`由两个操作数和一个运算符组成。
- 运算符 () 函数调用运算符
- 操作数 log 是一个函数名（Function Designator），类型是一种函数类型（Function Type）
- 操作数 1.0，类型是 double

`log(1.0)`这个表达式的值为运算结果，类型为 double。

在 C 中，函数调用表达式的值称为函数的返回值（Return Value）。

C 语言中的函数可以有副作用（Side Effect）。

改变计算机存储单元中的数据 或者 输入输出 的操作都算作副作用。

C 标准主要由两个部分组成：
1. 描述 C 的语法
2. 描述 C 的标准库

## 自定义函数

函数定义 -> 返回值类型  函数名(参数列表)  函数体

$? 是 shell 的一个特殊变量，表示上一次命令的退出状态。

main 函数最标准的形式应写成 `int main(int argc, char *argv[])`。

void 类型的值不能参与运算。

- 函数原型（Prototype） - `void newline(void)`
- 函数声明 - `void newline(void);`
- 函数定义 - `void newline(void) { printf("\n"); }`

函数的隐式声明（Implicit Declaration）
- 隐式声明的函数返回值都是 int
- 隐式声明的函数参数列表为 void

## 实参 形参

实参 - Argument

形参 - Parameter

形参相当于函数中定义的变量，调用函数传递参数的过程相当于定义形参并用实参的值来初始化。
