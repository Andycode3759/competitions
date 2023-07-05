// AC
#include <cstdio>
using namespace std;
const int MAXN = 1e7 + 7;
const long long INF = (1LL << 60) - 1;

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int n;
int arr[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    long long cur = 0, ans = -INF;
    for (int i = 1; i <= n; i++)
    {
        cur = max(cur + arr[i], arr[i]);
        ans = max(cur, ans);
    }
    printf("%lld\n", ans);
    return 0;
}
