// Score:0/100
// TLE
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int price[MAXN];
int log2of[MAXN];

struct STNode
{
    int min, max, profit;
};
STNode st[MAXN][21];

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
    // preload
    for (int i = 1; i <= n; i++)
    {
        st[i][0].min = price[i];
        st[i][0].max = price[i];
        st[i][0].profit = 0;
    }
    for (int j = 1; j <= log2of[MAXN - 1]; j++)
    {
        int len = 1 << j;
        if (len > n)
            break;
        for (int i = 1; i + len - 1 <= n; i++)
        { // max(l,r)=max(max(l,(l+r)/2),max())
            int rbound = i + (1 << j - 1);
            st[i][j].max = max(st[i][j - 1].max, st[rbound][j - 1].max);
            st[i][j].min = min(st[i][j - 1].min, st[rbound][j - 1].min);
            st[i][j].profit = max(st[i][j - 1].profit, st[rbound][j - 1].profit);
            st[i][j].profit = max(st[i][j].profit, st[rbound][j - 1].max - st[i][j - 1].min);

            printf("[%d,%d]: min=%d max=%d profit=%d\n", i, i + len - 1, st[i][j].min, st[i][j].max, st[i][j].profit);
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
        // l+2^s-1 => 'j' = s
        //
        int rangel = to - (1 << log2ofLen) + 1;

        printf("[%d,%d] + [%d,%d] -> [%d,%d]\n", from, from + (1 << log2ofLen) - 1, rangel,
               rangel + (1 << log2ofLen) - 1, from, to);

        //?

        printf("%d\n", ans);
    }
    return 0;
}
