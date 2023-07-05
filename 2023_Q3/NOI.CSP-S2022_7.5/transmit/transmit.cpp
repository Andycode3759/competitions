#include <cstdio>
using namespace std;
const int MAXN = 2003;
const long long INF = (1LL << 58) - 1;

constexpr const long long min(const long long &a, const long long &b)
{
    return a < b ? a : b;
}

int n, q, k;
int v[MAXN];
bool graphRaw[MAXN][MAXN], graph[MAXN][MAXN];
long long cost[MAXN][MAXN];

void dfs(int d1, int d2, int d3, int x, int step)
{
    if (step <= 0)
    {
        graph[x][d1] = graph[d1][x] = true;
        graph[x][d2] = graph[d2][x] = true;
        graph[x][d3] = graph[d3][x] = true;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (graphRaw[x][i])
        {
            dfs(d2, d3, x, i, step - 1);
        }
    }
}

// functions for debug
void printGraph()
{
    printf("   ");
    for (int i = 1; i <= n; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%3d", i);
        for (int j = 1; j <= n; j++)
        {
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }
}
void printGraphRaw()
{
    printf("   ");
    for (int i = 1; i <= n; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%3d", i);
        for (int j = 1; j <= n; j++)
        {
            printf("%3d", graphRaw[i][j]);
        }
        printf("\n");
    }
}
void printCost()
{
    printf("     ");
    for (int i = 1; i <= n; i++)
    {
        printf("%5d", i);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%5d", i);
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] >= INF)
                printf("  INF");
            else
                printf("%5lld", cost[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    freopen("transmit.in", "r", stdin);
    freopen("transmit.out", "w", stdout);

    scanf("%d%d%d", &n, &q, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", v + i);
    }
    int s, t;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &s, &t);
        graphRaw[s][t] = true;
        graphRaw[t][s] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        dfs(0, 0, 0, i, k);
    }

    // printGraph();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = graph[i][j] ? v[i] + v[j] : INF;
        }
    }

    // printCost();

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j] - v[k]);
            }
        }
    }

    // printCost();

    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &s, &t);
        printf("%lld\n", cost[s][t]);
    }

    return 0;
}
