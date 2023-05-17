#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2008;
const int MOD = 23;

int modPow[MAXN];
char canvas[MAXN][MAXN];
int n, m;
bool mark[30];
int hashX[MAXN][MAXN], hashY[MAXN][MAXN];

int findX(int ax, int ay, int bx, int by)
{
    return hashX[bx][by] - hashX[ax][ay - 1] * modPow[by - ay + 1];
}
int findY(int ax, int ay, int bx, int by)
{
    return hashY[bx][by] - hashY[ax - 1][ay] * modPow[bx - ax + 1];
}

int main()
{
    // freopen("circle.in", "r", stdin);
    // freopen("circle.out", "w", stdout);
    scanf("%d%d", &n, &m);

    modPow[0] = 1;
    for (int i = 1; i <= max(n, m); i++)
    {
        modPow[i] = modPow[i - 1] * MOD;
    }

    int lc = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", canvas[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            int c = canvas[i][j] - 'a';
            if (!mark[c])
                lc++;
            mark[c] = true;

            hashX[i][j] = hashX[i][j - 1] * MOD + c + 1;
            hashY[i][j] = hashY[i - 1][j] * MOD + c + 1;
        }
    }
    if (lc == 1) // sp
    {
        // printf("isSp!\n");
        printf("%lld\n", 1LL * m * n * (m - 1) * (n - 1) / 4);
        return 0;
    }

    long long ans = 0;

    for (int ax = 1; ax < n; ax++)
    {
        for (int ay = 1; ay < m; ay++)
        {
            for (int bx = ax + 1; bx <= n; bx++)
            {
                if (canvas[bx][ay] != canvas[bx - 1][ay])
                    break;
                for (int by = ay + 1; by <= m; by++)
                {
                    if (canvas[ax][by] != canvas[ax][by - 1])
                        break;
                    if (findX(ax, ay, ax, by) == findX(bx, ay, bx, by) &&
                        findY(ax, ay, bx, ay) == findY(ax, by, bx, by))
                        ans++;
                }
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
