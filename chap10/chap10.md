# gdb

调试的基本思想：分析现象 - 假设错误原因 - 产生新的现象去验证假设 这样一个循环。

## 单步执行和跟踪函数调用

编译时，如果要对代码进行调试，需要加上 `-g` 选项。该选项的作用是在可执行文件中加入源代码信息。

gdb 命令：
```
/* 查看帮助 */
(gdb) help

/* 查看具体项目的帮助 */
(gdb) help files

/* 列出源代码 */
(gdb) list 1

/* 重复上一条命令 */
(gdb) [ENTER]

/* 列出指定函数的代码 */
(gdb) list add_range

/* 退出 gdb 环境 */
(gdb) quit

/* 开始执行程序 */
(gdb) start

/* 执行下一条语句 */
(gdb) next

/* 执行下一条语句，如果有函数调用则进入到函数中 */
(gdb) step

/* 查看函数调用的栈帧 */
(gdb) backtrace

/* 查看当前函数的局部变量的值 */
(gdb) info locals

/* 选择指定的函数栈帧 */
(gdb) frame [STACK_NUM]

/* 让程序运行到当前函数返回为止 */
(gdb) finish

/* 打印表达式的值 */
(gdb) print [EXPRESSION]

/* 修改表达式的值 */
(gdb) set var [EXPRESSION]
```

## 断点

gdb 命令：
```
/* 跟踪显示指定变量的值 */
(gdb) display [VARIABLE_NAME]

/* 取消跟踪指定的变量 */
(gdb) undisplay [VARIABLE_NUM]

/* 设置断点 */
(gdb) break [LINE_NUM]

/* 连续运行直到到达断点 */
(gdb) continue

/* 查看已经设置的断点 */
(gdb) info breakpoints

/* 删除断点 */
(gdb) delete breakpoints [BREAKPOINT_NUM]

/* 禁用断点 */
(gdb) disable breakpoints [BREAKPOINT_NUM]

/* 激活断点 */
(gdb) enable breakpoints [BREAKPOINT_NUM]

/* 条件断点 */
(gdb) break ... if ...
```

## 观察点
