# 3.11 考试总结

> Context: Tingtime（教练）出差去了，让我们自己在机房考试...

## A - 数学偶像（计蒜客信息学 11 月编程新手赛）

按理来说应该是送分的数论题，用暴力也能拿到 90 分，但第一次尝试后只拿了 20 分就暂时放弃点开了 B 题。推测拿 20 分的原因在于 connect 函数除了问题：

```c++
// TLE -80%
#include <bits/stdc++.h>
using namespace std;

int log10of[1005];
int pow10of[5];

int connect(int a, int b)
{

    return a * pow10of[log10of[a]] + b;

}

int main()
{

    log10of[0] = 0;
    for (int i = 1; i <= 1000; i++)
    {
        log10of[i] = log10of[i / 10] + 1;
        // printf("log10of[%d]=%d\n", i, log10of[i]);
    }
    pow10of[0] = 1;
    for (int i = 1; i <= 4; i++)
    {
        pow10of[i] = pow10of[i - 1] * 10;
        // printf("pow10of[%d]=%d\n", i, pow10of[i]);
    }

    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (connect(i, j) == i * j + i + j)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;

}

```

当时执着于用对数和指数预处理来优化时间，但事实是**无论有没有预处理，这种思路的算法最多也只能拿 90 分，反而容易弄巧成拙**，因此更稳妥的方法是直接用 if-else 来判断$a$的位数：

```c++
for (int i = 1; i <= a; i++)
{
    for (int j = 1; j <= b; j++)
    {
        int f;
        if (j >= 1000)
            f = i * 10000 + j;
        else if (j >= 100)
            f = i * 1000 + j;
        else if (j >= 10)
            f = i * 100 + j;
        else
            f = i * 10 + j;
        if (f == i * j + i + j)
            ans++;
    }
}
```

