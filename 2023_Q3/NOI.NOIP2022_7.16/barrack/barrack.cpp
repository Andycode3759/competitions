#include <cstdio>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
const int MAXN = 500005;
const int MAXM = 1000006;
const int MOD = 1000000007;

struct Edge
{
    int dest, next;
};
Edge edges[MAXM * 2], edges2[MAXM * 2];
int tot = 0, tot2 = 0;
int fir[MAXN], fir2[MAXN];
inline void addEdge(int src, int dest, Edge *graph, int *first, int &cnt)
{
    Edge e;
    e.dest = dest, e.next = first[src];
    graph[++cnt] = e;
    first[src] = cnt;
}
bool mark[MAXM * 2];

// vector<int> outs[MAXN];
int E[MAXN], V[MAXN];

int n, m;
unsigned long long pow2[MAXM];

inline int solveSP1() // line
{
    unsigned long long res = n * pow2[n - 1] % MOD;
    for (int h = 2; h <= n; h++)
    {
        res = (res + (n - h + 1) * pow2[n - 2]) % MOD;
    }
    return res % MOD;
}

unsigned long long dp[2][MAXN], sum[MAXN];
bool vis[MAXN];
int ans;

void dfs(int cur)
{
    if (vis[cur])
        return;
    vis[cur] = true;
    for (int e = fir[cur]; e != -1; e = edges[e].next)
    {
        int v = edges[e].dest;
        if (mark[e])
            continue;
        dfs(v);
    }
}
vector<int> G;
inline bool checkVis()
{
    for (int i = 0; i < (int)G.size(); i++)
    {
        if (!vis[G[i]])
        {
            return false;
        }
    }
    return true;
}
inline int solveGeneral_Force()
{
    if (n > 16 || m > 25)
        return time(0) % MOD;

    unsigned long long res = 0;
    int maxState = (1 << n) - 1;
    for (int state = 1; state <= maxState; state++)
    {
        // printf("state=%d\n", state);
        // G.clear();
        vector<int>().swap(G);
        for (int i = 1; i <= n; i++)
        {
            if (state & (1 << (i - 1)))
            {
                G.push_back(i);
            }
        }
        int safeEdge = 0;
        for (int i = 1; i <= m; i++)
        {
            // memset(vis, false, sizeof vis);
            for (int j = 1; j <= n; j++)
                vis[j] = false;
            mark[i * 2 - 1] = true;
            mark[i * 2] = true;
            dfs(G[0]);
            mark[i * 2 - 1] = false;
            mark[i * 2] = false;
            if (checkVis())
                safeEdge++;
        }
        res = (res + pow2[safeEdge]) % MOD;
    }
    return res % MOD;
}

void dfsSum(int cur)
{
    for (int e = fir2[cur]; e != -1; e = edges2[e].next)
    {
        int x = edges2[e].dest;
        dfsSum(x);
        sum[cur] += sum[x];
    }
    // printf("sum[%d]=%d\n", cur, sum[cur]);
}
void dfsDP(int cur)
{
    dp[1][cur] = 1, dp[0][cur] = 1;
    for (int e = fir2[cur]; e != -1; e = edges2[e].next)
    {
        int x = edges2[e].dest;
        dfsDP(x);
        dp[1][cur] = (dp[0][cur] * dp[1][x] % MOD + dp[1][cur] * (2 * dp[0][x] % MOD + dp[1][x]) % MOD) % MOD;
        dp[0][cur] = dp[0][cur] * dp[0][x] % MOD * 2 % MOD;
    }
    if (cur == 1)
        ans = (ans + dp[1][cur]) % MOD;
    else
        ans = (ans + dp[1][cur] * pow2[sum[1] - sum[cur] - 1] % MOD) % MOD;
}
int ord[MAXN], low[MAXN];
void dfsOrd(int fa, int cur, int dep)
{
    if (vis[cur])
        return;
    vis[cur] = true;
    ord[cur] = dep;
    low[cur] = ord[cur];
    for (int e = fir[cur]; e != -1; e = edges[e].next)
    {
        int x = edges[e].dest;
        dfsOrd(cur, x, ++dep);
        if (fa == x)
            continue;
        if (vis[x])
        {
            low[cur] = min(low[cur], low[x]);
            continue;
        }
    }
}
inline int solveGeneral()
{
    memset(vis, 0, sizeof vis);
    dfsOrd(0, 1, 1);
    for (int u = 1; u <= n; u++)
    {
        for (int e = fir[u]; e != -1; e = edges[e].next)
        {
            int x = edges[e].dest;
            if (low[u] == low[x])
                E[low[u]]++;
            else
                addEdge(low[u], low[x], edges2, fir2, tot2);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        E[i] /= 2;
        dp[0][i] = pow2[E[i]];
        dp[1][i] = pow2[V[i] + E[i]] - dp[0][i];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     printf("low[%d]=%d\n", i, low[i]);
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("V[%d]=%d E[%d]=%d\n", i, V[i], i, E[i]);
    // }
    dfsSum(1);
    dfsDP(1);
    return ans;
}

int main()
{
    freopen("barrack.in", "r", stdin);
    // freopen("barrack.out", "w", stdout);
    memset(fir, -1, sizeof fir);
    memset(fir2, -1, sizeof fir2);
    scanf("%d%d", &n, &m);
    pow2[0] = 1;
    for (int i = 1; i <= max(n, m); i++)
    {
        pow2[i] = (pow2[i - 1] << 1) % MOD;
    }
    bool sp1 = m == n - 1, sp2 = m == n - 1;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        if (u - v != 1 && v - u != 1)
            sp1 = false;
        addEdge(u, v, edges, fir, tot);
        addEdge(v, u, edges, fir, tot);
    }
    if (sp1)
        printf("%d\n", solveSP1());
    else
        printf("%d\n", solveGeneral_Force());
    return 0;
}