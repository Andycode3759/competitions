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

int n;

double getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        points[i] = Point(x, y, i);
    }
    double dis = 0;
    int last;
    scanf("%d", &last);
    for (int i = 2; i <= n; i++)
    {
        int now;
        scanf("%d", &now);
        dis += getDistance(points[last], points[now]);
        last = now;
    }

    printf("%lf\n", dis);

    return 0;
}
