#include <cstdio>
using namespace std;
constexpr int MAXN = 2005;
constexpr int MOD = 1e9 + 7;

int n;
long long dp[MAXN][MAXN]; // dp[i][j]=>长度为i的串，i在位置j
long long sum[MAXN][MAXN];
bool s[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int t;
        scanf("%d", &t);
        s[i] = t;
    }

    dp[1][1] = 1;
    sum[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum[1][i] = sum[1][i - 1] + dp[1][i];
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i])
        {
            for (int j = 2; j <= i + 1; j++)
            {
                // for (int k = 1; k <= j - 1; k++)
                // {
                //     dp[i + 1][j] += dp[i][k];
                //     if (dp[i + 1][j] >= MOD)
                //         dp[i + 1][j] -= MOD;
                // }
                dp[i + 1][j] = (dp[i + 1][j] + sum[i][j - 1]) % MOD;
            }
        }
        else
        {
            for (int j = 1; j <= i; j++)
            {
                // for (int k = j; k <= i; k++)
                // {
                //     dp[i + 1][j] += dp[i][k];
                //     if (dp[i + 1][j] >= MOD)
                //         dp[i + 1][j] -= MOD;
                // }
                dp[i + 1][j] = (dp[i + 1][j] + sum[i][i] - sum[i][j - 1]) % MOD;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            sum[i + 1][j] = sum[i + 1][j - 1] + dp[i + 1][j];
        }

        // printf("  dp");
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%4d", i);
        // }
        // printf("\n");
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%4d", i);
        //     for (int j = 1; j <= n; j++)
        //     {
        //         printf("%4lld", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("  sum");
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%4d", i);
        // }
        // printf("\n");
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%4d", i);
        //     for (int j = 1; j <= n; j++)
        //     {
        //         printf("%4lld", sum[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }

    printf("%lld\n", sum[n][n] % MOD);

    return 0;
}