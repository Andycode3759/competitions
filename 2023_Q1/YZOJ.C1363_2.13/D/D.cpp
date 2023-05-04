// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 104;
const int INF = (1 << 31) - 1;
char strA[MAXN], strB[MAXN];
int cost[MAXN][MAXN]; // cost[i][j] => 从i到j，从空白串画成B需要的最小次数
int realAns[MAXN];

int getCostFromBlank(int left, int right)
{
    if (cost[left][right] >= 0)
        return cost[left][right];
    int &ans = cost[left][right];

    if (left == right)
    {
        // return ans = (strA[left] == strB[left] ? 0 : 1);
        return 1;
    }
    // if (strA[right] == strB[right])
    // {
    //     return ans = getCostFromBlank(left, right - 1);
    // }
    if (strB[left] == strB[right])
    {
        return ans = getCostFromBlank(left + 1, right);
    }
    ans = INF;
    for (int k = left; k < right; k++)
    {
        ans = min(ans, getCostFromBlank(left, k) + getCostFromBlank(k + 1, right));
    }

    return ans;
}

int main()
{
    while (scanf("%s%s", strA + 1, strB + 1) == 2)
    {
        int len = strlen(strA + 1);

        // printf("len=%d\n", len);

        memset(cost, -1, sizeof(cost));
        memset(realAns, 0, sizeof(realAns));
        for (int i = 1; i <= len; i++)
        {
            realAns[i] = getCostFromBlank(1, i);
        }
        for (int i = 1; i <= len; i++)
        {
            if (strA[i] == strB[i])
            {
                realAns[i] = realAns[i - 1];
            }
            else
            {
                for (int k = 1; k < i; k++)
                {
                    realAns[i] = min(realAns[i], realAns[k] + getCostFromBlank(k + 1, i));
                }
            }
        }
        // getCostFromBlank(1, len);
        printf("%d\n", realAns[len]);
    }
    return 0;
}
