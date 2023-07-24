// AC
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 200005;

struct Edge
{
    Edge(int _d = 0, int _n = -1, int _v = 0) : dest(_d), next(_n), val(_v)
    {
    }
    int dest, next, val;
};
int edgeCnt;
Edge edges[MAXN * 2];
int head[MAXN];
int deg[MAXN];

inline void addEdge(int src, int dest, int val)
{
    edges[++edgeCnt] = Edge(dest, head[src], val);
    head[src] = edgeCnt;
}

bool vis[MAXN];
long long dp[MAXN], ans[MAXN];
void dfsDP(int u)
{
    dp[u] = 0;
    vis[u] = true;
    for (int e = head[u]; e != -1; e = edges[e].next)
    {
        int v = edges[e].dest, w = edges[e].val;
        if (vis[v])
            continue;
        // printf("%d -> %d\n", u, v);
        if (deg[v] == 1)
            dp[u] += w;
        else
            dfsDP(v), dp[u] += min(dp[v], 1LL * w);
    }
    // printf("dp[%d]=%lld\n", u, dp[u]);
}
void dfsAns(int u)
{
    vis[u] = true;
    for (int e = head[u]; e != -1; e = edges[e].next)
    {
        int v = edges[e].dest, w = edges[e].val;
        if (vis[v])
            continue;
        if (deg[u] == 1)
            ans[v] = dp[v] + w;
        else
            ans[v] = dp[v] + min(ans[u] - min(dp[v], 1LL * w), 1LL * w);
        dfsAns(v);
    }
}

int n;

inline void clearVis()
{
    for (int i = 1; i <= n; i++)
        vis[i] = false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        edgeCnt = 0;
        for (int i = 0; i < MAXN; i++)
        {
            edges[2 * i + 1] = edges[2 * i] = Edge();
            deg[i] = 0;
            head[i] = -1;
            dp[i] = ans[i] = 0;
        }
        scanf("%d", &n);
        clearVis();
        int u, v, w;
        for (int i = 1; i <= n - 1; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            deg[u]++, deg[v]++;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        dfsDP(1);
        ans[1] = dp[1];
        clearVis();
        dfsAns(1);
        long long res = -1;
        for (int i = 1; i <= n; i++)
            res = max(res, ans[i]);
        printf("%lld\n", res);
    }
    return 0;
}
