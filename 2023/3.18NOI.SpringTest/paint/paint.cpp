// 100%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

struct Operate
{
    Operate(int _c, int _z)
    {
        color = _c;
        zidx = _z;
    }
    int color;
    int zidx;
};
vector<Operate> opts; // 所有操作
int affectRow[MAXN];  // 最后一次影响到第i行的操作下标
int affectCol[MAXN];  // 最后一次影响到第i列的操作下标

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        vector<Operate>().swap(opts);
        memset(affectRow, -1, sizeof(affectRow));
        memset(affectCol, -1, sizeof(affectCol));
        int n, m, q;
        // n行m列
        scanf("%d%d%d", &n, &m, &q);

        int opt, x, c;
        // opt=0 行
        // opt=1 列
        for (int j = 0; j < q; j++)
        {
            scanf("%d%d%d", &opt, &x, &c);
            opts.push_back(Operate(c, j));
            if (opt == 0)
            {
                affectRow[x] = opts.size() - 1;
            }
            if (opt == 1)
            {
                affectCol[x] = opts.size() - 1;
            }
        }

        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= m; y++)
            {
                // 第x行第y列
                // 最后一次影响x行的操作和最后一次影响y行的操作比较z index
                Operate r = affectRow[x] < 0 ? Operate(0, -1) : opts[affectRow[x]];
                Operate c = affectCol[y] < 0 ? Operate(0, -1) : opts[affectCol[y]];
                int ans = r.zidx > c.zidx ? r.color : c.color;
                printf("%d ", ans);
            }
            printf("\n");
        }
    }
    return 0;
}
