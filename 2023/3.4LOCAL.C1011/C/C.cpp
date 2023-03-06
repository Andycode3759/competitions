// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 13;
const int MOD = 1e8;

int soilStates[MAXN];
int planCount[MAXN][1 << MAXN];
int m, n;

int lowbit(int x)
{
    return x & (-x);
}

bool checkRow(int state)
{
    while (state)
    {
        int l1 = lowbit(state);
        if (l1 == state)
            break;
        int l2 = lowbit(state - l1);
        if (l1 << 1 == l2)
            return false;
        state -= l1;
    }
    return true;
}
bool checkMatch(int state1, int state2)
{
    return (state1 | state2) == (state1 + state2);
}
bool checkValid(int stateSoil, int statePlan)
{
    return (stateSoil & statePlan) == statePlan;
}

int getPlanCount(int row, int state)
{
    if (row == 0)
        return 1;
    int &ans = planCount[row][state];
    if (ans >= 0)
        return ans;

    ans = 0;
    for (int s = 0; s < (1 << n); s++) // s => 前一行的状态
    {
        if (!checkRow(s) || !checkMatch(state, s) || !checkValid(soilStates[row - 1], s))
            continue;
        ans += getPlanCount(row - 1, s);
    }
    return ans;
}

int main()
{
    memset(planCount, -1, sizeof(planCount));
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        int s = 0, input;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &input);
            s = (s + input) << 1;
        }
        soilStates[i] = s;
    }
    int ans = 0;
    for (int s = 0; s < (1 << n); s++)
    {
        if (!checkRow(s) || !checkValid(soilStates[m], s))
            continue;
        ans += getPlanCount(m, s);
    }
    printf("%d\n", ans);
    return 0;
}
