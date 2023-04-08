// TLE -10%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
typedef unsigned long long ull;

int n;
ull t;
ull songs[MAXN];

ull read()
{
    ull res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        songs[i] = read();
        // scanf("%llu", songs + i);
    }
    t = read();
    // scanf("%llu", &t);

    int i = 1;
    while (t > songs[i])
    {
        t -= songs[i];
        i++;
        if (i > n)
            i = 1;
    }

    printf("%d\n", i);
    return 0;
}
