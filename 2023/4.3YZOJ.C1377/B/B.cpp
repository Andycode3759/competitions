#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;

int n, m, r;
int v[MAXN];

struct Edge
{
    Edge(int _d, int _n)
    {
        dest = _d;
        next = _n;
    }
    int dest, next;
};
vector<Edge> edges;
int fir[MAXN];

vector<int> child[MAXN];
bool mark[MAXN];
void addEdge(int src, int dst)
{
    edges.push_back(Edge(dst, fir[src]));
    fir[src] = edges.size() - 1;
}
void dfs(int node) // 无向转有向
{
    mark[node] = true;
    for (int i = fir[node]; i != -1; i = edges[i].next)
    {
        Edge &e = edges[i];
        if (mark[e.dest])
            continue;
        child[node].push_back(e.dest);
        dfs(e.dest);
    }
}

// // 暴力 60%
// void addVal(int node, int delta)
// {
//     v[node] += delta;
// }
long long getSumDumber(int root)
{
    long long sum = v[root];
    vector<int> &c = child[root];
    for (int i = 0; i < c.size(); i++)
    {
        sum += getSumDumber(c[i]);
    }
    return sum;
}

// "正解" 80%
int tsp = 0;
int tiIn[MAXN], tiOrd[MAXN], tiOut[MAXN];
void dfsTime(int x)
{
    tiOrd[++tsp] = x;
    tiIn[x] = tsp;
    vector<int> &c = child[x];
    for (int i = 0; i < c.size(); i++)
    {
        dfsTime(c[i]);
    }
    tiOut[x] = tsp;
}
// void addVal(int node, int delta)
// {
//     v[node] += delta;
// }
long long getSumDumb(int root)
{
    long long sum = 0;
    for (int i = tiIn[root]; i <= tiOut[root]; i++)
    {
        sum += v[tiOrd[i]];
    }
    return sum;
}

// 正解+线段树
struct SegTreeNode
{
    int left, right;
    long long sum;
};
struct SegTree
{
    SegTreeNode nodes[2 * MAXN];
    int size;

    SegTree(int _s)
    {
        size = _s;
    }

    void build(int idx, int l, int r)
    {
        nodes[idx].left = l;
        nodes[idx].right = r;
        if (l == r)
        {
            nodes[idx].sum = v[tiOrd[l]];
            return;
        }

        int mid = (l + r) >> 1;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        nodes[idx].sum = nodes[idx * 2].sum + nodes[idx * 2 + 1].sum;

        // printf("%6d%6d%6lld\n", l, r, nodes[idx].sum);
    }
    long long query(int idx, int l, int r)
    {
        // printf("query(%d,%d,%d)\n", idx, l, r);
        SegTreeNode &n = nodes[idx];
        if (n.left == l && n.right == r)
        {
            return n.sum;
        }
        int mid = (n.left + n.right) >> 1;
        long long res = 0;
        if (l <= mid)
        {
            res += query(idx * 2, l, mid);
        }
        if (r > mid)
        {
            res += query(idx * 2 + 1, mid + 1, r);
        }
        return res;
    }
};

SegTree sgt(n);
void addVal(int node, int delta)
{
}
long long getSum(int root)
{
    return sgt.query(1, tiIn[root], tiOut[root]);
}

int main()
{
    memset(fir, -1, sizeof(fir));
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", v + i);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }
    dfs(r);
    dfsTime(r);

    // printf("%6s%6s%6s\n", "l", "r", "sum");
    sgt.build(1, 1, n);

    // printf("     x    in   out\n");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%6d%6d%6d\n", i, tiIn[i], tiOut[i]);
    // }

    while (m--)
    {
        int op;
        scanf("%d", &op);
        int a, x;
        switch (op)
        {
        case 1:
            scanf("%d%d", &a, &x);
            addVal(a, x);
            break;

        case 2:
            scanf("%d", &a);
            printf("%lld\n", getSum(a));
            break;
        }
    }
    return 0;
}