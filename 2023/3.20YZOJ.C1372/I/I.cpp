// AC
#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int iCeil(int a, int b)
{
    return (a + b - 1) / b;
}

int force() // 63%
{
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % c == 0)
            ans++;
    }
    return ans;
}

int trueAns() // AC
{
    int ac = ceil(a * 1.0 / c) * c, bc = floor(b * 1.0 / c) * c;
    return (bc - ac) / c + 1;
}

int withICeil() // 50%
{
    int ac = iCeil(a, c) * c, bc = (b / c) * c;
    return (bc - ac) / c + 1;
}

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    // int ans = force();
    int ans = trueAns();
    // int ans = withICeil();
    printf("%d\n", ans);
    return 0;
}
