// AC
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 200005;

int n, k, q;
int arr[MAXN];
int ok[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(ok, 0, sizeof(ok));
        scanf("%d%d%d", &n, &k, &q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", arr + i);
            ok[i] = (arr[i] <= q) ? 1 : 0;
        }
        long long ans = 0;
        int sl = 0;
        bool bg = false;
        for (int i = 1; i <= n + 1; i++)
        {
            if (ok[i] == 1)
            {
                sl++;
                bg = true;
                // printf("1: sl=%d\n",sl);
            }
            else
            {
                // printf("0: sl=%d\n",sl);
                if (bg)
                {
                    int d = sl - k + 1;
                    if (d > 0)
                    {
                        ans += (1LL * d * (1 + d)) >> 1;
                    }
                }
                sl = 0;
                bg = false;
            }
        }
        printf("%lld\n", ans);
    }
}
