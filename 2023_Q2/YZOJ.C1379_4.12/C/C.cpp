// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    int n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        if (m > 30)
            m = 30;
        long long sum = 0;
        while (n > 0)
        {
            int t = (1 << m);
            if (t <= n)
            {
                n -= t;
                sum++;
            }
            else
            {
                m--;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
