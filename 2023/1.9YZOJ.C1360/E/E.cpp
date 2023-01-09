// Score: 0/100
// TLE
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    long long maxi = (long long)sqrt((double)n);
    for (long long i = 2; i <= maxi; i++)
    {
        if (n % maxi == 0)
            return false;
    }
    return true;
}

int main()
{
    long long n;
    scanf("%lld", &n);

    long long maxq = (long long)pow(n / 2.0, 1.0 / 3);
    // printf("%lld",maxq);
    long long ans = 0;
    for (long long q = 3; q <= maxq; q++)
    {
        if (!isPrime(q))
            continue;
        long long maxp = min((long long)(n * 1.0 / (q * q * q)) + 1, q);
        long long qcube = q * q * q;
        for (long long p = 2; p < maxp; p++)
        {
            // if(q%p==0) continue;
            // printf("isPrime(%lld)=%d isPrime(%lld)=%d\n",p,isPrime(p),q,isPrime(q));
            if (isPrime(p))
            {
                if (p * qcube <= n)
                    ans++;
                else
                    break;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
