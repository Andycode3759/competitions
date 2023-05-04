// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int piles[MAXN];

int minCost[MAXN][MAXN]; // 将[i,j]堆的石子合并所需的最小代价
int sum[MAXN][MAXN];     // [i,j]堆石子的重量和

void init(int n)
{
    memset(minCost, -1, sizeof(minCost));
    for (int i = 1; i <= n; i++)
        minCost[i][i] = 0;
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

    int ans = (1 << 31) - 1;
    for (int k = left; k < right; k++)
    {
        ans = min(ans, getMinCost(left, k) + getMinCost(k + 1, right) + sum[left][right]);
    }
    return minCost[left][right] = ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", piles + i);
        sum[1][i] = sum[1][i - 1] + piles[i];
    }
    init(n);

    printf("%d\n", getMinCost(1, n));

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
