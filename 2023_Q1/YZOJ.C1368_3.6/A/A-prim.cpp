// AC
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
    int to;
    Edge(double _l, int _t)
    {
        length = _l;
        to = _t;
    }
};

struct EdgeComp
{
    bool operator()(Edge a, Edge b)
    {
        return a.length > b.length;
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

priority_queue<Edge, vector<Edge>, EdgeComp> edgesFrom[MAXN];
priority_queue<Edge, vector<Edge>, EdgeComp> edges;

void addEdges(priority_queue<Edge, vector<Edge>, EdgeComp> src)
{
    while (!src.empty())
    {
        edges.push(src.top());
        src.pop();
    }
}

bool isInSmt[MAXN];
vector<double> lengths;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    init(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &villages[i].x, &villages[i].y);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            edgesFrom[i].push(Edge(getDistanceOf(i, j), j));
        }
    }

    addEdges(edgesFrom[0]);
    isInSmt[0] = true;
    while (!edges.empty())
    {
        Edge e = edges.top();
        edges.pop();
        if (isInSmt[e.to])
            continue;
        lengths.push_back(e.length);
        addEdges(edgesFrom[e.to]);
        isInSmt[e.to] = true;
    }
    sort(lengths.begin(), lengths.end(), greater<double>());
    k--;
    if (k < 0)
        k = 0;

    // for (int i = 0; i < lengths.size(); i++)
    // {
    //     printf("%.2lf\n", lengths[i]);
    // }
    // printf("\n");

    printf("%.2lf\n", k >= lengths.size() ? 0.00 : lengths[k]);
    return 0;
}
