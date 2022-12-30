//UNFINISHED
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 33;
const double PI = acos(-1.0);

struct Point
{
    double x, y;

    Point(double _x = 0, double _y = 0)
    {
        x = _x;
        y = _y;
    }

    double distanceTo(Point another)
    {
        return sqrt(pow(x - another.x, 2) + pow(y - another.y, 2));
    }
    Point operator+(Point b)
    {
        return Point(x + b.x, y + b.y);
    }
};
Point points[MAXN];

int main()
{
    int kase;
    scanf("%d", &kase);
    for (int k = 0; k < kase; k++)
    {
        int n;
        for (int i = 0; i < n; i++)
        {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            points[i] = Point(tx, ty);
        }
    }
    return 0;
}
