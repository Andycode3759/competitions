// 10%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
const double EPS = 1e-11;

struct Point
{
    Point(double _x = 0, double _y = 0, int _i = 0)
    {
        x = _x;
        y = _y;
        index = _i;
    }

    double x, y;
    int index;
};
struct PointCmp
{
    bool operator()(Point a, Point b)
    {
        if (abs(a.y - b.y) <= EPS)
        {
            return a.index < b.index;
        }
        else
        {
            return a.y > b.y;
        }
    }
};
struct BFSNode
{
    vector<int> perm;
    double distance;
};

Point points[MAXN];

int n;
bool book[MAXN];

double getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
bool contains(vector<int> &v, int obj)
{
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        if (*i == obj)
            return true;
    }
    return false;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        points[i] = Point(x, y, i);
    }
    sort(points + 1, points + 1 + n, PointCmp());

    // for (int i = 1; i <= n; i++)
    // {
    //     printf("point #%d: (%lf,%lf) @ index %d\n", i, points[i].x, points[i].y, points[i].index);
    // }
    vector<int> ansPerm;
    double minDis = 1e15;
    queue<BFSNode> Q;
    BFSNode start;
    start.perm.push_back(1);
    start.distance = 0;
    Q.push(start);

    while (!Q.empty())
    {
        BFSNode p = Q.front();
        Q.pop();
        if (p.perm.size() >= n)
        {
            if (p.distance < minDis)
            {
                ansPerm = p.perm;
                minDis = p.distance;
            }
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (contains(p.perm, i))
                continue;
            BFSNode ex;
            ex.perm = p.perm;
            Point a = points[*(ex.perm.end() - 1)];
            ex.perm.push_back(i);
            Point b = points[*(ex.perm.end() - 1)];
            ex.distance = p.distance + getDistance(a, b);
            Q.push(ex);
        }
    }

    for (vector<int>::iterator i = ansPerm.begin(); i != ansPerm.end(); i++)
    {
        printf("%d ", points[*i].index);
    }
    printf("\n");
    return 0;
}
