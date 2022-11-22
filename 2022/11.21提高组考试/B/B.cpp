#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int a[1003];
int n;
int cost;

int action(int x) // returns the cost, x != 0
{
    a[x] = 0;
    int l, r;
    int costl = 0;
    int costr = 0;
    for (int i = x - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            l = i;
            break;
        }
        else
        {
            costl += a[i];
        }
    }
    for (int i = x + 1; i <= n + 1; i++)
    {
        if (a[i] == 0)
        {
            r = i;
            break;
        }
        else
        {
            costr += a[i];
        }
    }
    if (costl < 0)
        costl = 0;
    if (costr > 0)
        costr = 0;
    return costl + costr;
}

void doit(int start, int end)
{
    int max = -1;
    int best = -1;
    int cost = 0;
    for (int i = start; i <= end; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            best = i;
        }
    }
    cost += action(best);
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    // doit(0, n + 1);

    printf("bu hui zuo\n");

    return 0;
}
