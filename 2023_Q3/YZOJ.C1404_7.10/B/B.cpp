// AC
#include <cstdio>
using namespace std;
const int MAXN = 300005;
const int MAXN_LG = 20;
const int INF = (1 << 30) - 1;

constexpr const int max(const int &a, const int &b)
{
    return a < b ? b : a;
}
constexpr const int min(const int &a, const int &b)
{
    return a < b ? a : b;
}
inline int read()
{
    int f = 1, res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            f = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return f * res;
}

int n, m;
int val[MAXN], sum[MAXN];
int stMin[MAXN_LG][MAXN];
int lg2[MAXN];

inline int getMin(int l, int r)
{
    int lg = lg2[r - l + 1];
    return min(stMin[lg][r], stMin[lg][l + (1 << lg) - 1]);
}

int main()
{
    lg2[1] = 0;
    n = read(), m = read();
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i >> 1] + 1;
    for (int i = 1; i <= n; i++)
        stMin[0][i] = (sum[i] = sum[i - 1] + (val[i] = read()));

    for (int lg = 1, len = 2; len <= n; lg++, len = (1 << lg))
    {
        for (int i = n; i >= (1 << (lg - 1)); i--)
        {
            stMin[lg][i] = min(stMin[lg - 1][i], stMin[lg - 1][i - (1 << (lg - 1))]);
        }
    }

    int res = -INF;
    for (int i = n; i >= 1; i--)
    {
        res = max(res, sum[i] - getMin(max(0, i - m), i - 1));
    }
    printf("%d\n", res);

    return 0;
}