#include <cstdio>
using namespace std;
const int MAXN = 1000006;

int min(int a, int b)
{
    return a < b ? a : b;
}

int n;
int arr[MAXN << 1], sum[MAXN << 1];
int cnt[MAXN << 1];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[n + i] = arr[i];
    }
    int minSum = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        sum[i] = (arr[i] % 2 == 0) ? 1 : -1;
        sum[i] += sum[i - 1];
        minSum = min(minSum, sum[i]);
    }
    for (int i = 0; i <= n * 2; i++)
    {
        sum[i] -= minSum;
    }

    long long ans = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        if (i > n + 1)
        {
            cnt[sum[i - n - 1]]--;
        }
        ans += cnt[sum[i]];
        if (i <= n)
            cnt[sum[i]]++;
    }

    printf("%lld\n", ans);
    return 0;
}
