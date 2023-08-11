#include <cstdio>
#include <vector>
using namespace std;
constexpr int MAXN = 2000006;
constexpr int INF = (1 << 30) - 1;

struct Edge
{
    int src, dest;
};
struct Graph
{
    Edge edges[MAXN];
    vector<int> outs[MAXN];
    int tot = 0;
    void addEdge(int src, int dest)
    {
        edges[++tot].src = src, edges[tot].dest = dest;
        outs[src].push_back(dest);
        outs[dest].push_back(src);
    }
};

int n, m, q;
Graph G;

int dis[15][15];

int main()
{
    int T;
    scanf("%d", &T);
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G.addEdge(u, v);
        dis[u][v] = dis[v][u] = 1;
    }

    for (int i = 1; i <= G.tot; i++)
    {
        int u = G.edges[i].src, v = G.edges[i].dest;
        for (int i = 0, len1 = G.outs[u].size(); i < len1; i++)
        {
            int uu = G.outs[u][i];
            if (uu == v)
                continue;
            for (int j = 0, len2 = G.outs[v].size(); j < len2; j++)
            {
                int vv = G.outs[v][j];
                if (vv == u || uu == vv)
                    continue;
                dis[uu][vv] = dis[vv][uu] = 1;
            }
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dis[a][b] >= INF ? -1 : dis[a][b]);
    }

    return 0;
}