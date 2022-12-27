//Score: 94/100
#include <bits/stdc++.h>
using namespace std;
long long fup = 1, fdown = 0;

void flip()
{
    long long t = fup;
    fup = fdown;
    fdown = t;
}

void res(long long &a, long long &b)
{
    long long g = __gcd(a, b);
    a /= g;
    b /= g;
}

int main()
{
    long long p, q;
    int n;
    int a[92];
    scanf("%lld%lld%d", &p, &q, &n);
    res(p, q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        flip();
        fup += fdown * a[i];
    }
    res(fup, fdown);
    printf(p == fup && q == fdown ? "YES\n" : "NO\n");
    return 0;
}
