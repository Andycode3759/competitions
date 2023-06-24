#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 12;

struct Node
{
    int cost, dmg;
};
Node se[MAXN], sf[MAXN];

int n, pi, bi, d;

void solveSP1() // n=1
{
    if (se[1].cost > pi && sf[1].cost > pi)
    {
        printf("T\n");
        return;
    }

    int eb = bi, fb = bi, ep = pi, fp = pi;
    while (true)
    {
        if (ep >= se[1].cost)
        {
            fb -= se[1].dmg;
            ep -= se[1].cost;
            if (fb <= 0)
            {
                printf("E %d\n", eb);
                return;
            }
        }
        if (fp >= sf[1].cost)
        {
            eb -= sf[1].dmg;
            if (eb <= 0)
            {
                printf("F %d\n", fb);
                return;
            }
        }
        if (d == 0)
        {
            printf("T\n");
            return;
        }
        ep = min(ep + d, pi), fp = min(fp + d, pi);
    }
}
void solveSP2() // d=0
{
    solveSP1();
}
void solveGeneral()
{
    solveSP1();
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &n, &pi, &bi, &d);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &se[i].cost, &se[i].dmg);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &sf[i].cost, &sf[i].dmg);
        }

        if (n == 1)
            solveSP1();
        else if (d == 0)
            solveSP2();
        else
            solveGeneral();
    }
    return 0;
}
