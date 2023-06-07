#include <cmath>
#include <cstdio>
using namespace std;

int n;
int c1 = -1, v1 = -1, c2 = -1, v2 = -1;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d", &n);
    int c, v;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &c, &v);
        if (c1 == -1)
            c1 = c, v1 = v;
        else if (c2 == -1)
        {
            if (c1 != c || v1 != v)
                c2 = c, v2 = v;
        }
    }
    if (c2 == -1)
    {
        printf("%d\n", n - 1);
    }
    else
    {
        printf("%d\n", (c1 == c2 && abs(v1 - v2) == 1) ? n - 2 : n - 1);
    }
    return 0;
}