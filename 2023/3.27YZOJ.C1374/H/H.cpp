// AC       on POJ (p1330)
// WA -56%  on YZOJ
// 玄学
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
        // isFatherEdge = _f;
    }
    int dest, next;
    // bool isFatherEdge; // 是一条儿子指向父亲的边
};
vector<Edge> edges;
int firstEdge[MAXN];

void addEdge(int src, int dst)
{
    edges.push_back(Edge(dst, firstEdge[src]));
    firstEdge[src] = edges.size() - 1;
}

int grandfaLog[MAXN][MAX_LOGN]; // 从x出发，向上移动2^i步的祖先；-1表示超出根
int fatherOf[MAXN];
int depthOf[MAXN];
void init(int n, int root)
{
    for (int i = 0; i < MAX_LOGN; i++)
    {
        grandfaLog[root][i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        grandfaLog[i][0] = fatherOf[i];
    }
    for (int lg = 1; lg < MAX_LOGN; lg++)
    {
        for (int x = 1; x <= n; x++)
        {
            grandfaLog[x][lg] = grandfaLog[grandfaLog[x][lg - 1]][lg - 1];
        }
    }
}
void dfsGetDepth(int x, int depth)
{
    depthOf[x] = depth;
    for (int i = firstEdge[x]; i != -1; i = edges[i].next)
    {
        Edge &e = edges[i];
        // if (e.isFatherEdge)
        //     continue;
        dfsGetDepth(e.dest, depth + 1);
    }
}
int findLCA(int x, int y)
{
    if (depthOf[x] < depthOf[y])
        swap(x, y);
    // 保证depthOf[x] >= depthOf[y]

    for (int lg = MAX_LOGN - 1; lg >= 0; lg--) // 上移x
    {
        int g = grandfaLog[x][lg];
        if (g <= 0 || depthOf[g] < depthOf[y])
        {
            continue;
        }
        else
        {
            x = grandfaLog[x][lg];
        }
    }
    // 保证depthOf[x]==depthOf[y]

    if (x == y)
        return y;

    for (int lg = MAX_LOGN - 1; lg >= 0; lg--)
    {
        if (grandfaLog[x][lg] != grandfaLog[y][lg])
        {
            x = grandfaLog[x][lg];
            y = grandfaLog[y][lg];
        }
    }
    return fatherOf[x];
}

bool book[MAXN];
void dfsColor(int x, int root)
{
    if (x == root)
        return;
    book[x] = true;
    dfsColor(fatherOf[x], root);
}
int findLCAForce(int x, int y, int root)
{
    memset(book, 0, sizeof(book));
    if (depthOf[x] < depthOf[y])
        swap(x, y);
    dfsColor(x, root);
    while (!book[y])
    {
        y = fatherOf[y];
    }
    return y;
}

int main()
{
    int T;
    T = read();
    // scanf("%d", &T);
    while (T--)
    {
        memset(firstEdge, -1, sizeof(firstEdge));
        memset(grandfaLog, -1, sizeof(grandfaLog));
        memset(fatherOf, -1, sizeof(fatherOf));
        memset(depthOf, -1, sizeof(depthOf));
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
            // addEdge(v, u, true);
            fatherOf[v] = u;
        }
        int x, y;
        x = read();
        y = read();
        // scanf("%d%d", &x, &y);
        int root = 0;
        for (int i = 1; i <= n; i++)
        {
            if (fatherOf[i] <= 0)
            {
                root = i;
                break;
            }
        }
        init(n, root);
        dfsGetDepth(root, 0);
        int ans = findLCA(x, y);
        // int ans = findLCAForce(x, y, root);
        printf("%d\n", ans);
    }
    return 0;
}