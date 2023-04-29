#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const long long INF = (1LL << 62) - 1;

long long read()
{
    char c = getchar();
    long long res = 0;
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int n;

struct Lab
{
    long long x = 0, y = 0, z = 0;

    long long distanceTo(Lab a)
    {
        return abs(x - a.x) + abs(y - a.y) + abs(z - a.z);
    }
};

Lab lab[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        // scanf("%d", &n);
        n = read();
        Lab avg;
        for (int i = 1; i <= n; i++)
        {
            // scanf("%lld%lld%lld", &lab[i].x, &lab[i].y, &lab[i].z);
            lab[i].x = read();
            lab[i].y = read();
            lab[i].z = read();
            avg.x += lab[i].x;
            avg.y += lab[i].y;
            avg.z += lab[i].z;
        }
        avg.x /= n;
        avg.y /= n;
        avg.z /= n;

        // force
        int ansP = 0;
        long long minDis = INF;
        for (int p = 1; p <= n; p++)
        {
            long long dis = 0;
            for (int i = 1; i <= n; i++)
            {
                if (i == p)
                    continue;
                dis += lab[p].distanceTo(lab[i]);
            }
            if (dis < minDis)
            {
                minDis = dis;
                ansP = p;
            }
        }
        printf("%d %lld\n", ansP, minDis);
    }
    return 0;
}
