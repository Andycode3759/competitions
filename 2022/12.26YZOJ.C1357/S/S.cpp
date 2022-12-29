//ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-7;

int main()
{
    double len, temp, coff;
    while (scanf("%lf%lf%lf", &len, &temp, &coff) == 3)
    {
        if (len < 0 && temp < 0 && coff < 0)
        {
            break;
        }
        double radLength = len * (1 + temp * coff);
        // printf("radLen=%lf\n",radLength);
        double l = 0, r = len / 2;
        double mid;
        // 二分高度差
        while (r - l >= EPS)
        {
            // printf("l=%lf d=%lf radLen=%lf\n",len,mid,getRadLen(len,mid));
            mid = (l + r) / 2.0;
            double radius = (4 * mid * mid + len * len) / (8 * mid);
            double s = asin(len / 2 / radius) * radius * 2;
            if (s > radLength)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        printf("%.3lf\n", mid);
    }
    return 0;
}
