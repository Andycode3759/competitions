// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r);
    double probNot;
    if (l >= x)
    {
        probNot = 1.0;
    }
    else if (x > r)
    {
        probNot = 0.0;
    }
    else
    {
        probNot = (r - x + 1.0) / (r - l + 1.0);
    }
    printf("%.15lf\n", 1.0 - probNot);
    return 0;
}
