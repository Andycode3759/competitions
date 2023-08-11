#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int MAXN = 100005;

struct Item
{
    int val, wei;
};
Item it[MAXN];

int n, q;

long long dp[MAXN];

long long doTheKnapsack(int u, int l)
{
    for (int i = 0; i < MAXN; i++)
        dp[i] = 0;

    while (u != 0)
    {
        for (int i = l; i >= it[u].wei; i--)
        {
            dp[i] = max(dp[i], dp[i - it[u].wei] + it[u].val);
        }
        u /= 2;
    }
    return dp[l];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &it[i].val, &it[i].wei);
    }
    scanf("%d", &q);
    while (q--)
    {
        int u, l;
        scanf("%d %d", &u, &l);
        printf("%lld\n", doTheKnapsack(u, l));
    }
    return 0;
}