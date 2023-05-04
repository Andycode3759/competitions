// 90%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int MAXSN = 100006;

int canvas[MAXN][MAXN];

int spCanvas[MAXSN];

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(canvas, 0, sizeof(canvas));
        memset(spCanvas, 0, sizeof(spCanvas));
        bool spCase = false;
        int n, m, q;
        // n行m列
        scanf("%d%d%d", &n, &m, &q);

        if (m >= MAXN)
            spCase = true;

        int opt, x, c;
        // opt=0 行
        // opt=1 列
        for (int j = 0; j < q; j++)
        {
            scanf("%d%d%d", &opt, &x, &c);
            if (spCase)
            {
                spCanvas[x] = c;
            }
            else
            {
                if (opt == 0)
                {
                    for (int i = 1; i <= m; i++)
                    {
                        canvas[x][i] = c;
                    }
                }
                if (opt == 1)
                {
                    for (int i = 1; i <= n; i++)
                    {
                        canvas[i][x] = c;
                    }
                }
            }
        }

        if (spCase)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int i = 1; i <= m; i++)
                {
                    printf("%d ", spCanvas[i]);
                }
                printf("\n");
            }
        }
        else
        {
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= m; y++)
                {
                    printf("%d ", canvas[x][y]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
