#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int T;
long long n;
long long c;

long long getF(int i)
{
    return (1 << i) - 1;
}

long long getG(long long x)
{
    int bits = 0;
    while (x > 0)
    {
        x = x >> 1;
        bits++;
    }
    return getF(bits);
}

long long getDp(long long i)
{
    return (getG(i) + 1) / 2 - 1; //秒出
}

long long conv(string nbin)
{
    long long result = 0;
    for (int i = 0; i < nbin.size(); i++)
    {
        result = result << 1;
        if (nbin[i] == '1')
            result++;
    }
    return result;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    scanf("%d", &T);

    string nbin;
    for (int kase = 0; kase < T; kase++)
    {
        cin >> nbin >> c;
        n = conv(nbin);
        if (c % 2 == 0) //秒出
        {
            printf("0\n");
            continue;
        }
        long long sum = 0;
        for (long long i = 0; i <= n; i++)
        {
            sum += getDp(i);
            sum = sum % Mod;
        }
        printf("%lld\n", sum);
    }

    return 0;
}
