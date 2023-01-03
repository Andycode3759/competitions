// Score:0/100
// TLE
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int price[MAXN];
int stProfit[MAXN][21], stMax[MAXN][21], stMin[MAXN][21];
// st[i][j] => 从i号城市到i+2^j-1号城市（共2^j个）最多能赚多少钱
int log2of[MAXN];

void calcLog()
{
    log2of[1] = 0;
    log2of[2] = 1;
    for (int i = 3; i < MAXN; i++)
    {
        log2of[i] = log2of[i / 2] + 1;
    }
}
long long tick = 0;
int main()
{
    calcLog();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &price[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        int rbound = min(n, i + (1 << j) - 1);
        int pMax = -1;
        int pMin = price[i];
        int v = 0;
        for (int t = i; t <= n; t++)
        {
            v = max(v, price[t] - pMin);
            pMin = min(pMin, price[t]);
            pMax = max(pMax, price[t]);
            if (t == rbound)
            {
                stProfit[i][j] = v;
                stMax[i][j] = pMax;
                stMin[i][j] = pMin;
                // printf("%d -> %d: %d\n", i, rbound, stProfit[i][j]);
                j++;
                rbound = min(n, i + (1 << j) - 1);
            }
            tick++;
        }
    }
    // printf("preload ticks: %lld\n", tick);
    for (int q = 0; q < m; q++)
    {
        int from, to, ans;
        scanf("%d%d", &from, &to);

        if (to - from == 1)
        {
            printf("%d\n", max(0, price[to] - price[from]));
            continue;
        }

        int log2ofLen = log2of[to - from + 1];
        int rangel = to - (1 << log2ofLen) + 1;

        // printf("[%d,%d] + [%d,%d] -> [%d,%d]\n", from, from + (1 << log2ofLen) - 1, rangel,
        //        rangel + (1 << log2ofLen) - 1, from, to);

        ans = max(stProfit[from][log2ofLen], stProfit[rangel][log2ofLen]);
        ans = max(ans, stMax[rangel][log2ofLen] - stMin[from][log2ofLen]);
        printf("%d\n", ans);
    }
    return 0;
}
