// Score: 83/100
// WA
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-7;

double getHeight(double x, double y, double w)
{
    double lt = sqrt(x * x - w * w), rt = sqrt(y * y - w * w);
    return lt * rt / (lt + rt);
}

int main()
{
    double x, y, c;
    while (scanf("%lf%lf%lf", &x, &y, &c) == 3)
    {
        // 二分距离
        double l = 0, r = x + y;
        double mid;
        while (r - l > EPS)
        {
            mid = (l + r) / 2;
            if (mid > x || mid > y)
            {
                r = mid;
                continue;
            }
            if (getHeight(x, y, mid) > c)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        printf("%.3lf\n", mid);
    }
    return 0;
}
