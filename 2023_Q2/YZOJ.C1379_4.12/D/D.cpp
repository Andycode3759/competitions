#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAX_LOGN = 20;

int n, m;
int faLog[MAX_LOGN][MAXN]; // 倍增祖先
int depth[MAXN];           // 节点深度

struct Edge
{
    Edge(int _d, int _n) : dest(_d), next(_n)
    {
    }
    int dest, next;
};
vector<Edge> edges;
int fir[MAXN];
void addEdge(int from, int to)
{
    edges.push_back(Edge(to, fir[from]));
    fir[from] = edges.size() - 1;
}

// 记录父亲+统计深度
bool mark[MAXN];
void dfs(int n, int fa, int d)
{
    faLog[0][n] = fa;
    depth[n] = d;
    mark[n] = true;
    for (int i = fir[n]; i != -1; i = edges[i].next)
    {
        Edge &e = edges[i];
        if (mark[e.dest])
            continue;
        dfs(e.dest, n, d + 1);
    }
}

void init()
{
    for (int lg = 1; lg < MAX_LOGN; lg++)
    {
        for (int i = 1; i <= n; i++)
        {
            faLog[lg][i] = faLog[lg - 1][faLog[lg - 1][i]];
        }
    }
}

int findLCA(int x, int y)
{
    if (depth[x] < depth[y]) // 保证x比y深
        swap(x, y);

    // 上移x
    for (int lg = MAX_LOGN - 1; lg >= 0; lg--)
    {
        int t = faLog[lg][x];
        if (t <= 0 || depth[t] < depth[y])
            continue;
        x = t;
        if (depth[x] == depth[y])
            break;
    }

    if (x == y)
        return x;

    for (int lg = MAX_LOGN; lg >= 0; lg--)
    {
        if (faLog[lg][x] != faLog[lg][y])
        {
            x = faLog[lg][x];
            y = faLog[lg][y];
        }
    }
    return faLog[0][x];
}

struct Path
{
    int p1, p2;
    int lca = -1;

    int getLCA() // 缓存LCA
    {
        if (lca >= 1)
            return lca;
        return lca = findLCA(p1, p2);
    }
};
struct PathCmp
{
    bool operator()(Path a, Path b)
    {
        return depth[a.getLCA()] > depth[b.getLCA()];
    }
};
Path paths[MAXN];

bool col[MAXN];
void dfsColor(int n, int end)
{
    col[n] = true;
    if (n == end)
        return;
    dfsColor(faLog[0][n], end);
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(fir, -1, sizeof(fir));
        memset(mark, false, sizeof(mark));
        memset(depth, 0, sizeof(depth));
        memset(faLog, 0, sizeof(faLog));
        memset(col, false, sizeof(col));
        vector<Edge>().swap(edges);

        int a, b;
        for (int i = 1; i <= n - 1; i++)
        {
            scanf("%d%d", &a, &b);
            addEdge(a, b);
            addEdge(b, a);
        }
        dfs(1, 0, 0);
        init();

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &paths[i].p1, &paths[i].p2);
        }
        sort(paths, paths + m, PathCmp());

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            Path &p = paths[i];
            if (col[p.getLCA()])
                continue;
            dfsColor(p.p1, p.getLCA());
            dfsColor(p.p2, p.getLCA());
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
