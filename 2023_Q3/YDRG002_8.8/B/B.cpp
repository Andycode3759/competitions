#include <cstdio>
using namespace std;
constexpr int MAXN = 200005;

// struct Edge
// {
//     int next, v, w;
// };
struct Edge
{
    int u, v, w;
};
Edge edges[MAXN];
int head[MAXN], tot;

// inline void addEdge(int u, int v, int w)
// {
//     Edge &target = edges[++tot];
//     target.v = v, target.w = w;
//     target.next = head[u];
//     head[u] = tot;
// }
inline void addEdge(int u, int v, int w)
{
    Edge &target = edges[++tot];
    target.v = v, target.w = w;
    target.u = u;
}

int n, m;
int val[MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
        // addEdge(u, v, w);
        // addEdge(v, u, w);
        val[u] |= w;
        val[v] |= w;
    }

    for (int i = 1; i <= m; i++)
    {
        Edge &e = edges[i];
        if ((val[e.u] & val[e.v]) != e.w)
        {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", val[i]);
    }
    printf("\n");
    return 0;
}