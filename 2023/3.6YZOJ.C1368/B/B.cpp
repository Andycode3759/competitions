// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 303;

struct Edge
{
    int from, to, cost;
    Edge(int _f = 0, int _t = 0, int _c = 0)
    {
        from = _f;
        to = _t;
        cost = _c;
    }
};
struct EdgeCmp
{
    bool operator()(Edge a, Edge b)
    {
        return a.cost < b.cost;
    }
};
struct UnionFindSet
{
    int fatherOf[MAXN];

    UnionFindSet(int size)
    {
        for (int i = 0; i <= size; i++)
        {
            fatherOf[i] = i;
        }
    }

    void merge(int father, int son)
    {
        fatherOf[getFather(son)] = father;
    }
    int getFather(int son)
    {
        if (fatherOf[son] == son)
            return son;
        return fatherOf[son] = getFather(fatherOf[son]);
    }
};

vector<Edge> edges;

int main()
{
    int n;
    scanf("%d", &n);
    UnionFindSet ufs(n);

    int input;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        edges.push_back(Edge(0, i, input));
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf("%d", &input);
            if (x == y)
                continue;
            edges.push_back(Edge(x, y, input));
        }
    }

    sort(edges.begin(), edges.end(), EdgeCmp());
    int ans = 0;
    int edgeLeft = n;
    for (vector<Edge>::iterator i = edges.begin(); i != edges.end() && edgeLeft > 0; i++)
    {
        Edge &e = *i;
        if (ufs.getFather(e.from) == ufs.getFather(e.to))
            continue;

        // printf("edge #%d: %d---%d--->%d\n", i, e.from, e.cost, e.to);

        ans += e.cost;
        ufs.merge(e.from, e.to);
        edgeLeft--;
    }
    printf("%d\n", ans);
    return 0;
}
