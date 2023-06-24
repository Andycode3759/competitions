#include <cstdio>
using namespace std;
const int MAXN = 25;

long long fra[MAXN];
long long f[MAXN];

int main()
{
    fra[0] = 1;
    f[1] = 1, f[2] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fra[i] = fra[i - 1] * i;
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
    }

    for (int n = 1; n < MAXN; n++)
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += fra[n] / (fra[i] * fra[n - i]) * f[i];
        }
        printf("n=%d fra[n]=%lld f[n]=%lld ans=%lld\n", n, fra[n], f[n], sum);
    }

    return 0;
}
