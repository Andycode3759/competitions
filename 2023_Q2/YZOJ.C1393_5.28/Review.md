# 5.28 考试总结

## A - 矩形覆盖 ([YACS639](https://iai.sh.cn/problem/639))

扫描线的简化版，可以用线段树解决。将坐标离散化后，用线段树维护各个小区间的高度及面积和，懒惰标记就是更新的高度。注意下传信息时标记的处理，只有高的才能覆盖低的，以及离散化后的数据下标与区间长度的转化需要注意细节。

```c++
struct SegTreeNode
{
    int l, r;   // 对应x轴上pos[r]-pos[l-1]长度的区间
    long long area = 0;
    long long mark = 0;
};
struct Rect
{
    long long s, t, h;
    const bool operator<(const Rect &a) const
    {
        return h < a.h;
    }
};
const int MAXN = 300006;
SegTreeNode st[MAXN << 3];
Rect rects[MAXN];

vector<long long> pos;
map<long long, int> posRank;    // 原始数据对应离散化后的下标，这里图方便用个map

void passDown(int idx)  // 下传信息
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx * 2], &rc = st[idx * 2 + 1];
    if (node.mark > lc.mark)    // 只有高的能覆盖低的
    {
        lc.mark = node.mark;
        lc.area = (pos[lc.r] - pos[lc.l - 1]) * node.mark;
    }
    if (node.mark > rc.mark)
    {
        rc.mark = node.mark;
        rc.area = (pos[rc.r] - pos[rc.l - 1]) * node.mark;
    }
    node.mark = 0;
    node.area = lc.area + rc.area;
}
void gatherUp(int idx)  // 上传信息
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx * 2], &rc = st[idx * 2 + 1];
    node.area = lc.area + rc.area;
}
void build(int l, int r, int idx)   // 建树
{
    SegTreeNode &node = st[idx];
    node.l = l, node.r = r;
    node.area = 0;
    node.mark = 0;
    if (l == r)
        return;

    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    gatherUp(idx);
}
void update(int l, int r, long long height, int idx)    // 更新
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        node.mark = height;
        node.area = (pos[node.r] - pos[node.l - 1]) * height;
        return;
    }
    if (node.mark > 0)
        passDown(idx);

    int nmid = (node.l + node.r) >> 1;
    if (l <= nmid)
        update(l, r, height, idx * 2);
    if (r > nmid)
        update(l, r, height, idx * 2 + 1);
    gatherUp(idx);
}
long long query(int l, int r, int idx)  // 查询
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        return node.area;
    }
    if (node.mark > 0)
        passDown(idx);

    int nmid = (node.l + node.r) >> 1;
    long long res = 0;
    if (l <= nmid)
        res += query(l, r, idx * 2);
    if (r > nmid)
        res += query(l, r, idx * 2 + 1);
    return res;
}

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &rects[i].s, &rects[i].t, &rects[i].h);
        pos.push_back(rects[i].s);
        pos.push_back(rects[i].t);
    }

    sort(pos.begin(), pos.end());   //离散化
    unique(pos.begin(), pos.end());
    for (int i = 0; i < pos.size(); i++)
    {
        posRank[pos[i]] = i + 1;
    }

    sort(rects, rects + n);

    build(1, pos.size() - 1, 1);
    for (int i = 0; i < n; i++)
    {
        Rect &r = rects[i];
        update(posRank[r.s], posRank[r.t] - 1, r.h, 1);
    }

    printf("%lld\n", query(1, pos.size() - 1, 1));
    return 0;
}
```

~~然而超时了 只有 60 分~~

~~越卡常越慢~~

## B - 评测队列（二） ([YZCS662](https://iai.sh.cn/problem/662))

首先考虑只有 $2$ 个任务 $\#1,\#2$（1 前 2 后）的情况。有两种可能：

1. $\#2$ 完成编译后，$\#1$ 还没有运行完成，因此在 $\#1$ 运行完后立即运行 $\#2$，即 $b_1 \geq a_2$；
2. $\#2$ 完成编译前，$\#1$ 已经运行完成，运行服务器会出现一段空闲期，即 $b_1 < a_2$。

两种情况的总耗时分别是：

$$
T_1=a_1+a_2+b_1+b_2-a_2 \\
T_2=a_1+a_2+b_1+b_2-b_1
$$

合起来就是：$T=a_1+a_2+b_1+b_2-min(a_2,b_1)$。由于答案具有无后效性（保证当前最快时不改变之后的最快安排），因此可以将所有任务按照编译/运行时间交叉比较后排序（即 $min(a_2,b_1)<min(a_1,b_2)$ 的话将任务 $\#2$ 放前面，反之亦然），顺次模拟执行得出结果。

另一个难点可能在于模拟的实现：分别维护编译和运行服务器的总耗时，对于每一个任务，编译用时可以直接叠加（编译服务器一定不会出现空档），运行用时则需要考虑是前一个任务运行完还是当前任务编译完更耗时。

```c++
struct Task
{
    int comp, exec;
    const bool operator<(const Task &t) const   // 交叉比较
    {
        return min(t.exec, comp) < min(exec, t.comp);
    }
};

const int MAXN = 200006;
Task tasks[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &tasks[i].comp, &tasks[i].exec);
    }
    sort(tasks + 1, tasks + n + 1); // 直接排序

    long long ct = 0, et = 0;
    for (int i = 1; i <= n; i++)    // 模拟运行
    {
        Task &t = tasks[i];
        ct += t.comp;
        et = max(ct, et) + t.exec;
    }
    printf("%lld\n", et);
    return 0;
}

```

## C - 平地起高楼 ([51Nod-14045](https://www.51nod.com/Question/Index.html#questionId=14045))

突破点：$(i\ and\ j)+(i\ or\ j)=i+j$。

之后就容易发现，可以起高楼的平地坐标必须是 $gcd(x,y)$ 的倍数，也就是说一共有 $n \over gcd(x,y)$ 块可用的平地，只需要判断这个数是奇是偶即可。

```c++
long long n, x, y;
scanf("%lld%lld%lld", &n, &x, &y);
long long cnt = n / __gcd(x, y);
printf(cnt % 2 == 0 ? "lose\n" : "win\n");
```

## D - 独特数 ([YACS683](https://iai.sh.cn/problem/683))

一个比较暴力（但对于本题来说足够了）的做法是使用迭代加深 DFS，枚举指定位数的 0~9 排列，把排列拼成十进制数，得到的一定是独特数。只需注意开头一位不为 0 即可。

```c++
const int MAXN = 8900000;
long long uniNum[MAXN];
int uCnt = 0;   // 组合数的个数
int n;

bool vis[12];
void dfs(int step, int maxDepth, long long cur)
{
    if (step > maxDepth)
    {
        uniNum[uCnt++] = cur;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (vis[i] || (step == 1 && i == 0))    // 开头一位不能是0
            continue;

        vis[i] = true;
        dfs(step + 1, maxDepth, cur * 10 + i);
        vis[i] = false; // 回溯，记得撤销更改

        if (uCnt >= n)  // 已经枚举了n个就可以提前退出
            return;
    }
    return;
}

int main()
{
    scanf("%d", &n);
    for (int s = 1; s <= 10; s++)
    {
        dfs(1, s, 0);
        if (uCnt >= n)  // 已经枚举了n个可以提前退出
            break;
    }
    printf("%lld\n", uniNum[n - 1]);
    return 0;
}
```
