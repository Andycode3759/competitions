// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;

int n, m;

int graph[MAXN][MAXN]; // 1赢，0输，-1未知，-2无解
int dp(int a, int b)
{
    if (graph[a][b] != -1)
        return graph[a][b];

    graph[a][b] = -2;
    // printf("dp: %d, %d\n", a, b);

    for (int k = 1; k <= n; k++)
    {
        if (k == a || k == b)
            continue;
        if (dp(a, k) == 1 && dp(k, b) == 1)
        {
            graph[a][b] = 1;
            graph[b][a] = 0;
            return graph[a][b];
        }
    }
    return graph[a][b];
}

void printTable()
{
    printf("%3s", "dp");
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

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(graph, -1, sizeof(graph));

        scanf("%d%d", &n, &m);
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            graph[a][b] = 1;
            graph[b][a] = 0;
        }
        // printTable();

        for (a = 1; a <= n; a++)
        {
            for (b = 1; b <= n; b++)
            {
                if (a == b)
                    continue;
                dp(a, b);
            }
        }

        // printTable();

        int ans = 0;
        for (a = 1; a <= n; a++)
        {
            for (b = a + 1; b <= n; b++)
            {
                if (graph[a][b] == -2)
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
