// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20006;

struct Edge
{
    Edge(int _d, int _w, int _n)
    {
        dest = _d;
        weight = _w;
        next = _n;
    }
    int dest;
    int weight;
    int next;
};
vector<Edge> edges;
int firstEdge[MAXN];

void addEdge(int src, int dest, int weight)
{
    edges.push_back(Edge(dest, weight, firstEdge[src]));
    firstEdge[src] = edges.size() - 1;
}

int colorOf[MAXN];

void dfs(int v, int th, int color, bool *flag)
{
    colorOf[v] = color;
    for (int i = firstEdge[v]; i != -1; i = edges[i].next)
    {
        Edge e = edges[i];
        if (e.weight <= th)
            continue;
        if (colorOf[e.dest] == 0)
            dfs(e.dest, th, 3 - color, flag);
        else if (colorOf[e.dest] == color)
        {
            *flag = true;
            return;
        }
    }
    return;
}
bool tryBuildBG(int th, int n)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (colorOf[i] == 0)
        {
            dfs(i, th, 1, &flag);
            if (flag)
                return false;
        }
    }
    return true;
}

int main()
{
    memset(firstEdge, -1, sizeof(firstEdge));
    int n, m;
    scanf("%d%d", &n, &m);
    int maxw = -1;
    for (int i = 0; i < m; i++)
    {
        int s, d, w;
        scanf("%d%d%d", &s, &d, &w);
        maxw = max(maxw, w);
        addEdge(s, d, w);
        addEdge(d, s, w);
    }

    int l = 0, r = maxw;
    int ans;
    while (r > l)
    {
        ans = (l + r) / 2;
        // printf("[%d, (%d), %d]: ", l, ans, r);
        memset(colorOf, 0, sizeof(colorOf));
        if (tryBuildBG(ans, n))
        {
            // printf("Yes\n");
            r = ans;
        }
        else
        {
            // printf("No\n");
            l = ans + 1;
        }
    }
    printf("%d\n", l);

    // for (int ans = 0; ans <= maxw; ans++)
    // {
    //     memset(colorOf, 0, sizeof(colorOf));
    //     if (tryBuildBG(1, ans, 1))
    //     {
    //         printf("%d\n", ans);
    //         return 0;
    //     }
    // }

    // printf(tryBuildBG(1, maxw, 1) ? "Yes\n" : "No\n");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", colorOf[i]);
    // }
    // printf("\n");

    return 0;
}
