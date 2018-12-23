# 循环语句

## while 语句

```c
while (A) B
```
A：控制表达式
B：子语句（可以是若干条语句组成的语句块）

- 累加器（Accumulator）
- 循环变量（Loop Variable）

- 函数式编程（Functional Programming）
- 命令式编程（Imperative Programming）

给变量多次赋值时要格外小心，在代码中多次读写同一个变量应该以一种一致的方式进行。

## do while 语句

```c
do A while (B)
```
A：语句（可以是由语句组成的语句块）
B：控制表达式

while 语句先测试控制表达式再执行循环体。

do while 语句先执行循环体再测试控制表达式的值。

## for 语句

```c
for (cond1; cond2; cond3) {
...
}
```
cond1, cond2, cond3：控制表达式1，2，3

在不考虑循环体内有 continue 语句的情况下，for 循环等价于下面的 while 循环。
```c
cond1;
while (cond2) {
...
cond3;
}
```

死循环的写法：
```c
/* Type A */
while (1) { ... }

/* Type B */
for (;1;) { ... }

/* Type C */
for (;;) { ... }
```

在 C99 中新增了 for 循环的语法，在控制表达式1中可以有变量的定义。如下所示：
```c
for (int i = 0; i < n; i++) { ... }
```
上例的变量 i 只是 for 循环中的局部变量，循环结束后就不能使用变量 i 了。

自增、自减：
```c
i++; // 表达式的值为 i，Side Effect i 的值增加了 1
i--; // 表达式的值为 i，Side Effect i 的值减少了 1
++i; // 表达式的值为 i + 1，Side Effect i 的值增加了 1
--i; // 表达式的值为 i - 1，Side Effect i 的值减少了 1
```

如何理解`a+++++b`：编译的过程分为词法解析和语法解析两个阶段，在词法解析阶段，编译器总是从前到后找 最长的合法 Token。这个表达式从前到后解析，a ++ ++ + b，因为 ++ 运算符要求操作数能做左值，a 能做左值没问题，a++ 只能做右值，最后编译器报错。

## break continue 语句

break：
1. 可以从 switch 语句中跳出
2. 可以从循环体中跳出

continue：
1. 对于 while、do while 语句，执行完 continue 语句后测试控制表达式，如果值为真则继续执行下一次循环
2. 对于 for，执行完 continue 语句之后，先执行控制表达式3，然后测试控制表达式2，如果值为真则继续执行下一次循环。

## 嵌套循环

break 只能跳出最内层的循环或 switch，continue 也只能跳出最内层的循环。

## goto 语句和标号

goto 语句只能跳转到同一个函数的指定标号处。

```c
for (A) {
  for (B) {
    if (C) {
      goto error;
    }
  }
}

error:
...
```

goto 的常用场合：一个函数中的任何地方出现了错误条件都可以立即跳转到函数末尾做出错处理（释放之前分配的资源、恢复之前改动的全局变量等）。

标号的命名要符合标识符命名规则。
