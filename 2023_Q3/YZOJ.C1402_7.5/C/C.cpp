// AC
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
const long long INF = (1LL << 60) - 1;

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int n;
int arr[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    for (int Kase = 1; Kase <= T; Kase++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", arr + i);
        }
        long long cur = 0, ans = -INF;
        int l = 1, r = 1;
        int ansL = 1, ansR = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cur < 0)
            {
                l = i, r = i;
                cur = arr[i];
            }
            else
            {
                r = i;
                cur += arr[i];
            }
            if (cur > ans)
            {
                ansL = l, ansR = r;
                ans = cur;
            }
        }
        printf("Case %d:\n%lld %d %d\n\n", Kase, ans, ansL, ansR);
    }
    return 0;
}
