# 4.26 周练小结

## A - A 与劳动节

首先最简单的思路就是暴力枚举，枚举点 $p$ 再计算距离求和维护最小值。

显然会超时，那么如何优化呢？一般来说，多重循环的算法可以考虑优化某一层，用速度更快的对数级算法代替之，算法的整体速度便可加快。这里分层来考虑：

- 第 1 层——枚举点 $p$：是否存在更快捷的寻找点 $p$ 的方法或公式？如果把这个问题降至一维——数轴上的点，那么答案显然是取最中间的点（或偶数点的情况下，最中间线段上的任意点）。可惜此问题在三维甚至二维上都没有特别简便的解法。
- 第 2 层——计算距离：计算所有点到给定点 $p$ 的距离一定要枚举所有点吗？答案是否定的。由于题目中使用的是曼哈顿距离——三维坐标差的绝对值之和，我们可以考虑将三维分开计算。首先看 $x$ 轴坐标，根据绝对值的性质：

<!-- prettier-ignore-start -->
$$ \sum^{n}_{i=1}|x_i-x_p| = \sum_{x_i \leq x_p}x_p-x_i + \sum_{x_i>x_p}x_i-x_p $$
<!-- prettier-ignore-end -->

假设有 $d$ 个点满足 $x_i \leq x_p$，即按 $x$ 坐标升序排序，$p$ 点排在第 $d$ 位，那么上式可以写成：

<!-- prettier-ignore-start -->
$$ d \times x_p-\sum_{x_i \leq x_p}x_i \ + \sum_{x_i>x_p}x_i - x_p \times (n-d) $$
<!-- prettier-ignore-end -->

再整理一下：

<!-- prettier-ignore-start -->
$$ x_p \times (2d-n) +\sum^{n}_{i=1}x_i - 2 \sum^{d}_{i=1}x_i $$
<!-- prettier-ignore-end -->

其中两个区段求和是非常简单的，只需要用前缀和预处理就可以了。至于求出 $d$ 的具体值，可以用`upper_bound`等二分函数。最后将 $x,y,z$ 三个维度分别处理相加即可得到距离之和。二分查找和快排的时间复杂度相近，都是对数级的，因此内层循环可以被很好地优化。

```c++
sort(x + 1, x + 1 + n);
sort(y + 1, y + 1 + n);
sort(z + 1, z + 1 + n);
for (int i = 1; i <= n; i++)    // 求前缀和
{
    sumx[i] = sumx[i - 1] + x[i];
    sumy[i] = sumy[i - 1] + y[i];
    sumz[i] = sumz[i - 1] + z[i];
}
int ansP = 0;
long long minDis = INF;
for (int p = 1; p <= n; p++)    // 枚举点p
{
    long long dis = 0;
    Lab &l = lab[p];

    int dx = upper_bound(x + 1, x + 1 + n, l.x) - x - 2; // x[dx]及以前的元素都小于等于l.x
    dis += l.x * (2 * dx - n) + sumx[n] - 2 * sumx[dx];

    int dy = upper_bound(y + 1, y + 1 + n, l.y) - y - 2;
    dis += l.y * (2 * dy - n) + sumy[n] - 2 * sumy[dy];

    int dz = upper_bound(z + 1, z + 1 + n, l.z) - z - 2;
    dis += l.z * (2 * dz - n) + sumz[n] - 2 * sumz[dz];

    if (dis < minDis)
    {
        minDis = dis;
        ansP = p;
    }
}
printf("%d %lld\n", ansP, minDis);
```

## B - 射击

首先对于坐标范围不大的数据，可以直接用二维数组标记模拟。可惜空间和时间浪费都很严重，那么可以想办法将二维的点转化为线性的序列，再来进行查找。

很自然会想到将点先按 $x$ 坐标排序，相同时再按 $y$ 坐标排序，这样关键问题就变为如何查找。设查找的基准点为 $b$，那么查找的任务便是要找到一个点 $s$ 使得 $s_x \geq b_x+1$ 且 $s_y \geq b_y+1$ 且 $s$ 尽量排在序列的前面。可以用 `lower_bound` 方便快捷地找到 $x$ 坐标的分割点，但对于 $y$ 轴坐标满足条件的点，还需要进行迭代查找。具体方法是：在当前的 $x$ 坐标相同的一些点的区间里查找目标 $y$ 坐标的 `lower_bound`，如果找到了那么这个点就是，找不到就增大 $x$ 坐标进入下一个区间。

这种方法要求点序列始终是有序的，并且需要支持删除操作。STL 的 `set` 刚好可以满足这些需求，我们只需要使用内置的 `pair` 类型即可自动支持二维优先级排序，但个人更喜欢定义一个重载运算符的结构体：

```c++
struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y)
    {
    }
    const bool operator<(const Point &a) const
    {
        return x == a.x ? y < a.y : x < a.x;
    }
};

set<Point> points;
typedef set<Point>::iterator iter;  // 定义迭代器类型缩写让代码变简洁

// 这里直接以函数的形式实现三种操作，实际做题在main函数里套输入接口就可以了
void add(Point a)   // add和remove操作都可以直接调用STL
{
    points.insert(a);
}
void remove(Point a)
{
    points.erase(a);
}
Point find(Point a)
{
    iter i;
    a.x++;  // 别忘了要+1
    for (;;)    // 无限循环，等价于while(true)
    {
        iter p = points.lower_bound(Point(a.x, a.y + 1));   // 寻找“最靠左下方”的点，但此处p的横纵坐标之一可能会与原始的a点相等
        if (p == points.end())  // 所有点都在a点左边和下面
            return Point(-1, -1);   // 这个函数返回点(-1,-1)表示未找到

        iter cur = p;
        i = points.lower_bound(Point(cur->x, a.y + 1)); // 增大x迭代查找，同上
        if (i == points.end())
            return Point(-1, -1);
        cur = i;
        if (cur->y >= a.y + 1)  // 如果当前点的y轴坐标满足条件就返回
            return *cur;
        a.x = cur->x;   // 否则修改当前点的x坐标留到下一次尝试
    }
}
```

## C - 树上异或路径

🤔🤔🤔🤔🤔🤔

```c++
// Insert Code Here
```
