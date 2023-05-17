#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;

struct Rain
{
    int l, r, val;
};

int n, m, k;
int sta[MAXN];
int goal[MAXN];
Rain rains[MAXN];
int ans[MAXN];

int got[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", sta + i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", goal + i);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &rains[i].l, &rains[i].r, &rains[i].val);
    }

    for (int i = 1; i <= k; i++)
    {
        Rain &r = rains[i];
        int c = r.l;
        while (true)
        {
            got[c] += r.val;
            c++;
            if (c > m)
                c = 1;
            if (c == r.r)
                break;
        }
        for (int i = 1; i <= m; i++)
        {
        }
        printf("%d\n", ans[i]);
    }
    return 0;
}
