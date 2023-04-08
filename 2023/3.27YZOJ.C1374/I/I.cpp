#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100006;

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

struct BFSNode
{
    BFSNode(int _n, int _s)
    {
        node = _n;
        step = _s;
    }
    int node, step;
};
bool book[MAXN];
int force(int x, int y) // TLE -30%
{
    memset(book, false, sizeof(book));
    queue<BFSNode> Q;
    Q.push(BFSNode(x, 0));
    while (!Q.empty())
    {
        BFSNode n = Q.front();
        Q.pop();
        if (n.node == y)
            return n.step;
        book[n.node] = true;
        for (int i = firstEdge[n.node]; i != -1; i = edges[i].next)
        {
            if (!book[edges[i].dest])
                Q.push(BFSNode(edges[i].dest, n.step + 1));
        }
    }
    return -1;
}

// LCA
int trueAns(int x, int y)
{
}

int main()
{
    memset(firstEdge, -1, sizeof(firstEdge));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", force(x, y));
    }
    return 0;
}
