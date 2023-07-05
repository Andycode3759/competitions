#include <cstdio>
using namespace std;
const int MAXN = 300005;
const long long INF = (1LL << 60) - 1;

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int n, m;
int arr[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    long long cur = 0, ans = -INF;
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cur > 0)
        {
            cur += arr[i];
            if (len == m)
                cur -= arr[i - m];
            else
                len++;
        }
        else
        {
            cur = arr[i];
            len = 1;
        }
        ans = max(cur, ans);
    }
    printf("%lld\n", ans);
    return 0;
}
