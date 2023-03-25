// WA -20%
#include <bits/stdc++.h>
using namespace std;

long long llCeil(long long a, long long b)
{
    return (a + b - 1) / b;
}

int main()
{
    long long n, m, h, a;
    scanf("%lld%lld%lld%lld", &n, &m, &h, &a);

    long long ans = llCeil(n, a) * llCeil(m, a) * llCeil(h, a);

    printf("%lld\n", ans);
    return 0;
}
