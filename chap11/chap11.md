# 算法的概念

本章推荐的书目：
- Programming Pearls
- Introduction to Algorithms

## 排序与查找

算法（Algorithm）是将一组输入转化成一组输出的一系列计算步骤，其中每个步骤必须能在有限时间内完成。

算法是用来解决一类计算问题的，而不是一个。

## 插入排序

```
9, 5, 2, 4, 7
5, 9, 2, 4, 7
2, 5, 9, 4, 7
2, 4, 5, 9, 7
2, 4, 5, 9, 7
```

插入排序类似于将扑克牌从小到大的排序。

每次插入牌时，之前的牌的顺序确保是正确的。

## 算法的时间复杂度

数量级从小到大的顺序：O(lg n) - O(sqrt(n)) - O(n) - O(n*lg n) - O(n^2) - O(n^3) - O(2^n) - O(n!)

⊙ 的含义和“等于”类似。

○ 的含义和“小于等于”类似。

## 归并排序

插入排序算法采取增量式（Incremental）的策略解决问题。

归并排序算法采取分而治之（Divide-and-Conquer）的策略。

## 线性查找

在一个字符串中找某一个字符，找到了返回其位置，未找到返回 -1。

k-th Order Statistic

## 折半查找

从一组排好序的序列中找出某个元素的位置，则有更快的算法。

DbC（Design by Contract）：
- Precondition
- Maintenance
- Postcondiction

用简单的、不容易出错的代码去测试复杂的、容易出错的代码。

在代码中适当的地方使用断言（Assertion）可以有效地帮助我们测试代码。

使用 `#define NDEBUG` 可以禁用 `assert.h` 中的 `assert` 宏定义，也可以不必修改源文件，在编译命令行加上选项 `-NDEBUG` 就相当于在源文件开头定义了 `NDEBUG` 宏。
