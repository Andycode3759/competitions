#include <cstdio>
using namespace std;
const int MAXN = 1000006;

int n;
int arr[MAXN << 1], sum[MAXN << 1];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[n + i] = arr[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        sum[i] = (arr[i] % 2 == 0) ? 1 : -1;
        sum[i] += sum[i - 1];
    }
    long long ans = 0;
    for (int len = 2; len <= n; len += 2)
    {
        for (int l = 1, r = l + len - 1; l <= n; l++, r++)
        {
            if (sum[r] - sum[l - 1] == 0)
                ans++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
