// AC
// Fixed: 2023/5/3
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;

int n;
struct Stone
{
    int x, y;
};
Stone stones[MAXN];
bool vis[MAXN];

struct StoneCmpY
{
    const bool operator()(const Stone &a, const Stone &b) const
    {
        return a.y < b.y;
    }
};
struct StoneCmp
{
    const bool operator()(const Stone &a, const Stone &b) const
    {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    }
};

void solveSP1()
{
    printf("Yes\n");
    sort(stones + 1, stones + 1 + n, StoneCmpY());
    for (int i = 1; i < n; i += 2)
    {
        printf("%d %d %d %d\n", stones[i].x, stones[i].y, stones[i + 1].x, stones[i + 1].y);
    }
}
void solveSP2()
{
    printf("Yes\n");
    sort(stones + 1, stones + 1 + n, StoneCmpY());
    for (int i = 1; i < n; i += 2)
    {
        printf("0 %d %d %d\n", stones[i].y, stones[i + 1].y - stones[i].y, stones[i + 1].y);
    }
}
void solveGeneral()
{
    printf("Yes\n");
    sort(stones + 1, stones + 1 + n, StoneCmp());
    for (int x = n; x >= 1;)
    {
        if (vis[x])
        {
            --x;
            continue;
        }
        int y = x - 1;
        while (vis[y])
            --y;
        Stone &sx = stones[x], &sy = stones[y];

        if (sx.x == sy.x)
        {
            printf("%d %d %d %d\n", sx.x, sx.y, sx.x + sx.y - sy.y, sy.y);
            vis[x] = true;
            vis[y] = true;
        }
        else if (sx.y >= sy.y)
        {
            int len = max(sx.x - sy.x, sx.y - sy.y);
            printf("%d %d %d %d\n", sy.x, sy.y, sy.x + len, sy.y + len);
            vis[x] = true;
            vis[y] = true;
        }
        else
        {
            int z = y - 1;
            Stone &sz = stones[z];
            if (z == 0 || sz.x < sy.x || sz.y < sx.y)
            {
                // Z可能不存在
                int len = max(sx.x - sy.x, sy.y - sx.y);
                printf("%d %d %d %d\n", sy.x, sx.y, sy.x + len, sx.y + len);
                vis[x] = true;
                vis[y] = true;
            }
            else if (sz.y > sx.y)
            {
                printf("%d %d %d %d\n", sz.x, sz.y, sz.x + (sy.y - sz.y), sy.y);
                vis[z] = true;
                vis[y] = true;
            }
            else if (sy.y - sz.y <= sx.x - sz.x)
            {
                printf("%.2lf %d %.2lf %d\n", sy.x - 0.5, sy.y, sy.x - 0.5 + sy.y - sz.y, sz.y);
                vis[y] = true;
                vis[z] = true;
            }
            else
            {
                printf("%d %d %d %d\n", sz.x, sz.y, sx.x, sz.y + (sx.x - sz.x));
                vis[x] = true;
                vis[z] = true;
            }
        }
    }
}

int main()
{
    // freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, false, sizeof(vis));
        bool sp1 = true, sp2 = true;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            stones[i].x = x;
            stones[i].y = y;
            if (x != y)
                sp1 = false;
            if (x != 0)
                sp2 = false;
        }
        if (sp1)
        {
            solveSP1();
            continue;
        }
        if (sp2)
        {
            solveSP2();
            continue;
        }
        solveGeneral();
    }
    return 0;
}
