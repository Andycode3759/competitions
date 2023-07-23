// AC
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long ulong;
const int MOD = 998244353;
const int MAXN = 1003;

int id;
int land[MAXN][MAXN];
int n, m, doC, doF;
ulong row[MAXN][MAXN], col[MAXN][MAXN];
ulong rowSum[MAXN][MAXN], fCnt[MAXN][MAXN];

inline void solve()
{
    ulong resC = 0, resF = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (row[i][j] <= 1 || col[i][j] <= 2)
                continue;
            resC += (rowSum[i + col[i][j] - 1][j] - rowSum[i + 1][j]) * (row[i][j] - 1);
            resF += (row[i][j] - 1) * (fCnt[i + col[i][j] - 2][j] - fCnt[i + 1][j]);
        }
    }

    printf("%llu %llu\n", resC * doC % MOD, resF * doF % MOD);
}

int main()
{
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);

    int T;
    scanf("%d%d", &T, &id);
    while (T--)
    {
        memset(land, false, sizeof land);
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(rowSum, 0, sizeof rowSum);
        memset(fCnt, 0, sizeof fCnt);

        scanf("%d%d%d%d", &n, &m, &doC, &doF);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%1d", &land[i][j]);
                land[i][j] ^= 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (land[i][j] == 0)
                    row[i][j] = 0;
                else
                    row[i][j] = row[i][j + 1] + land[i][j];
            }
        }
        for (int j = 1; j <= m; j++)
        {
            for (int i = n; i >= 1; i--)
            {
                if (land[i][j] == 0)
                    col[i][j] = 0;
                else
                    col[i][j] = col[i + 1][j] + land[i][j];
            }
        }
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (row[i][j] == 0)
                    rowSum[i][j] = 0;
                else
                    rowSum[i][j] = rowSum[i - 1][j] + row[i][j] - 1;

                // if (col[i][j] <= 1 || row[i][j] <= 1)
                //     fCnt[i][j] = 0;
                // else
                fCnt[i][j] = (col[i][j] - 1) * (row[i][j] - 1) + fCnt[i - 1][j];
            }
        }

        // printf(" fCnt");
        // for (int i = 1; i <= m; i++)
        //     printf("%5d", i);
        // printf("\n");
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%5d", i);
        //     for (int j = 1; j <= m; j++)
        //     {
        //         printf("%5d", fCnt[i][j]);
        //     }
        //     printf("\n");
        // }

        if (doC == 0 && doF == 0)
            printf("0 0\n");
        else
            solve();
    }
    return 0;
}
