// AC
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 100005;
const int MAX_LOGN = 18;

int read()
{
    char c = getchar();
    int res = 0;
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

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
int firstEdge[MAXN];

void addEdge(int src, int dst)
{
    edges.push_back(Edge(dst, firstEdge[src]));
    firstEdge[src] = edges.size() - 1;
}

bool hasFa[MAXN];
int faLog[MAX_LOGN][MAXN]; // 从x出发，向上移动2^i步的祖先；-1表示超出根
int depth[MAXN];
void init(int n, int root)
{
    for (int lg = 1; lg < MAX_LOGN; lg++)
    {
        for (int x = 1; x <= n; x++)
        {
            faLog[lg][x] = faLog[lg - 1][faLog[lg - 1][x]];
        }
    }
}
void dfs(int x, int dep, int fa)
{
    depth[x] = dep;
    faLog[0][x] = fa;
    for (int i = firstEdge[x]; i != -1; i = edges[i].next)
    {
        Edge &e = edges[i];
        // printf("%d--->%d\n", x, e.dest);

        dfs(e.dest, dep + 1, x);
    }
}
int findLCA(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);
    // 保证depth[x] >= depth[y]

    for (int lg = MAX_LOGN - 1; lg >= 0; lg--) // 上移x
    {
        int g = faLog[lg][x];
        if (g <= 0 || depth[g] < depth[y])
        {
            continue;
        }
        else
        {
            x = faLog[lg][x];
        }
    }
    // 保证depth[x]==depth[y]

    if (x == y)
        return y;

    for (int lg = MAX_LOGN - 1; lg >= 0; lg--)
    {
        if (faLog[lg][x] != faLog[lg][y])
        {
            x = faLog[lg][x];
            y = faLog[lg][y];
        }
    }
    return faLog[0][x];
}

int main()
{
    int T;
    T = read();
    // scanf("%d", &T);
    while (T--)
    {
        memset(firstEdge, -1, sizeof(firstEdge));
        memset(faLog, -1, sizeof(faLog));
        memset(hasFa, false, sizeof(hasFa));
        memset(depth, -1, sizeof(depth));
        vector<Edge>().swap(edges);

        int n;
        n = read();
        // scanf("%d", &n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            u = read();
            v = read();
            // scanf("%d%d", &u, &v);
            addEdge(u, v);
            hasFa[v] = true;
            // addEdge(v, u, true);
            // faLog[0][v] = u;
        }
        int x, y;
        x = read();
        y = read();
        // scanf("%d%d", &x, &y);
        int root = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!hasFa[i])
            {
                root = i;
                break;
            }
        }
        dfs(root, 0, -1);
        init(n, root);
        int ans = findLCA(x, y);
        printf("%d\n", ans);
    }
    return 0;
}