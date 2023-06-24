// AC
#include <cstdio>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e8 + 8;

int n;
int f[MAXN];
int mxn = 2;

int main()
{
    f[1] = 1, f[2] = 3;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n > mxn)
        {
            for (int i = mxn + 1; i <= n + 1; i++)
            {
                f[i] = (int)(1LL * f[i - 1] + f[i - 2]) % MOD;
            }
            mxn = n;
        }
        printf("%d\n", (n % 2 == 0) ? 5 : -5);
        if (n == 1)
            printf("1\n");
        else if (n == 2)
            printf("10\n");
        else
            printf("%lld\n", (1LL * f[n] * f[n + 1] - 2) % MOD);
    }
    return 0;
}
