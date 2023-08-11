#include <cstdio>
#include <stack>
using namespace std;
constexpr int MAXN = 500005;
constexpr int MAXM = 1000006;
constexpr int MOD = 1e9 + 7;
using ll = long long;

struct Edge
{
    int dest, next;
};
struct Graph
{
    void init(int s)
    {
        for (int i = 0; i <= 2 * s; i++)
            fir[i] = -1;
        edgeCnt = 0;
    }
    Edge edges[MAXM * 2];
    int edgeCnt = 0;
    int fir[MAXM * 2];
    void addEdge(int src, int dest)
    {
        Edge e;
        e.dest = dest, e.next = fir[src];
        edges[++edgeCnt] = e;
        fir[src] = edgeCnt;
    }
};

Graph G1, G2;

stack<int> S;
int n, m;
int low[MAXN], dfn[MAXN], belong[MAXN];
ll sum[MAXN];
bool vis[MAXN];
int stmp = 0, dccCnt = 0;
ll ans = 0;
ll E[MAXN], V[MAXN];
ll pow2[MAXM];
ll dp[2][MAXN];

void tarjan(int fa, int cur)
{
    low[cur] = dfn[cur] = ++stmp;
    vis[cur] = true;
    S.push(cur);
    for (int e = G1.fir[cur]; e != -1; e = G1.edges[e].next)
    {
        int x = G1.edges[e].dest;
        if (x == fa)
            continue;
        if (dfn[x] == 0)
        {
            tarjan(cur, x);
            low[cur] = min(low[cur], low[x]);
        }
        else if (vis[x])
        {
            low[cur] = min(low[cur], dfn[x]);
        }
    }
    if (dfn[cur] == low[cur])
    {
        dccCnt++;
        int t;
        do
        {
            t = S.top();
            S.pop();
            vis[t] = false;
            belong[t] = dccCnt;
            V[dccCnt]++;
        } while (t != cur);
    }
}
void dfsSum(int fa, int cur)
{
    sum[cur] = E[cur];
    for (int e = G2.fir[cur]; e != -1; e = G2.edges[e].next)
    {
        int x = G2.edges[e].dest;
        if (fa == x)
            continue;
        dfsSum(cur, x);
        sum[cur] += sum[x] + 1;
    }
}
void dfsDP(int fa, int cur)
{
    for (int e = G2.fir[cur]; e != -1; e = G2.edges[e].next)
    {
        int x = G2.edges[e].dest;
        if (fa == x)
            continue;
        dfsDP(cur, x);
        dp[1][cur] = (dp[1][cur] * ((dp[0][x] * 2 + dp[1][x]) % MOD)) % MOD + dp[0][cur] * dp[1][x] % MOD;
        dp[0][cur] = ((dp[0][cur] * dp[0][x] % MOD) * 2) % MOD;
    }
    if (cur == 1)
        ans = (ans + dp[1][cur]) % MOD;
    else
        ans = (ans + dp[1][cur] * pow2[sum[1] - sum[cur] - 1]) % MOD;
}
int main()
{
    pow2[0] = 1;
    for (int i = 1; i < MAXM; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;

    scanf("%d%d", &n, &m);
    G1.init(max(n, m)), G2.init(max(n, m));
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        G1.addEdge(u, v);
        G1.addEdge(v, u);
    }
    tarjan(0, 1);
    for (int u = 1; u <= n; u++)
    {
        for (int e = G1.fir[u]; e != -1; e = G1.edges[e].next)
        {
            int v = G1.edges[e].dest;
            if (belong[u] != belong[v])
                G2.addEdge(belong[u], belong[v]);
            else
                E[belong[u]]++;
        }
    }
    for (int i = 1; i <= dccCnt; i++)
    {
        E[i] /= 2;
        dp[0][i] = pow2[E[i]];
        dp[1][i] = pow2[V[i] + E[i]] - dp[0][i];
    }
    dfsSum(0, 1);
    dfsDP(0, 1);
    printf("%llu\n", ans);
    return 0;
}