最后正解其实也不难（好在做完 C 题后终于想到了），只需要数学稍微推导即可得出$10^{\lfloor logj \rfloor +1}=j$的等价关系。（[代码已提交在 G 站](https://github.com/Andycode3759/competitions/blob/main/2023/3.11YZOJ.C1369/A/A.cpp)）

> 本次考试的第一题如果没有在 10 分钟（或者 5 分钟）以内，做到 90 分，这个考试就一定是失败的。
> 我们的 3 位同学，过了半小时依然还没先提交 90 分的代码。在考场来说，**考试策略一定是不正确的**。
>
> —— Tingtime

## B - 蒜头君寻宝（计蒜客信息学 11 月编程新手赛）

看到题目第一反应是线段树，但由于忘记了线段树该怎么写导致心里很慌，花了半个小时执着于线段树的实现，后面又推倒重来换成分块，到最后代码都没写完。

实际上本题骗到 30 分是很容易的，不难发现**只有在向右移动的时候才有可能捡起宝藏**（因为起点在最左边），**因此只要记录位置和已经经过的最右边端点即可**（可以证明，数列上一定存在一个点$p$，区间$[0, p]$全部为空，$(p, n]$全部为未捡起的宝藏，且$p$点位置要么不动要么右移）。拿 30 分的做法即纯模拟，暴力累加，只需要用前缀和优化一下就能满分。**甚至不用线段树。**

```c++
// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

long long latestProfit = 0;
int pos = 0;
int cut = 1; // 最靠左边的有宝藏的位置

int treasure[MAXN];
long long treasureSum[MAXN]; // 前缀和

int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", treasure + i);
        treasureSum[i] = treasureSum[i - 1] + treasure[i];
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1: // move
            int dis, dir;
            scanf("%d%d", &dis, &dir);
            if (dir == 1) // left
            {
                latestProfit = 0;
                pos -= dis;
                pos = max(pos, 1);
            }
            if (dir == 2) // right
            {
                int oldPos = pos;
                pos += dis;
                pos = min(pos, n);
                if (pos < cut)
                {
                    latestProfit = 0;
                    break;
                }
                int l = max(oldPos, cut);
                int r = pos;
                latestProfit = treasureSum[r] - treasureSum[l - 1];
                cut = max(cut, pos + 1);
            }
            break;
        case 2: // query latestProfit
            printf("%lld\n", latestProfit);
            break;
        case 3: // query pos
            printf("%d\n", pos);
            break;
        }
    }
    return 0;

}

```

> 第 2 题也是如此，做的情况也不好。纯粹模拟拿下 30 分，**应该是在 10 分钟以内做完的事情。**（这样，在大概 20 分钟以内，得分就至少 120 分）而 Andy 在结束前 8 分钟提交的代码还依然是 0 分，这就非常说不过去！！
>
> —— Tingtime
>
> （注：其他两位队友本题 AC）

## C - 第七中学

和上楼梯问题的思路很相似，只要判断带炸弹的台阶将其答案设为 0，以及输出时的细节处理即可。~~（好不容易拿了个一血嘿嘿嘿）~~

代码放在[ G 站](https://github.com/Andycode3759/competitions/blob/main/2023/3.11YZOJ.C1369/C/C.cpp)上就不复制粘贴浪费字数了（

## D - 抓内鬼（Public NOIP Round #3）

- 第一步：用 Dijkstra 找出点 $1$ 到 $n$ 的所有最短路中包含的所有边；
- 第二步：可以证明这些边构成了一个有向无环图（DAG），对这些边进行拓扑排序；
- 第三步：将前 $k$ 个点标记为 $U$，剩下的标记为 $P$。现在所有从点 $1$ 到 $n$ 的最短路只会在 $P$ 和 $U$ 之间切换 1 次，所以**合法方案存在当且仅当存在有一条长度大于等于 3 的最短路**。
- 特殊情况：如果存在一条直接从 $1$ 到 $n$ 的边则需要特殊处理。由于图是点权图，因此这条直达的边一定是 $1$ 到 $n$ 的**唯一最短边**。因此除了 $n=2,k=1$ 的情况外合法方案永远存在。

```c++
// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const int INF = (1 << 30);

struct VertexCmp
{
    bool operator()(int a, int b)
    {
        return dis[a] > dis[b];
    }
};
priority_queue<int, vector<int>, VertexCmp> vertexies;

vector<int> destFrom[MAXN];

int weight[MAXN];
int dis[MAXN];

int main()
{
    int n, m, k;
    bool direct = false;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", weight + i);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        if ((a == 1 && b == n) || (a == n && b == 1))
        {
            direct = true;
            // 防止输入没读完卡出奇奇怪怪的问题，特殊情况打标记判断
        }
        scanf("%d%d", &a, &b);
        destFrom[a].push_back(b);
        destFrom[b].push_back(a);
    }
    if (direct)
    {
        printf((n == 2 && k == 1) ? "impossible\n" : "UP\n");
        return 0;
    }

    // Dijkstra
    dis[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dis[i] = INF;
    }
    for (int i = 0; i < n; i++)
    {
        int v = vertexies.top();
        vector<int> &outEdges = destFrom[v];
        for (int j = 0; j < outEdges.size(); j++)
        {
            int &dest = outEdges[j];
            dis[dest] = min(dis[dest], dis[v] + weight[dest]);
        }
        vertexies.pop();
    }

    // TODO: 找出点11到nn的所有最短路中包含的所有边

    // TODO: 拓扑排序

    // TODO: 输出方案+判断存在有长度大于等于3的最短路

    return 0;
}
```

> 2023.4.30 更新：本题和最短路径和拓扑排序等等**统统没有关系**。对于特殊情况的判断保持不变，剩下的一般情况只需要在点 $1$ 和点 $n$ 放不同的壮丁就可以保证符合题意。假设点 1 放的是 U，点 n 放的是 P，那么可以从点 1 开始 BFS 一层层拓展并尽量放 U，U 放完了就全放 P，如此构造的方案一定是合法的。

```c++
// 读边时进行特判
for (int i = 0; i < m; i++)
{
    int f, t;
    scanf("%d%d", &f, &t);
    if ((f == 1 && t == n) || (f == n && t == 1))
    {
        if (k == 1 && n == 2)
        {
            printf("impossible\n");
            return 0;
        }
        if (k >= 2)
        {
            for (int i = 1; i <= k - 1; i++)
                printf("U");
            for (int i = 1; i <= n - k; i++)
                printf("P");
            printf("U");
        }
        else
        {
            for (int i = 1; i <= n - k - 1; i++)
                printf("P");
            for (int i = 1; i <= k; i++)
                printf("U");
            printf("P");
        }
        printf("\n");
        return 0;
    }
    dest[f].push_back(t);
    dest[t].push_back(f);
}

// BFS构造解
queue<int> Q;
Q.push(1);
while (!Q.empty())
{
    int u = Q.front();
    Q.pop();
    if (vis[u])
        continue;
    if (k == 0)
        break;

    vis[u] = true;
    mark[u] = true;
    k--;

    vector<int> &d = dest[u];
    for (int i = 0; i < d.size(); i++)
    {
        Q.push(d[i]);
    }
}

for (int i = 1; i <= n; i++)
{
    printf("%c", mark[i] ? 'U' : 'P');
}
printf("\n");
```

## 小结

1. 看到题目第一反应不是“如何 AC”，而应该是“如何用最少的时间/最无脑的思路骗到最多的分”；
2. 某个知识点不会不要慌，更不要执着于写自己不熟练的模板，深层次挖掘题目信息或许可以找到更优解。

> 本次考试应该是前面 30 分钟 ~ 50 分钟，前 3 题至少至少拿下大概 90+30+50（无脑递推，不考虑炸弹），大概 170 分。
> 如果推理能力较好，应该就是前面一个小时以内拿下 300 分，然后剩下的时间集中思考处理第 4 题，这才是正常的状态。
>
> 考试反馈出来的问题很严重：**考试策略严重不恰当**（如果不是考试策略问题，就是代码能力极度弱，前面 3 题可以体现出这方面的问题），**思维能力有待提高**，需要予以高度重视！
>
> —— Tingtime
