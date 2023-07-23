#include <cstdio>
using namespace std;
typedef unsigned long long ulong;
const int MAXN = 11;

ulong dp[MAXN][MAXN][MAXN];
int a, b;
int brkA[MAXN], brkB[MAXN], cntA = 0, cntB = 0;

int main()
{
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = j; k <= 9; k++)
            {
                dp[i][j][k] = 1;
            }
        }
    }

    for (int i = 3; i < MAXN; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = j; k <= 9; k++)
            {
                for (int x = k; x <= 9; x++)
                {
                    dp[i][j][k] += dp[i - 1][k][x];
                }
            }
        }
    }
    // printf("%llu\n", dp[4][1][2]);
    while (scanf("%d%d", &a, &b) == 2)
    {
        a--;
        cntA = 0, cntB = 0;
        while (a > 0)
        {
            brkA[++cntA] = a % 10;
            a /= 10;
        }
        while (b > 0)
        {
            brkB[++cntB] = b % 10;
            b /= 10;
        }

        for (int i = 2; i <= cntB; i++)
        {
            if (brkB[i] > brkB[i - 1])
                brkB[i - 1] = 9, brkB[i]--;
        }
        for (int i = cntA - 1; i >= 1; i--)
        {
            if (brkA[i] < brkA[i + 1])
                brkA[i] = brkA[i + 1];
        }

        a = b = 0;
        for (int i = cntA; i >= 1; i--)
            a = a * 10 + brkA[i];
        for (int i = cntB; i >= 1; i--)
            b = b * 10 + brkB[i];
        // printf("%d %d\n", a, b);

        ulong ans1 = cntB > 1 ? 9 : brkB[1];

        for (int i = 2; i < cntB; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                for (int k = 1; k <= 9; k++)
                {
                    ans1 += dp[i][j][k];
                }
            }
        }

        if (cntB > 2)
        {
            for (int j = 1; j < brkB[cntB]; j++)
            {
                for (int k = 1; k <= 9; k++)
                {
                    ans1 += dp[cntB][j][k];
                }
            }
        }
        if (cntB > 1)
        {
            for (int k = 1; k <= brkB[cntB - 1]; k++)
            {
                ans1 += dp[cntB][brkB[cntB]][k];
            }
        }

        ulong ans2 = cntA > 1 ? 9 : brkA[1];

        for (int i = 2; i < cntA; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                for (int k = 1; k <= 9; k++)
                {
                    ans2 += dp[i][j][k];
                }
            }
        }

        if (cntA > 2)
        {
            for (int j = 1; j < brkA[cntA]; j++)
            {
                for (int k = 1; k <= 9; k++)
                {
                    ans2 += dp[cntA][j][k];
                }
            }
        }
        if (cntA > 1)
        {
            for (int k = 1; k <= brkA[cntA - 1]; k++)
            {
                ans2 += dp[cntA][brkA[cntA]][k];
            }
        }

        printf("%llu\n", ans1 - ans2);
    }

    // printf("%llu\n", dp[3][2][3]);

    return 0;
}
