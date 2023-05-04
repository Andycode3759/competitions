// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202;
const int MAXK = 32;
const int INF = (1 << 31) - 1;
const char MSG_ANS[] = "Depot %d at restaurant %d serves restaurants %d";
const char MSG_SUM[] = "Total distance sum = %d\n";

// minSum[x][y][k] => 对于第x到第y家店，建k个厂得到的最小距离和
int minSum[MAXN][MAXN][MAXK];
// 每家McBurger的坐标
int pos[MAXN];

int getMinSum(int left, int right, int fact)
{
    if (minSum[left][right][fact] >= 0)
        return minSum[left][right][fact];
    int &ans = minSum[left][right][fact];

    if (fact == 1)
    {
        int mid = (right + left) / 2;
        ans = 0;
        for (int i = left; i <= right; i++)
        {
            ans += abs(pos[i] - pos[mid]);
        }
        return ans;
    }

    ans = INF;
    for (int rangeCut = left; rangeCut < right; rangeCut++)
    {
        }
    return ans;
}

int main()
{
    // McBurger数量
    int n;
    // 供应厂数量
    int k;
    // 数据组计数器
    int chain = 1;

    while (scanf("%d%d", &n, &k) == 2 && n != 0 && k != 0)
    {
        memset(pos, 0, sizeof(pos));
        memset(minSum, -1, sizeof(minSum));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", pos + i);
        }
        printf(MSG_SUM, getMinSum(1, n, k));
        chain++;
    }
    return 0;
}
