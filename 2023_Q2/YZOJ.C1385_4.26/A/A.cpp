// AC
// Fixed: 2023/4/29
#include <algorithm>
#include <cmath>
#include <cstdio>
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
    long long x, y, z;

    long long distanceTo(Lab a)
    {
        return abs(x - a.x) + abs(y - a.y) + abs(z - a.z);
    }
};

Lab lab[MAXN];

long long x[MAXN], y[MAXN], z[MAXN];
long long sumx[MAXN], sumy[MAXN], sumz[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        // scanf("%d", &n);
        n = read();
        for (int i = 1; i <= n; i++)
        {
            // scanf("%lld%lld%lld", &lab[i].x, &lab[i].y, &lab[i].z);
            lab[i].x = x[i] = read();
            lab[i].y = y[i] = read();
            lab[i].z = z[i] = read();
        }

        sort(x + 1, x + 1 + n);
        sort(y + 1, y + 1 + n);
        sort(z + 1, z + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            sumx[i] = sumx[i - 1] + x[i];
            sumy[i] = sumy[i - 1] + y[i];
            sumz[i] = sumz[i - 1] + z[i];
        }
        int ansP = 0;
        long long minDis = INF;
        for (int p = 1; p <= n; p++)
        {
            long long dis = 0;
            Lab &l = lab[p];

            int dx = upper_bound(x + 1, x + 1 + n, l.x) - x - 2; // px及以前的元素都小于等于l.x
            dis += l.x * (2 * dx - n) + sumx[n] - 2 * sumx[dx];

            int dy = upper_bound(y + 1, y + 1 + n, l.y) - y - 2;
            dis += l.y * (2 * dy - n) + sumy[n] - 2 * sumy[dy];

            int dz = upper_bound(z + 1, z + 1 + n, l.z) - z - 2;
            dis += l.z * (2 * dz - n) + sumz[n] - 2 * sumz[dz];

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
