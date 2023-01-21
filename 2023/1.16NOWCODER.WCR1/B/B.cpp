//TLE
#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 44;
int n, m, x, y;
int ans;
struct Match
{
    Match(int s = 0, int c = 0)
    {
        self = s;
        comp = c;
    }

    int self, comp;
} states[MAXN];

void dfs(int round, int selfRemain, int compRemain, int score)
{
    if (round > n)
    {
        if (score >= m)
            ans++;
        ans %= MOD;
        return;
    }
    if (round == n) // last round
    {
        states[round].self = selfRemain;
        states[round].comp = compRemain;
        if (selfRemain > compRemain)
            score += 3;
        else if (selfRemain == compRemain)
            score += 1;
        dfs(round + 1, 0, 0, score);
        return;
    }
    for (int i = selfRemain; i >= 0; i--)
    {
        for (int j = compRemain; j >= 0; j--)
        {
            states[round].self = i;
            states[round].comp = j;
            if (i > j)
                score += 3;
            else if (i == j)
                score += 1;
            dfs(round + 1, selfRemain - i, compRemain - j, score);
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    dfs(1, x, y, 0);
    printf("%d\n", ans);
    return 0;
}