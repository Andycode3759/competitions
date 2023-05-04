#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, vx, vy;

int main()
{
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &vx, &vy);

    if (vx == 0)
    {
        if (x == 0 || x == n)
        {
            printf("%d %d\n", x, vy > 0 ? m : 0);
        }
        else
        {
            printf("-1\n");
        }
        return 0;
    }
    if (vy == 0)
    {
        if (y == 0 || y == m)
        {
            printf("%d %d\n", vx > 0 ? n : 0, y);
        }
        else
        {
            printf("-1\n");
        }
        return 0;
    }
    if (vx == -1)
        x += n;
    if (vy == -1)
        y += m;
    for (int tm = 0; tm <= 100000000; tm++)
    {
        if ((tm + x) % n == 0 && (tm + y) % m == 0)
        {
            int kx = (tm + x) / n;
            int ky = (tm + y) / m;
            printf("%d %d\n", kx % 2 == 1 ? n : 0, ky % 2 == 1 ? m : 0);
            return 0;
        }

        // printf("time: %d  x=%d y=%d\n", tm, x, y);
    }
    printf("-1\n");

    return 0;
}
