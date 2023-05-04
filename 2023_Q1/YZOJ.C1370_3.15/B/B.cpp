// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
const long long INF = (1LL << 31) - 1;
const int MOD = (1 << 31) - 1;

long long dis[MAXN];
bool book[MAXN];
int graph[MAXN][MAXN];

int main()
{
    // input
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[v][u] = graph[u][v] = min(graph[u][v], w);
    }

    // Dijkstra
    for (int i = 1; i <= n; i++)
    {
        dis[i] = graph[1][i];
    }
    book[1] = true;
    for (int i = 1; i <= n; i++)
    {
        int v = 0, minDis = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!book[j] && dis[j] <= minDis)
            {
                v = j;
                minDis = dis[j];
            }
        }
        book[v] = true;
        for (int j = 1; j <= n; j++)
        {
            dis[j] = min(dis[j], dis[v] + graph[v][j]);
        }
    }

    // ?

    for (int i = 1; i <= n; i++)
    {
        printf("dis[%d]=%lld\n", i, dis[i]);
    }

    long long ans = 1;

    printf("%lld\n", ans);

    return 0;
}
