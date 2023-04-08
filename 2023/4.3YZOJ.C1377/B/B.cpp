#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;

int n, m, r;
int v[MAXN];

struct Edge
{
    Edge(int _d, int _n)
    {
        dest = _d;
        next = _n;
    }
    int dest, next;
};
vector<Edge> edges;
int fir[MAXN];

vector<int> child[MAXN];
bool mark[MAXN];
void addEdge(int src, int dst)
{
    edges.push_back(Edge(dst, fir[src]));
    fir[src] = edges.size() - 1;
}
void dfs(int node) // 无向转有向
{
    mark[node] = true;
    for (int i = fir[node]; i != -1; i = edges[i].next)
    {
        Edge &e = edges[i];
        if (mark[e.dest])
            continue;
        child[node].push_back(e.dest);
        dfs(e.dest);
    }
}

void addVal(int node, int delta)
{
    v[node] += delta;
}
long long getSum(int root) // 60%
{
    long long sum = v[root];
    vector<int> &c = child[root];
    for (int i = 0; i < c.size(); i++)
    {
        sum += getSum(c[i]);
    }
    return sum;
}

int main()
{
    memset(fir, -1, sizeof(fir));
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", v + i);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }
    dfs(r);

    while (m--)
    {
        int op;
        scanf("%d", &op);
        int a, x;
        switch (op)
        {
        case 1:
            scanf("%d%d", &a, &x);
            addVal(a, x);
            break;

        case 2:
            scanf("%d", &a);
            printf("%lld\n", getSum(a));
            break;
        }
    }
    return 0;
}