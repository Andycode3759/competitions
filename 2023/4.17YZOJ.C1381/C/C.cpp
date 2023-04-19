#include <bits/stdc++.h>
using namespace std;
const int MAXN = 17;

struct Point
{
    double x;
    double y;

    double getDistance(Point &c)
    {
        return sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
    }

    const bool operator<(const Point &c) const
    {
        return x == c.x ? y < c.y : x < c.x;
    }
};
Point ch[MAXN];

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &ch[i].x, &ch[i].y);
    }
    double ans = 1e9;
    // int cnt = 0;
    sort(ch, ch + n);
    while (next_permutation(ch, ch + n))
    {
        // printf("%d\n", ++cnt);
        double dis = 0;
        Point last;
        last.x = 0, last.y = 0;
        for (int i = 0; i < n; i++)
        {
            dis += last.getDistance(ch[i]);
            last = ch[i];
            if (dis >= ans)
                break;
        }
        ans = min(ans, dis);
    }

    printf("%.2lf\n", ans);
    return 0;
}
