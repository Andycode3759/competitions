// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
const double EPS = 1e-11;
const double INF = 1e15;

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

Point points[MAXN];
Point sortedPoints[MAXN];

int n;

double getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double minDis[MAXN][MAXN][2]; // 取左边i个点和右边i个点并且当前在左(0)或右(1)的最小路径

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            minDis[i][j][0] = minDis[i][j][1] = -114514;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        sortedPoints[i] = points[i] = Point(x, y, i);
    }
    sort(sortedPoints + 1, sortedPoints + n + 1);
    int topPoint = sortedPoints[1].index;
}