#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
using pii = pair<int, int>;
constexpr int MAXN = 300005;
constexpr int MOD = 1e9 + 7;

constexpr long long quickPow(long long a, int x)
{
    long long res = 1;
    for (; x > 0; x = (x >> 1), a = (1LL * a * a) % MOD)
    {
        if ((x & 1) == 1)
            res = (1LL * res * a) % MOD;
    }
    return res;
}

int n, m;
pii pairs[MAXN];

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b)
            swap(a, b);
        b--;
        pairs[i].first = a, pairs[i].second = b;
    }
    sort(pairs + 1, pairs + 1 + m);

    pii curSeg = pairs[1];
    int tot = 1, lft = n - 1;
    for (int i = 2; i <= m; i++)
    {
        if (curSeg.first <= pairs[i].first && pairs[i].first <= curSeg.second)
        {
            curSeg.second = max(curSeg.second, pairs[i].second);
        }
        else
        {
            tot++;
            lft -= curSeg.second - curSeg.first + 1;
            curSeg = pairs[i];
        }
    }
    lft -= curSeg.second - curSeg.first + 1;

    printf("%lld\n", quickPow(2, tot + lft));
    return 0;
}