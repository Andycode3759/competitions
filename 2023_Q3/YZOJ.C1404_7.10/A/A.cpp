// AC
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 505;

int n, m;
int ans[MAXN];
bool G[MAXN][MAXN];
int cnt[MAXN];

int main()
{
    ans[0] = 0, ans[1] = ans[2] = ans[3] = 1;
    for (int i = 4; i < MAXN; i++)
    {
        for (int j = 1; j < i; j++)
        {
            ans[i] = max(ans[i], min(ans[i - 1 - j] + ans[j], ans[i - j] + ans[j - 1]));
        }
    }
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(G, false, sizeof(G));
        memset(cnt, 0, sizeof(cnt));
        int u, v;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            u++, v++;
            G[u][v] = G[v][u] = true;
        }
        int cur = 1;
        for (int i = 2; i <= n; i++)
        {
            if (G[i][i - 1])
                cur++;
            else
                cnt[cur]++, cur = 1;
        }
        cnt[cur]++;

        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d ", cnt[i]);
        // }
        // printf("\n");

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += ans[i] * cnt[i];
        }
        printf("%d\n", res);
    }
    return 0;
}
