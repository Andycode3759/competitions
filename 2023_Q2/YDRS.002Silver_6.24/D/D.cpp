#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1003;
const int MOD = 998244353;
const int INF = (1 << 30) - 1;

struct Edge
{
    Edge(int _d, int _c) : dest(_d), cost(_c)
    {
    }
    int dest, cost;
};
vector<Edge> graph[MAXN];

int n, m;
int path[MAXN];
int bestCost = INF;
int ans[MAXN];
bool vis[MAXN];

void dfs1(int cur, int v, int cost)
{
    if (cur == v)
    {
        bestCost = min(cost, bestCost);
        return;
    }
    for (int u = 0; u < graph[cur].size(); u++)
    {
        Edge ne = graph[cur][u];
        if (!vis[ne.dest])
        {
            vis[ne.dest] = true;
            dfs1(ne.dest, v, cost + ne.cost);
            vis[ne.dest] = false;
        }
    }
}
void dfs2(int cur, int v, int step, int cost)
{
    path[step] = cur;
    if (cur == v)
    {
        if (cost == bestCost)
        {
            for (int i = 1; i <= step; i++)
            {
                ans[path[i]]++;
                if (ans[path[i]] >= MOD)
                    ans[path[i]] -= MOD;
            }
        }
        return;
    }
    for (int u = 0; u < graph[cur].size(); u++)
    {
        Edge ne = graph[cur][u];
        if (!vis[ne.dest])
        {
            vis[ne.dest] = true;
            dfs2(ne.dest, v, step + 1, cost + ne.cost);
            vis[ne.dest] = false;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(Edge(b, c));
    }

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (u == v)
            {
                ans[u]++;
                if (ans[u] >= MOD)
                    ans[u] -= MOD;
            }
            else
            {
                bestCost = INF;
                memset(vis, false, sizeof(vis));
                dfs1(u, v, 0);
                memset(vis, false, sizeof(vis));
                dfs2(u, v, 1, 0);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}
