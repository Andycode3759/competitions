// ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 404;
const long long INF = (1LL << 61);
long long dis[MAXN][MAXN];

int main()
{
    int n; // sight count
    int m; // path count
    int q; // plan count
    scanf("%d%d%d", &n, &m, &q);

    // init
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = i == j ? 0 : INF;
        }
    }

    // read path
    for (int i = 0; i < m; i++)
    {
        int from, to, len;
        scanf("%d%d%d", &from, &to, &len);
        dis[from][to] = min(dis[from][to], 1LL * len);
        dis[to][from] = dis[from][to];
    }

    // Floyd
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

    // requests
    for (int i = 0; i < q; i++)
    {
        int st, ed;
        scanf("%d%d", &st, &ed);
        printf("%lld\n", dis[st][ed] >= INF ? -1 : dis[st][ed]);
    }

    return 0;
}
