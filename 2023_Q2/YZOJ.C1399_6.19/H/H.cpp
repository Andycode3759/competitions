#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;

int n;
long long a[MAXN], m[MAXN];
__int128 M[MAXN];

__int128 exgcd(__int128 a, __int128 b, __int128 &x, __int128 &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    __int128 r = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return r;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        M[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", a + i, m + i);
            M[1] *= m[i];
        }
        for (int i = 1; i <= n; i++)
        {
            M[i] /= m[i];
        }
    }
    return 0;
}
