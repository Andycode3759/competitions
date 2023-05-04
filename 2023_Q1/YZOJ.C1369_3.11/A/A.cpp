#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    long long ans = 0;
    int tenied = 10;
    for (; tenied <= b; tenied *= 10)
    {
        if (tenied - 1 <= b)
            ans += a;
    }
    printf("%lld\n", ans);
    return 0;
}
