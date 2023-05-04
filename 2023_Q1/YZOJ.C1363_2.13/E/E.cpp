// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 104;
const int INF = (1 << 31) - 1;
int diaosi[MAXN];
int anger[MAXN][MAXN]; // anger[i][j] => 第i个人到第j个人的最小怒气值

int getAnger(int left, int right)
{
    if (anger[left][right] >= 0)
        return anger[left][right];
    int &ans = anger[left][right];

    ans = INF;
    for (int k = left; k < right; k++) // 让left第k个上场
    {
        /*
            [left,k-1]:
            k: diaosi[left]
        */
        ans = min();
    }

    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        int n;
        scanf("%d", &n);
        for (int i = i; i <= n; i++)
        {
            scanf("%d", diaosi + i);
        }
        memset(anger, -1, sizeof(anger));
        printf("Case #%d: %d\n", kase, getAnger(1, n));
    }
    return 0;
}
