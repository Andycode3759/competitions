// 30%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150004;
const int MAXK = 4;
const int INF = (1 << 30) - 1;
int passlock[MAXK][MAXN];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    int t, k;
    scanf("%d%d", &t, &k);

    while (t--)
    {
        memset(passlock, 0, sizeof(passlock));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &passlock[i][j]);
            }
        }

        if (k == 1)
        {
            int minp = INF, maxp = -1;
            for (int i = 0; i < n; i++)
            {
                minp = min(minp, passlock[0][i]);
                maxp = max(maxp, passlock[0][i]);
            }
            printf("%d\n", maxp - minp);
        }
        else if (k == 2)
        {
            int minp = INF, maxp = -1;
            for (int i = 0; i < n; i++)
            {
                if (passlock[0][i] > passlock[1][i]) // 保证passlock[0][i]<=passlock[1][i]
                {
                    swap(passlock[0][i], passlock[1][i]);
                }
            }
            int ans = -1;
            for (int a = 0; a <= 1; a++)
            {
                minp = INF, maxp = -1;
                for (int i = 0; i < n; i++)
                {
                    minp = min(minp, passlock[a][i]);
                    maxp = max(maxp, passlock[a][i]);
                }
                ans = max(ans, maxp - minp);
            }

            printf("%d\n", ans);
        }
        else
        {
            printf("114514\n");
        }
    }

    return 0;
}
