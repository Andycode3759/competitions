// AC
#include <cstdio>
using namespace std;
const int MAXN = 1e7 + 7;
const int INF = (1 << 30) - 1;

constexpr const int max(const int &a, const int &b)
{
    return a > b ? a : b;
}

int n;
int val[MAXN], ans[MAXN];
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
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        val[i] = read();

    int res = -INF;
    for (int i = n; i >= 1; i--)
    {
        ans[i] = max(val[i], val[i] + max(0, ans[i + 1]));
        res = max(res, ans[i]);
    }

    printf("%d\n", res);
    return 0;
}
