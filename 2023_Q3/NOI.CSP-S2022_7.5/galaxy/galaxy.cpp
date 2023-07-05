#include <cstdio>
using namespace std;
const int MAXN = 1003;

bool graph[MAXN][MAXN];
int outCnt[MAXN];
int n, m, q;
bool vis[MAXN];

bool dfs(int x)
{
    if (vis[x])
        return true;
    vis[x] = true;
    for (int i = 1; i <= n; i++)
    {
        if (graph[x][i] && dfs(i))
            return true;
    }
    return false;
}

int main()
{
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);

    scanf("%d%d", &n, &m);
    int op, u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        graph[u][v] = true;
        outCnt[u]++;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &op);
        if (op == 1 || op == 3)
        {
            scanf("%d%d", &u, &v);
            if (op == 1)
                graph[u][v] = false, outCnt[u]--;
            else // op == 3
                graph[u][v] = true, outCnt[u]++;
        }
        else
        {
            scanf("%d", &u);
            if (op == 2)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (graph[i][u])
                        outCnt[i]--;
                    graph[i][u] = false;
                }
            }
            else // op == 4
            {
                for (int i = 1; i <= n; i++)
                {
                    if (!graph[i][u])
                        outCnt[i]++;
                    graph[i][u] = true;
                }
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (outCnt[i] != 1)
            {
                printf("NO\n");
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        for (int i = 1; i <= n; i++)
            vis[i] = false;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            if (!dfs(i))
            {
                printf("NO\n");
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        printf("YES\n");
    }
    return 0;
}
