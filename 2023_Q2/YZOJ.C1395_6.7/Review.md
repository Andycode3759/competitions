# 6.7 周练小结

## A - 同花顺

### 小分点

- 对于只有一种或两种牌的情况：如果所有牌都相同，那答案就是 $n-1$；如果只有两种牌，看这两种牌的花色是否相同、点数之差是否小于 $n$，如果是那答案就是 $n-2$，否则是 $n-1$。

### 赛时分析

一开始的做法是：将所有牌先按花色、再按点数排序，然后找已存在的最长的同花顺。设其长度为 $len$，那答案就是 $n-len$。

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

但是这个解法是错误的，得出的答案会大于（或等于）实际答案。为什么？因为一副整体很“散”、但局部都满足同花顺的牌，或者是一幅点数递增但间隔很大的牌，只需要改少量的牌就可以凑成完整的同花顺。比如下面这幅：

```
1 1
1 3
1 5
1 7
1 9
```

正确答案是 $2$，用上面的做法得到的答案是 $4$（因为原始牌不存在一套两张牌及以上的连续的同花顺）。

### 正解

<details>
<summary>展开</summary>

从上面的解法出发，我们不能仅仅拘泥于连续的牌组，而要考虑所有可能的牌的搭配。那么不妨把思路想暴力一点，枚举所有的牌的子集，判断这一组牌是否存在于最后的同花顺中。如果一组牌存在于最后的同花顺中，那么这组牌一定满足这些条件：

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

</details>

## B - 华小科的函数

### 小分点

- 对于 $M \leq 8, M \leq 8$ 的情况：直接模拟，答案正确性很容易保证。
- 对于 $N=1$ 的情况：只有 $M$ 本身才能一次操作得到 $1$，故答案为 $1$。
- 对于 $M=2$ 的情况：不会分析可以用 BFS 打表找规律。考虑从 $1$ 出发，每次经过乘 2 或减 1 两种操作之一，$N$ 次以内可以到达哪些数。

<details>
<summary>打表代码（展开）</summary>
```c++
const int MAXN = 10;

struct Node
{
    Node(int _s, long long _x) : step(_s), x(_x) { }
    int step;
    long long x;
};
queue<Node> Q;  // BFS 队列
map<long long, bool> M; // 用于判重

for (int maxStep = 1; maxStep <= MAXN; maxStep++)
{
    long long res = 0;
    while (!Q.empty())
        Q.pop();
    M.clear();
    Q.push(Node(0, 1));
    M[1] = true;
    while (!Q.empty())
    {
        Node n = Q.front();
        Q.pop();
        if (n.step == maxStep)
        {
            res++;
            continue;
        }
        long long n1 = n.x - 1, n2 = n.x * 2;
        if (n.x % 2 == 0 && !M[n1] && n1 > 1)   // 只有奇数才能通过+1得到偶数，即+1操作不能连续出现2次
        {
            Q.push(Node(n.step + 1, n1));
            M[n1] = true;
        }
        if (!M[n2] && n2 > 1)
        {
            Q.push(Node(n.step + 1, n2));
            M[n2] = true;
        }
    }
    printf("n=%d ans=%lld\n", maxStep, res);
}
```
</details>

运行结果如下：
```c++
n=1 ans=1
n=2 ans=1
n=3 ans=2
n=4 ans=3
n=5 ans=5
n=6 ans=8
n=7 ans=13
n=8 ans=21
n=9 ans=34
n=10 ans=55
```

不难发现这是一个斐波那契数列，对于这种特殊情况便可直接计算解决。

- 对于 $N<M$ 的情况：首先对于所有计算在答案内的数 $a$ 都会满足 $a \leq M^N$，因为更大的数一定要通过比 $N$ 次更多的步数才能得到 $1$。反过来，从 $1$ 出发经过 $N$ 次逆操作，在 $N<M$ 的情况下，得到的数一定会小于 $M^N$。此时得到的所有数都满足题意，而每个中间数都有 2 条路径（乘 2 或减 1），因此答案为 $2^{N-1}$。

### 赛时分析

本来第一类小分点的分是很好拿下的，但考后修复数据重判后却只得了 5 分。为什么？

```c++
int mx = pow(m, n);
int res = 0;
for (int i = 1; i <= mx; i++)
{
    int a = i;
    for (int j = 1; j <= n; j++)
    {
        if (a % m == 0)
            a /= m;
        else
            a++;
    }
    if (a == 1)
        res++;
    if (res >= MOD)
        res -= MOD;
}
printf("%d\n", res);
```

事实上并不是任何数严格经过 $N$ 次复合操作后得到 $1$ 都可以计算到答案中。因为有些数经过小于 $N$ 次操作后就已经得到了 $1$，按照题意，这些数是不属于答案的。因此需要在枚举时用标记将这些情况排除。

```c++
int mx = pow(m, n);
int res = 0;
for (int i = 1; i <= mx; i++)
{
    int a = i;
    bool ok = true;
    for (int j = 1; j <= n; j++)
    {
        if (a == 1)
        {
            ok = false;
            break;
        }
        if (a % m == 0)
            a /= m;
        else
            a++;
    }
    if (a == 1 && ok)
        res++;
    if (res >= MOD)
        res -= MOD;
}
printf("%d\n", res);
```

### 正解

<details>
<summary>展开</summary>

</details>

## C - 最小生成树

### 小分点

- 对于 $p=1$ 或 $a_i=1$ 的情况：两两点之间的路径最小边权都为 $1$，故答案为 $n-1$。
- 对于 $n \leq 200$ 的情况：打暴力，直接枚举所有区间，遍历求出其最小值和 gcd，满足条件就连边，最后再用最小生成树跑一遍。
- 对于 $n \leq 2000$ 的情况：也是暴力做法，但求最小值和 gcd 可以用 ST 表加速。

### 赛时分析

暴力代码的思路比较容易想到，但代码量还是稍微大一些，加上考试的时候有点忘了 Kruskal 和 ST 表怎么写，没有自信下手。此处反映出学了后面忘了前面的问题，今后应该要注意将前面学过的知识点进行复习巩固、查漏补缺，避免上赛场时再次出现类似的问题。

### 正解

<details>
<summary>展开</summary>

~~既然题目名字叫最小生成树，那么首先排除最小生成树的做法~~

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

</details>

## D - 野猪骑士

### 小分点

- 对于 $k=1$ 的情况：直接把所有的房屋分配给唯一的一名骑士，即用矩形将所有点都包括起来；
- 对于 $k=n$ 的情况：每个骑士分配一个房屋，即对于每一个点都有一个小矩形与其对应；
- 对于点存在单调性质的情况：
- 对于规模较小的一般数据（$n \leq 12,k \leq 12$）：暴力枚举，先枚举房屋编号 $[1,n]$ 的全排列，再对每一个排列枚举骑士的房屋分配方式，对于每一种情况求解取最小值。实现时套两层 DFS 即可。

### 正解

<details>
<summary>展开</summary>


</details>
