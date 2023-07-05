#include <cstdio>
using namespace std;
const int MAXN = 2505;
const int MAXM = 10004;
const int INF = (1 << 30) - 1;

constexpr long long max(const long long &a, const long long &b)
{
    return a > b ? a : b;
}
int readInt()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}
long long readLL()
{
    long long res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

struct Edge
{
    int a, b;
};
Edge edges[MAXM];

int n, m, k;
long long score[MAXN];
int graph[MAXN][MAXN];

long long solveSP1() // k=0
{
    long long ans = -1;
    for (int d1 = 2; d1 <= n; d1++)
    {
        for (int d2 = 2; d2 <= n; d2++)
        {
            if (d2 == d1)
                continue;
            for (int d3 = 2; d3 <= n; d3++)
            {
                if (d3 == d2 || d3 == d1)
                    continue;
                for (int d4 = 2; d4 <= n; d4++)
                {
                    if (d4 == d3 || d4 == d2 || d4 == d1)
                        continue;

                    if (graph[1][d1] == 1 && graph[d1][d2] == 1 && graph[d2][d3] == 1 && graph[d3][d4] == 1 &&
                        graph[d4][1] == 1)
                    {
                        ans = max(ans, score[d1] + score[d2] + score[d3] + score[d4]);
                    }
                }
            }
        }
    }
    return ans;
}
long long solveGeneral()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    long long ans = -1;
    for (int d1 = 2; d1 <= n; d1++)
    {
        for (int d2 = 2; d2 <= n; d2++)
        {
            if (d2 == d1)
                continue;
            for (int d3 = 2; d3 <= n; d3++)
            {
                if (d3 == d2 || d3 == d1)
                    continue;
                for (int d4 = 2; d4 <= n; d4++)
                {
                    if (d4 == d3 || d4 == d2 || d4 == d1)
                        continue;

                    if (graph[1][d1] <= k + 1 && graph[d1][d2] <= k + 1 && graph[d2][d3] <= k + 1 &&
                        graph[d3][d4] <= k + 1 && graph[d4][1] <= k + 1)
                    {
                        ans = max(ans, score[d1] + score[d2] + score[d3] + score[d4]);
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);

    // scanf("%d%d%d", &n, &m, &k);
    n = readInt();
    m = readInt();
    k = readInt();
    for (int i = 2; i <= n; i++)
    {
        // scanf("%lld", score + i);
        score[i] = readLL();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        // scanf("%d%d", &edges[i].a, &edges[i].b);
        edges[i].a = readInt();
        edges[i].b = readInt();
        graph[edges[i].a][edges[i].b] = 1;
        graph[edges[i].b][edges[i].a] = 1;
    }

    if (k == 0)
        printf("%lld\n", solveSP1());
    else
        printf("%lld\n", solveGeneral());

    return 0;
}
