// WA 100%
// 开摆
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 13;
const int INF = (1 << 30) + 1;
int cost[MAXN][MAXN];
int minCostFrom[MAXN][1 << MAXN]; // 从i点出发，已经过点状态为state的最小花费
// bit => 1为走过，0为没走过
int n;

int getMinCostFrom(int start, int state, int stackNum)
{
    int &ans = minCostFrom[start][state];
    if (ans >= 0)
        return ans;

    // printf("stack #%d (start=%d, state=%d) start\n", stackNum, start, state);

    if (state >= (1 << n) - 1)
    {
        // printf("stack #%d end: %d\n", stackNum, cost[start][0]);
        return ans = cost[start][0];
    }

    ans = INF;
    for (int i = 1; i <= n; i++)
    {
        if (i == start)
            continue;
        int next = 1 << (i - 1);
        int res = getMinCostFrom(i, state | next, stackNum + 1) + cost[start][i];
        if (res < ans)
        {
            // printf("stack #%d updated ans: %d->%d\n", stackNum, ans, res);
            ans = res;
        }
    }
    // printf("stack #%d end: %d\n", stackNum, ans);
    return ans;
}

int main()
{
    while (scanf("%d", &n) == 1 && n != 0)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                scanf("%d", &cost[i][j]);
            }
        }
        memset(minCostFrom, -1, sizeof(minCostFrom));
        printf("%d\n", getMinCostFrom(0, 0, 0));
    }
    return 0;
}
