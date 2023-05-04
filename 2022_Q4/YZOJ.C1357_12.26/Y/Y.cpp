// AC
#include <bits/stdc++.h>
using namespace std;

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
    y = xt - q * x;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    long long x, y;
    exgcd(a, b, x, y);
    printf("%lld\n", (x + b) % b);
    return 0;
}
