// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202;
const int INF = (1 << 31) - 1;
int piles[MAXN];

int minCost[2 * MAXN][2 * MAXN]; // 将[i,j]堆的石子合并所需的最小代价
int maxCost[2 * MAXN][2 * MAXN];
int sum[2 * MAXN][2 * MAXN]; // [i,j]堆石子的重量和

void init(int n)
{
    memset(minCost, -1, sizeof(minCost));
    memset(maxCost, -1, sizeof(maxCost));
    for (int i = 1; i <= n; i++)
        maxCost[i][i] = minCost[i][i] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sum[i][j] = sum[1][j] - sum[1][i] + piles[i];
        }
    }
}

int getMinCost(int left, int right)
{
    if (minCost[left][right] >= 0)
        return minCost[left][right];

    int ans = INF;
    for (int k = left; k < right; k++)
    {
        ans = min(ans, getMinCost(left, k) + getMinCost(k + 1, right) + sum[left][right]);
    }
    return minCost[left][right] = ans;
}
int getMaxCost(int left, int right)
{
    if (maxCost[left][right] >= 0)
        return maxCost[left][right];

    int ans = -1;
    for (int k = left; k < right; k++)
    {
        ans = max(ans, getMaxCost(left, k) + getMaxCost(k + 1, right) + sum[left][right]);
    }
    return maxCost[left][right] = ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", piles + i);
        piles[i + n] = piles[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        sum[1][i] = sum[1][i - 1] + piles[i];
    }
    init(2 * n);

    int ansMin = INF, ansMax = -INF;
    for (int delta = 0; delta < n; delta++)
    {
        ansMin = min(ansMin, getMinCost(1 + delta, n + delta));
        ansMax = max(ansMax, getMaxCost(1 + delta, n + delta));
    }

    printf("%d\n%d\n", ansMin, ansMax);

    // debug start
    // for (int i = 0; i <= n; i++)
    // {
    //     if (i == 0)
    //     {
    //         printf("j/i ");
    //     }
    //     else
    //     {
    //         printf("%4d", i);
    //     }
    // }
    // printf("\n");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%4d", i);
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%4d", sum[i][j]);
    //     }
    //     printf("\n");
    // }
    // debug end

    return 0;
}
