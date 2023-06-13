# 6.7 周练小结

## A - 同花顺

一开始的做法：将所有牌先按花色、再按点数排序，然后找已存在的最长的同花顺。设其长度为 $len$，那答案就是 $n-len$。

```c++
int lastC = -1, lastV = -1; // 上一张牌的花色与点数
int combo = 0, bst = 0; // 当前同花顺的长度和最长的长度
for(int i = 1; i <= n; i++)
{
    if (lastC == -1 || (c[i] == lastC && v[i] == lastV + 1))    // 作为同花顺的开头，或者能和上一张牌构成同花顺
    {
        combo++;
        lastC = c[i], lastV = v[i];
    }
    else    // 当前的这幅同花顺被打断
    {
        bst = max(combo, bst);
        combo = 0;
        lastC = -1;
    }
}
bst = max(combo, bst);  // 最后一段需要收尾
printf("%d\n", n - bst);
```

这个解法是错误的，得出的答案会大于（或等于）实际答案。为什么？因为一副整体很“散”、但局部都满足同花顺的牌，或者是一幅点数递增但间隔很大的牌，只需要改少量的牌就可以凑成完整的同花顺。比如下面这幅：

```
1 1
1 3
1 5
1 7
1 9
```

正确答案是 $2$，用上面的做法得到的答案是 $4$（因为原始牌不存在一套两张牌及以上的连续的同花顺）。

因此不能仅仅拘泥于连续的牌组，而要考虑所有可能的牌的搭配。那么不妨把思路想暴力一点，枚举所有的牌的子集，判断这一组牌是否存在于最后的同花顺中。如果一组牌存在于最后的同花顺中，那么这组牌一定满足这些条件：

- 所有牌的花色相同；
- **点数最大牌的点数与点数最小牌的点数之差要小于最后的同花顺长度。**

如果发现了这一点，那么枚举也可以简化：不需要枚举全部子集，只需要将牌按花色点数排序后，对于同花色的子序列里枚举所有连续的区间就可以了。如果要拿满分还有其他需要注意的细节，比如牌组需要先**去重**、区间长度为 $1$ 的区间也要考虑等。

```c++
struct Card
{
    int c, v; // c花色,v点数

    const bool operator<(const Card &a) const   // 用于排序
    {
        return (c == a.c) ? v < a.v : c < a.c;
    }
    const bool operator==(const Card &a) const  // 用于去重
    {
        return c == a.c && v == a.v;
    }
};
Card cards[MAXN];
vector<int> uc; // 所有不同花色的子序列之间的切分点位置

scanf("%d", &n);
for (int i = 1; i <= n; i++)
{
    scanf("%d%d", &cards[i].c, &cards[i].v);
}
// 排序并去重
sort(cards + 1, cards + 1 + n);
int cc = unique(cards + 1, cards + 1 + n) - cards - 1;
// 找出所有不同的花色。每一种花色对应排序后的一段子区间，第i种花色对应的区间末尾的后一个位置为uc[i]
int lc = -1;
for (int i = 1; i <= cc; i++)
{
    if (cards[i].c != lc)
    {
        uc.push_back(i);
        lc = cards[i].c;
    }
}
uc.push_back(cc + 1);   // 最后一个区间需要收个尾

int ans = 0;    // 能够存在于最后的同花顺的子序列中最长的长度
for (int c = 0; c < uc.size(); c++)
{
    for (int l = uc[c]; l < uc[c + 1]; l++) // 直接枚举子序列的左右端点
    {
        for (int r = l; r < uc[c + 1]; r++)
        {
            if (cards[r].v - cards[l].v <= n - 1)   // 满足条件就更新答案
            {
                ans = max(ans, r - l + 1);
            }
        }
    }
}
printf("%d\n", n - ans);    // 输出的是需要改的牌的数量，所以是n-ans
```

## B - 华小科的函数

对于 $n \leq 8, m \leq 8$ 的情况：直接模拟，答案正确性很容易保证。

对于 $m=2$ 的情况：

## C - 最小生成树

~~既然题目名字叫最小生成树，那么首先排除最小生成树的做法。~~

的确，这个题目的正解和图论没有半毛钱关系，甚至也不需要预处理区间最小/区间 gcd 等数据。

首先观察这个条件：$gcd_{i \leq k \leq j}\{a_k\}=min_{i \leq k \leq j}\{a_k\}$，即区间最小值等于区间最大公约数，其实这个条件等价于**区间内的最小值是区间里所有数的的因数**，即 $\forall k \in [i,j],\ min_{i \leq k \leq j}\{a_k\}\ |\ a_k$。

这样一来，如果一段区间 $[l,r]$ 内的点满足这个条件，那么一定可以从 $[l,r]$ 中任选两个不同点连接一条边，其权值为 $min_{l \leq k \leq r}\{a_k\}$。因此可以把这一段区间内连续的两点间的边（原权值为 $p$）全都替换成上述权值的边。既然要求的是最短路，那么对于区间最小值大于等于 $p$ 的区间就没有必要搞上面这一套。至此也就有了大概的思路：

1. 找到 $a_i$ 最小的还没有被标记过的点 $i$，如果 $a_i \geq p$，那么算法结束，此时一定没有更优的答案了；
2. 从 $i$ 点出发，向左右扩张出一段区间，满足区间内所有的数都是 $a_i$ 的倍数；
3. 计算出区间的长度和替换全部边后可以节省的费用；
4. 给区间内所有点打个标记，避免重复计算；

最后的最后，**记得开 `long long`**。

```c++
struct Node // 把值和下标捆绑，方便排序后找
{
    int val, idx;

    const bool operator<(const Node &a) const
    {
        return val < a.val;
    }
};

int arr[MAXN];
Node nodes[MAXN];
bool flag[MAXN];
int n, p;

scanf("%d%d", &n, &p);
for (int i = 1; i <= n; i++)
{
    scanf("%d", arr + i);
    nodes[i].val = arr[i];
    nodes[i].idx = i;
}
sort(nodes + 1, nodes + 1 + n);

long long contribute = 0;   // 总共可以节省的费用
for (int i = 1; i <= n; i++)    // 从值最小的点开始找
{
    int x = nodes[i].val, xi = nodes[i].idx;
    if (x >= p) // 此时一定没有更优解
        break;
    if (flag[xi])   // 已经找过的点不用重复计算
        continue;

    int l = xi, r = xi;
    // 左右扩张区间
    for (; l >= 1 && arr[l] % x == 0; l--)
        flag[l] = true;
    for (; r <= n && arr[r] % x == 0; r++)
        flag[r] = true;
    // 此时的区间是开区间，需要首尾再缩一下变成闭区间
    flag[l++] = false;
    flag[r--] = false;
    // 计算能节省的费用
    contribute += 1LL * (r - l) * (p - x);
}

printf("%lld\n", 1LL * p * (n - 1) - contribute);
return 0;
```

顺便一提，比赛时如果想不到上面的解法，观察到数据范围有 $p \leq 1$ 和 $a_i \leq 1$ 两种特殊情况，对于它们来说答案就是 $n-1$（任意两个相邻点之间的边权都是 $1$）。

_比赛时不要看到关键词就条件反射套模板，而要认真观察、分析条件，简化模型才能方便做题。_

## D - 野猪骑士
