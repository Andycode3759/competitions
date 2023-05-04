#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100002;

int f[MAXN];
int n, mod;

int main()
{
    scanf("%d%d", &n, &mod);

    f[0] = f[1] = 1;
    for (int y = 2; y <= n; y++)
    {
        int sum = 0;
        for (int x = 1; x <= y - 1; x++)
        {
            sum += f[x];
            sum %= mod;
        }
        int g = 0;
        for (int x = 1; x <= y - 1; x++)
        {
            if ((x ^ y) < x)
            {
                g += f[x ^ y];
                g %= mod;
            }
        }
        f[y] = (1 + sum - g + mod) % mod;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += f[i];
        ans %= mod;
    }
    printf("%d\n", ans % mod);
    return 0;
}