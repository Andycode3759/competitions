// ?%
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

double minDis[MAXN][MAXN]; // 从第i个灯连到第j个灯的最小距离

int decision[MAXN][MAXN]; // 在计算minDis[i][j]时最后一次连的是几号灯

double getMinDis(int left, int right)
{
    // 区间DP
    double &ans = minDis[left][right];
    if (ans >= 0)
        return ans;

    if (left == right)
    {
        decision[left][right] = left;
        return ans = 0;
    }

    ans = INF;
    // connect left
    double t = getDistance(points[left], points[left + 1]) + getMinDis(left + 1, right);
    if (t < ans)
    {
        ans = t;
        decision[left][right] = left;
    }

    // connect right
    t = getDistance(points[right], points[right - 1]) + getMinDis(left, right - 1);
    if (t < ans)
    {
        ans = t;
        decision[left][right] = right;
    }

    return ans;
}

vector<int> ansPerm;
void printAns(int left, int right)
{
    int &d = decision[left][right];
    printf("%d ", points[d].index);

    if (left != right)
    {
        if (d == left)
        {
            printAns(left + 1, right);
        }
        if (d == right)
        {
            printAns(left, right - 1);
        }
    }
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            minDis[i][j] = -114514;
        }
    }
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

    getMinDis(1, n);
    printAns(1, n);
    // for (int i = ansPerm.size() - 1; i >= 0; i--)
    // {
    //     printf("%d ", ansPerm[i]);
    // }
    printf("\n");

    return 0;
}
