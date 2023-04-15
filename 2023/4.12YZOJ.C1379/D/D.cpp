#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, m;

struct Edge
{
    Edge(int _d, int _n) : dest(_d), next(_n)
    {
    }
    int dest, next;
};
vector<Edge> edges;
int fir[MAXN];

void addEdge(int from, int to)
{
    edges.push_back(Edge(to, fir[from]));
    fir[from] = edges.size() - 1;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(fir, -1, sizeof(fir));
        vector<Edge>().swap(edges);

        int a, b;
        for (int i = 1; i <= n - 1; i++)
        {
            scanf("%d%d", &a, &b);
            addEdge(a, b);
            addEdge(b, a);
        }
    }
    return 0;
}
