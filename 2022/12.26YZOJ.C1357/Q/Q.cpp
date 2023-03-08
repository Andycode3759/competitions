// AC
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-5;

// pos 人离灯的距离
// light 灯的高度
// height 人的身高
double getLength(double pos, double light, double height, double width)
{
    double turnPoint = width * (light - height) / light;
    double q = height * pos / (light - height);
    return pos <= turnPoint ? height * pos / (light - height) : width - pos + light * (q - width + pos) / (q + pos);
}

int main()
{
    int kase;
    scanf("%d", &kase);
    for (int k = 0; k < kase; k++)
    {
        double light, height, width;
        scanf("%lf%lf%lf", &light, &height, &width);
        double l = 0, r = width;
        double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        while (r - l > EPS)
        {
            mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
            if (getLength(mid1, light, height, width) > getLength(mid2, light, height, width))
            {
                r = mid2;
            }
            else
            {
                l = mid1;
            }
        }
        printf("%.3lf\n", getLength(l, light, height, width));
    }
    return 0;
}
