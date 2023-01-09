#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202;
const int INF = 1e9 + 9;

int repairTime[MAXN];
int repairedVillage = -1;

long long rawDis[MAXN][MAXN];
long long dis[MAXN][MAXN];

int read()
{
    int res = 0;
    char input = getchar();
    while (input < '0' || input > '9')
    {
        input = getchar();
    }
    while (input >= '0' && input <= '9')
    {
        res = res * 10 + input - '0';
        input = getchar();
    }
    return res;
}

int main()
{
    int n = read();
    int m = read();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = i == j ? 0 : INF;
            rawDis[i][j] = i == j ? 0 : INF;
        }
    }

    for (int i = 0; i < n; i++)
    {
        repairTime[i] = read();
    }
    for (int i = 0; i < m; i++)
    {
        int from = read(), to = read(), len = read();
        rawDis[from][to] = min(rawDis[from][to], 1LL * len);
        rawDis[to][from] = rawDis[from][to];
    }
    int q = read();
    while (q--)
    {
        int x = read(), y = read(), t = read();

        for (int i = repairedVillage + 1; i < n; i++)
        {
            if (t >= repairTime[i])
            {
                repairedVillage = i;
            }
            else
            {
                break;
            }
        }
        if (x > repairedVillage || y > repairedVillage)
        {
            printf("-1\n");
            continue;
        }

        for (int i = 0; i <= repairedVillage; i++)
        {
            for (int j = 0; j <= repairedVillage; j++)
            {
                dis[i][j] = min(dis[i][j], rawDis[i][j]);
                dis[j][i] = dis[i][j];
            }
        }

        for (int k = 0; k <= repairedVillage; k++)
        {
            for (int i = 0; i <= repairedVillage; i++)
            {
                for (int j = 0; j <= repairedVillage; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        printf("%lld\n", dis[x][y] >= INF ? -1LL : dis[x][y]);
    }
    return 0;
}