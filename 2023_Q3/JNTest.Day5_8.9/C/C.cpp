#include <cstdio>
#include <cstring>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 102;

constexpr long long quickPow(long long a, int x)
{
    long long res = 1;
    for (; x > 0; x = (x >> 1), a = (1LL * a * a) % MOD)
    {
        if ((x & 1) == 1)
            res = (1LL * res * a) % MOD;
    }
    return res;
}

bool g[MAXN][MAXN], g2[MAXN][MAXN], g3[MAXN][MAXN];

int mem[MAXN][MAXN];

int n, m;
void Floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g2[i][j] = g2[i][j] || (i != j && g2[i][k] && g2[k][j]);
}
void AttackedFloyd()
{
    for (int k = 1; k <= n - m; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g3[i][j] = g3[i][j] || (i != j && g3[i][k] && g3[k][j]);
}

int dfs(int x, int y)
{
    if (x == n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g2[i][j] = g[i][j];
                g3[i][j] = g[i][j];
            }
        }
        Floyd();
        AttackedFloyd();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g2[i][j] != g3[i][j])
                    return 0;
            }
        }
        return 1;
    }
    int res = 0;
    g[x][y] = g[y][x] = true;
    res = (res + (y == n ? dfs(x + 1, x + 2) : dfs(x, y + 1))) % MOD;
    g[x][y] = g[y][x] = false;
    res = (res + (y == n ? dfs(x + 1, x + 2) : dfs(x, y + 1))) % MOD;
    return res;
}

int main()
{
    memset(mem, -1, sizeof mem);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &m);
        if (mem[n][m] >= 0)
            printf("%d\n", mem[n][m]);
        else
        {
            if (m == 0)
            {
                printf("%d\n", mem[n][m] = quickPow(2, n * (n - 1) / 2));
            }
            else
                printf("%d\n", mem[n][m] = dfs(1, 2));
        }
    }
    return 0;
}