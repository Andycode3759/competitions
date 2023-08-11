#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 303;

struct Shop
{
    int cost, val, time;
};
Shop sh[MAXN];

int n, m;

int dp[MAXN];
int doTheKnapsack(int t, int w)
{
    for (int i = 1; i <= w; i++)
        dp[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        Shop &s = sh[i];
        if (t < s.time)
            continue;
        for (int j = w; j >= s.cost; j--)
        {
            dp[j] = max(dp[j], dp[j - s.cost] + s.val);
        }
    }
    return dp[w];
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &sh[i].cost, &sh[i].val, &sh[i].time);
    }
    for (int i = 1; i <= m; i++)
    {
        int tm, money;
        scanf("%d %d", &tm, &money);
        printf("%d\n", doTheKnapsack(tm, money));
    }

    return 0;
}