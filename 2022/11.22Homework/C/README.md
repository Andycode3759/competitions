# C - 函数

>内存限制：64 MB
>
>时间限制：1.000 S

## 题目描述

数学课上老师定义了一个函数$f(n)={1\over2}+{1\over3}+...+{1\over{n}}+{1\over{n+1}}$，现在给出一个浮点数$c$，求使得$f(n)>=c$的最小整数$n$。

## 输入
多组测试数据，每组包含一个浮点数$c$。特别地，$c=0.0$表示结束。

## 输出
对于每组测试数据，输出一个整数$n$。

## 样例输入
```
1.00
3.71
0.04
5.19
0.00
```

## 样例输出
```
3
61
1
273
```

## 数据规模
对于$100\char37$的数据满足：$c<=5.2$，测试数据不超过10组。