#include <cstdio>
using namespace std;
constexpr int MAXN = 50004;

inline int read()
{
    char c = getchar();
    int res = 0;
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int n;
int a[MAXN], b[MAXN];
int q;

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    q = read();
    long long res = 0;
    while (q--)
    {
        int l, r, x;
        l = read(), r = read(), x = read();
        long long ans = 0;
        for (int i = l; i <= r; i++)
        {
            if ((x | a[i]) == x)
            {
                x -= a[i];
                ans += b[i];
            }
        }
        res ^= ans;
    }
    printf("%lld\n", res);
    return 0;
}