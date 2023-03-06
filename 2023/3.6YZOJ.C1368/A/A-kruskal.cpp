// WA 67%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;

struct Village
{
    double x, y;
} villages[MAXN];

struct Edge
{
    double length;
    int from, to;
    Edge(int _f, double _l, int _t)
    {
        from = _f;
        length = _l;
        to = _t;
    }
};

struct EdgeComp
{
    bool operator()(Edge a, Edge b)
    {
        return a.length < b.length;
    }
};

double distanceOf[MAXN][MAXN];

double getDistanceOf(int a, int b)
{
    if (distanceOf[a][b] >= 0)
        return distanceOf[a][b];
    return distanceOf[a][b] = distanceOf[b][a] =
               sqrt(pow(villages[a].x - villages[b].x, 2) + pow(villages[a].y - villages[b].y, 2));
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distanceOf[i][j] = i == j ? 0 : -1;
        }
    }
}

struct MergeSet
{
    int fatherOf[MAXN];
    MergeSet(int size)
    {
        for (int i = 0; i < size; i++)
        {
            fatherOf[i] = i;
        }
    }
    void addRelative(int father, int son)
    {
        fatherOf[son] = fatherOf[father];
    }
    int getTopFather(int son)
    {
        if (fatherOf[son] == son)
            return son;
        return fatherOf[son] = getTopFather(fatherOf[son]);
    }
};

vector<Edge> edges;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == 0)
        k = 1;
    init(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &villages[i].x, &villages[i].y);
    }

    MergeSet ms(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            edges.push_back(Edge(i, getDistanceOf(i, j), j));
        }
    }
    sort(edges.begin(), edges.end(), EdgeComp());

    int edgeCount = 0;
    for (int e = 0; e < edges.size(); e++)
    {
        Edge &ed = edges[e];
        if (ms.getTopFather(ed.from) == ms.getTopFather(ed.to))
            continue;
        ms.addRelative(ed.from, ed.to);
        edgeCount++;
        if (edgeCount == n - k)
        {
            printf("%.2lf\n", ed.length);
            return 0;
        }
    }
    printf("%.2lf\n", 0.00);
    return 0;
}
