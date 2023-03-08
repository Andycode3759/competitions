// AC
// Fixed on 1.9 20:56
#include <bits/stdc++.h>
using namespace std;
const int MAXP = 1e6 + 6;
bool isPrime[MAXP];
bool book[MAXP];

void calcPrimes()
{
    int currentPrime = 2;
    while (currentPrime < MAXP)
    {
        isPrime[currentPrime] = true;
        for (int i = 2; i * currentPrime < MAXP; i++)
        {
            book[i * currentPrime] = true;
        }
        do
            currentPrime++;
        while (book[currentPrime] && currentPrime < MAXP);
    }
}

int main()
{
    calcPrimes();
    long long n;
    scanf("%lld", &n);

    long long maxq = (long long)(pow(n / 2.0, 1.0 / 3) + 1);
    // printf("maxq=%lld\n", maxq);
    long long ans = 0;
    for (long long q = 3; q <= maxq; q++)
    {
        if (!isPrime[q])
            continue;
        long long qcube = q * q * q;
        for (long long p = 2; p < q; p++)
        {
            // if(q%p==0) continue;
            // printf("isPrime(%lld)=%d isPrime(%lld)=%d\n", p, isPrime[p], q, isPrime[q]);
            if (isPrime[p])
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
