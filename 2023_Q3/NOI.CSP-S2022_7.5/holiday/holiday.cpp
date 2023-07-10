// AC
// 但是Hack没过
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 2505;
const int MAXM = 10004;
const int INF = (1 << 30) - 1;

constexpr long long max(const long long &a, const long long &b)
{
    return a > b ? a : b;
}
inline int readInt()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}
inline long long readLL()
{
    long long res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int n, m, k;
long long score[MAXN];
int graph[MAXN][MAXN];
vector<int> outs1[MAXN], outs2[MAXN];
long long bestScore[6][MAXN]; // 第step步走在i点上时，目前能够获得的最大得分

long long ans = -1;

bool vis[MAXN];
inline void dfs(int cur, int step, long long sum)
{
    if (step > 4)
    {
        if (graph[cur][1] <= k + 1)
            ans = max(ans, sum);
        return;
    }
    if (sum < bestScore[step][cur])
        return;
    bestScore[step][cur] = sum;
    int len = outs2[cur].size();
    for (int i = 0; i < len; i++)
    {
        int v = outs2[cur][i];
        if (vis[v])
            continue;
        // for (int i = 1; i < step; i++)
        //     printf("  ");
        // printf("%d -> %d\n", cur, v);
        vis[v] = true;
        dfs(v, step + 1, sum + score[v]);
        vis[v] = false;
    }
}

inline void bfs(int st)
{
    queue<int> Q;
    Q.push(st);
    vis[st] = true;
    while (!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        int len = outs1[t].size();
        for (int i = 0; i < len; i++)
        {
            int v = outs1[t][i];
            if (!vis[v])
            {
                graph[st][v] = graph[st][t] + 1;
                if (graph[st][v] < k + 1)
                {
                    Q.push(v);
                }
                vis[v] = true;
            }
        }
    }
}

inline void printGraph()
{
    printf("    ");
    for (int i = 1; i <= n; i++)
        printf("%4d", i);
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%4d", i);
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] >= INF)
                printf(" INF");
            else
                printf("%4d", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // freopen("holiday-hack.in", "r", stdin);
    // freopen("holiday.out", "w", stdout);

    // scanf("%d%d%d", &n, &m, &k);
    n = readInt();
    m = readInt();
    k = readInt();
    for (int i = 2; i <= n; i++)
    {
        // scanf("%lld", score + i);
        score[i] = readLL();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        // scanf("%d%d", &edges[i].a, &edges[i].b);
        int u = readInt(), v = readInt();
        outs1[u].push_back(v);
        outs1[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
            vis[j] = false;
        }
        bfs(i);
    }

    // printGraph();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && graph[i][j] <= k + 1)
                outs2[i].push_back(j);
        }
    }
    for (int i = 2; i <= n; i++)
        vis[i] = false;
    vis[1] = true;
    dfs(1, 1, 0);
    printf("%lld\n", ans);

    return 0;
}
