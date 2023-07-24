#include <bitset>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 200005;
const int DIR[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, q;
// int stateRow[MAXN][MAXN], stateCol[MAXN][MAXN];
// int colAt[MAXN][MAXN], lvAt[MAXN][MAXN];
int **stateRow, **stateCol, **colAt, **lvAt;
bool **vis, **ok;

inline void clearData()
{
    if (m == 0 && n == 0)
        return;
    for (int i = 0; i <= n + 2; i++)
    {
        delete stateRow[i];
        delete stateCol[i];
        delete colAt[i];
        delete lvAt[i];
        delete vis[i];
        delete ok[i];
    }
    delete stateRow;
    delete stateCol;
    delete colAt;
    delete lvAt;
    delete vis;
    delete ok;
}
inline void init()
{
    stateRow = new int *[n + 3];
    stateCol = new int *[n + 3];
    colAt = new int *[n + 3];
    lvAt = new int *[n + 3];
    vis = new bool *[n + 3];
    ok = new bool *[n + 3];
    for (int i = 0; i <= n + 2; i++)
    {
        stateRow[i] = new int[m + 5];
        stateCol[i] = new int[m + 5];
        colAt[i] = new int[m + 5];
        lvAt[i] = new int[m + 5];
        vis[i] = new bool[m + 5];
        ok[i] = new bool[m + 5];
        memset(stateRow[i], 0, sizeof(int) * (m + 2));
        memset(stateCol[i], 0, sizeof(int) * (m + 2));
        memset(colAt[i], -1, sizeof(int) * (m + 2));
        memset(lvAt[i], 0, sizeof(int) * (m + 2));
        memset(vis[i], 0, sizeof(bool) * (m + 2));
        memset(ok[i], 0, sizeof(bool) * (m + 2));
    }
}

void dfs(int x, int y, int state, int col, int lv, int nrmLeft, int lstDir)
{
    ok[x][y] = true;
    if (nrmLeft == 0 || colAt[x][y] == (col ^ 1))
        return;
    for (int d = 0; d < 4; d++)
    {
        int dx = x + DIR[d][0];
        int dy = y + DIR[d][1];
        int ns;
        switch (d)
        {
        case 0:
            ns = stateCol[x][y];
            break;
        case 1:
            ns = stateCol[dx][y];
            break;
        case 2:
            ns = stateRow[x][y];
            break;
        case 3:
            ns = stateRow[x][dy];
            break;
        }

        // printf("(%d,%d) -> (%d,%d) s=%d ns=%d d=%d lstDir=%d\n", x, y, dx, dy, state, ns, d, lstDir);

        if (dx <= 0 || dy <= 0 || dx > n || dy > m || vis[dx][dy] || ns == 0 || colAt[dx][dy] == col ||
            lv < lvAt[dx][dy])
            continue;
        if (state == -1 || state == ns)
        {
            if (ns == 1)
            {
                vis[dx][dy] = true;
                dfs(dx, dy, ns, col, lv, nrmLeft - 1, d);
                vis[dx][dy] = false;
            }
            if (ns == 2 && (lstDir == -1 || d == lstDir))
            {
                vis[dx][dy] = true;
                dfs(dx, dy, ns, col, lv, nrmLeft, d);
                vis[dx][dy] = false;
            }
            if (ns == 3)
            {
                vis[dx][dy] = true;
                dfs(dx, dy, ns, col, lv, nrmLeft, d);
                vis[dx][dy] = false;
            }
        }
    }
}

inline void clearState(bool **dest)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dest[i][j] = false;
        }
    }
}

int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        clearData();
        scanf("%d%d%d", &n, &m, &q);
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m - 1; j++)
            {
                scanf("%1d", &stateRow[i][j]);
            }
        }
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%1d", &stateCol[i][j]);
            }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m - 1; j++)
        //     {
        //         printf(". %d ", stateRow[i][j]);
        //     }
        //     printf(".\n");
        //     if (i < n)
        //     {
        //         for (int j = 1; j <= m; j++)
        //         {
        //             printf("%d   ", stateCol[i][j]);
        //         }
        //         printf("\n");
        //     }
        // }

        int col, lv, x, y;
        // do stuff
        while (q--)
        {
            scanf("%d%d%d%d", &col, &lv, &x, &y);
            int ans = 0;
            clearState(ok);
            lvAt[x][y] = lv;
            colAt[x][y] = col;

            clearState(vis);
            vis[x][y] = true;
            dfs(x, y, -1, col, lv, 1, -1);
            ok[x][y] = false;

            // printf("%4s", "ok");
            // for (int j = 1; j <= m; j++)
            // {
            //     printf("%4d", j);
            // }
            // printf("\n");

            for (int i = 1; i <= n; i++)
            {
                // printf("%4d", i);
                for (int j = 1; j <= m; j++)
                {
                    // printf("%4d", ok[i][j]);
                    if (ok[i][j])
                        ans++;
                }
                // printf("\n");
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
