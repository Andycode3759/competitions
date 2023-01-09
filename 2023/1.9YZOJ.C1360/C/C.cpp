// ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const int WARN = 1e9;

int main()
{
    int a, b;
    long long ans = 1;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < b; i++)
    {
        ans *= a;
        if (ans < 0 || ans > WARN)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
