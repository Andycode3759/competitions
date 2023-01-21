// TLE
#include <bits/stdc++.h>
using namespace std;
const int MAXM = 4e5 + 5;
const int MOD = 998244353;

struct Range
{
    int left, right;

    int getCon(Range another, int n)
    {
        int revL2 = n - another.right, revR2 = n - another.left;
        int tl = max(left, revL2), tr = min(right, revR2);
        return max(0, tr - tl + 1);
    }

} ranges[MAXM];

int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int main()
{
    int n = read(), m = read();
    for (int i = 0; i < m; i++)
    {
        ranges[i].left = read();
        ranges[i].right = read();
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            ans = (ans + 1LL * ranges[i].getCon(ranges[j], n)) % MOD;
        }
    }
    ans = ans * 2LL % MOD;
    printf("%lld\n", ans);
    return 0;
}
