// ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;
int cows[MAXN];
int log2of[MAXN];

struct STNode
{
    int min, max;
} st[MAXN][16];

void calcLog()
{
    log2of[1] = 0;
    log2of[2] = 1;
    for (int i = 3; i < MAXN; i++)
    {
        log2of[i] = log2of[i / 2] + 1;
    }
}

int main()
{
    calcLog();
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cows[i]);
    }

    // preload
    for (int i = 1; i <= n; i++)
    {
        st[i][0].min = cows[i];
        st[i][0].max = cows[i];
    }
    for (int j = 1, len = 2; len <= n; j++, len = 1 << j)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        { // max(l,r)=max(max(l,(l+r)/2),max())
            int rbound = i + (1 << j - 1);
            st[i][j].max = max(st[i][j - 1].max, st[rbound][j - 1].max);
            st[i][j].min = min(st[i][j - 1].min, st[rbound][j - 1].min);

            // printf("[%d,%d]: min=%d max=%d\n", i, i + len - 1, st[i][j].min, st[i][j].max);
        }
    }

    // requests
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int logOfLen = log2of[r - l + 1];
        int stLen = 1 << logOfLen;
        int ansMin = min(st[l][logOfLen].min, st[r - stLen + 1][logOfLen].min);
        int ansMax = max(st[l][logOfLen].max, st[r - stLen + 1][logOfLen].max);
        printf("%d\n", ansMax - ansMin);
    }

    return 0;
}
