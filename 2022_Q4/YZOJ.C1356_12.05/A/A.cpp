//Score: 100/100
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    for (int i = 1; i <= n; i++)
    {
        x += i;
        x = sqrt(x);
    }
    printf("%.2f\n", x);
    return 0;
}
