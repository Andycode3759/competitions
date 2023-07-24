// AC
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ulong;
const int MAXN = 13;

ulong dp[MAXN][MAXN];
int a, b;
int brk[MAXN], cnt;

ulong getAns(int x)
{
    ulong res = 0;
    cnt = 0;
    memset(brk, 0, sizeof brk);
    do
    {
        brk[++cnt] = x % 10;
        x /= 10;
    } while (x > 0);

    for (int i = cnt; i >= 1; i--)
    {
        for (int j = 0; j < brk[i]; j++)
        {
            if (j < brk[i + 1])
                continue;
            res += dp[i][j];
        }
        if (brk[i] < brk[i + 1])
        {
            res--;
            break;
        }
    }

    return res;
}

int main()
{
    for (int j = 0; j <= 9; j++)
        dp[1][j] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = j; k <= 9; k++)
            {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    while (scanf("%d%d", &a, &b) == 2)
    {
        printf("%llu\n", getAns(b) - getAns(a - 1));
    }
    return 0;
}
