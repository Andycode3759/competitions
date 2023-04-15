// TLE
// -56%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int n, q, s, t;
long long peak[MAXN];
long long peakDelta[MAXN];

long long getTemp()
{
    long long temp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (peakDelta[i] > 0)
        {
            temp -= peakDelta[i] * s;
        }
        if (peakDelta[i] < 0)
        {
            temp -= peakDelta[i] * t;
        }
    }
    return temp;
}

int main()
{
    scanf("%d%d%d%d", &n, &q, &s, &t);
    for (int i = 0; i <= n; i++)
    {
        scanf("%lld", peak + i);
        if (i > 0)
        {
            peakDelta[i] = peak[i] - peak[i - 1];
        }
    }
    while (q--)
    {
        int l, r;
        long long x;
        scanf("%d%d%lld", &l, &r, &x);
        peakDelta[l] += x;
        peakDelta[r + 1] -= x;
        printf("%lld\n", getTemp());
    }
    return 0;
}
