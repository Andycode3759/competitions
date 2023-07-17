#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MOD = 998244353;
const int MAXN = 1003;

struct Segment
{
    Segment(int _p, int _l, int _r) : p(_p), l(_l), r(_r)
    {
    }
    int p, l, r;
};
vector<Segment> rows, cols;

int id;
bool land[MAXN][MAXN];
int n, m, doC, doF;
char input[MAXN];

// inline int countC()
// {
//     if (doC == 0)
//         return 0;
//     int cntR = rows.size(), cntC = cols.size();
//     int res = 0;
//     // 2 rows + 1 col
//     for (int ra = 0; ra < cntR; ra++)
//     {
//         Segment &rowA = rows[ra];
//         for (int rb = ra + 1; rb < cntR; rb++)
//         {
//             Segment &rowB = rows[rb];
//             if (rowB.p - rowA.p <= 1 || rowA.r - rowB.l <= 0)
//                 continue;
//             for (int c = 0; c < cntC; c++)
//             {
//                 Segment &col = cols[c];
//                 if (col.p < rowA.l || col.p > rowA.r || col.p < rowB.l || col.p > rowB.r || col.r < rowB.p ||
//                     col.l > rowA.p)
//                     continue;
//                 res = (res + 1LL * (rowA.r - col.p) * (rowB.r - col.p)) % MOD;
//             }
//         }
//     }
//     return res;
// }
inline void solve()
{
    int cntR = rows.size(), cntC = cols.size();
    int resC = 0, resF = 0;
    // 2 rows + 1 col
    for (int ra = 0; ra < cntR; ra++)
    {
        Segment &rowA = rows[ra];
        for (int rb = ra + 1; rb < cntR; rb++)
        {
            Segment &rowB = rows[rb];
            if (rowB.p - rowA.p <= 1 || rowA.r - rowB.l <= 0)
                continue;
            for (int c = 0; c < cntC; c++)
            {
                Segment &col = cols[c];
                if (col.p < rowA.l || col.p > rowA.r || col.p < rowB.l || col.p > rowB.r || col.r < rowB.p ||
                    col.l > rowA.p)
                    continue;
                if (doC)
                    resC = (resC + 1LL * (rowA.r - col.p) * (rowB.r - col.p)) % MOD;
                if (doF)
                    resF = (resF + 1LL * (rowA.r - col.p) * (rowB.r - col.p) * (col.r - rowB.p)) % MOD;
            }
        }
    }
    printf("%d %d\n", resC, resF);
}

int main()
{
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);

    int T;
    scanf("%d%d", &T, &id);
    while (T--)
    {
        memset(land, false, sizeof land);
        rows.clear(), cols.clear();
        scanf("%d%d%d%d", &n, &m, &doC, &doF);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", input + 1);
            for (int j = 1; j <= m; j++)
                land[i][j] = input[j] == '1';
        }

        for (int i = 1; i <= n; i++)
        {
            int st = 1, len = 0;
            for (int j = 1; j <= m; j++)
            {
                if (land[i][j])
                {
                    if (len >= 2)
                        rows.push_back(Segment(i, st, j - 1));
                    st = j + 1;
                    len = 0;
                }
                else
                    len++;
            }
            if (len >= 2)
                rows.push_back(Segment(i, st, m));
        }
        for (int j = 1; j <= m; j++)
        {
            int st = 1, len = 0;
            for (int i = 1; i <= n; i++)
            {
                if (land[i][j])
                {
                    if (len >= 3)
                        cols.push_back(Segment(j, st, i - 1));
                    st = i + 1;
                    len = 0;
                }
                else
                    len++;
            }
            if (len >= 3)
                cols.push_back(Segment(j, st, n));
        }

        // for (int i = 0; i < rows.size(); i++)
        //     printf("row %d [%d,%d]\n", rows[i].p, rows[i].l, rows[i].r);
        // for (int i = 0; i < cols.size(); i++)
        //     printf("col %d [%d,%d]\n", cols[i].p, cols[i].l, cols[i].r);

        solve();
    }
    return 0;
}
