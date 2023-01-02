//ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 1e7 + 7;
int factOf[MAXN];
int knownFn = 0;
void exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    long long q = a / b, r = a % b;
    long long xt, yt;
    exgcd(b, r, xt, yt);
    x = yt;
    y = xt - q * yt;
}
long long inv(int n)
{
    long long x, y;
    exgcd(n, MOD, x, y);
    return (x + MOD) % MOD;
}
void calculateFact(int n)
{
    for (int i = knownFn + 1; i <= n; i++)
    {
        factOf[i] = (1LL * factOf[i - 1] * i) % MOD;
    }
}
int getFact(int n)
{
    if (n > knownFn)
    {
        calculateFact(n);
        knownFn = n;
    }
    return factOf[n];
}

int main()
{
    int T;
    factOf[0] = 1;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int ans = getFact(n) * inv(getFact(k)) % MOD * inv(getFact(n - k)) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
