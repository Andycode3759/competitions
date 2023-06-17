#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 2000006;
const long long INF = (1LL << 42) - 1;

long long read()
{
    long long res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

long long wall[MAXN];
int n;
long long h, diff, maxh;

long long solveSP1()
{
    return maxh;
}
long long solveSP2()
{
    diff = abs(diff);
    if (diff % 2 == 0)
        return maxh;
    else
        return -1;
}

bool isDone()
{
    for (int i = 2; i <= n; i++)
        if (wall[i] != wall[i - 1])
            return false;
    return true;
}
long long solveGeneral()
{
    bool isGood = false;
    for (int i = 2; i <= n; i++)
    {
        if (abs(wall[i] - wall[i - 1]) % 2 == 0)
        {
            isGood = true;
            break;
        }
    }
    if (!isGood)
        return -1;
    while (!isDone())
    {
        int mi = 0;
        long long mw = INF;
        for (int i = 1; i <= n; i++)
        {
            if (wall[i] < mw)
                mw = wall[i], mi = i;
        }
        if (mi < n && wall[mi] == wall[mi + 1])
        {
            wall[mi] += 1, wall[mi + 1] += 1;
        }
        else
        {
            wall[mi] += 2;
        }
    }
    return wall[1];
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        bool sp1 = true, sp2 = true;
        bool odd = false;
        maxh = 0;
        for (int i = 1; i <= n; i++)
        {
            // scanf("%lld", wall + i);
            wall[i] = read();

            maxh = max(maxh, wall[i]);

            // sp1
            if (i == 1)
                odd = (wall[i] % 2 == 1);
            else
            {
                if ((wall[i] % 2 == 1) ^ odd)
                    sp1 = false;
            }

            // sp2
            if (i == 2)
                diff = wall[i] - wall[i - 1];
            if (i >= 3)
            {
                if (wall[i] - wall[i - 1] != diff)
                    sp2 = false;
            }
        }

        if (sp1)
            printf("%lld\n", solveSP1());
        else if (sp2)
            printf("%lld\n", solveSP2());
        else
            printf("%lld\n", solveGeneral());
    }
    return 0;
}
