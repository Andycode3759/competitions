#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
constexpr int MAXN = 10004;
constexpr long long INF = (1LL << 60) - 1;

int n;
int arr[MAXN], diff[MAXN];

long long ans = INF;
int d[MAXN * 2];
void dfs(int cnt, int l, int r)
{
    if (cnt == n - 1)
    {
        long long r1 = arr[1] * arr[1], r2 = arr[1];
        for (int i = 2; l <= r; l++, i++)
        {
            arr[i] = arr[i - 1] + d[l];
            r1 += arr[i] * arr[i], r2 += arr[i];
        }
        ans = min(ans, r1 * n - r2 * r2);
        return;
    }
    int p = diff[cnt + 2];
    if (p == 0)
    {
        d[l - 1] = p;
        dfs(cnt + 1, l - 1, r);
        return;
    }
    if (p != d[r])
    {
        d[l - 1] = p;
        dfs(cnt + 1, l - 1, r);
    }
    d[r + 1] = p;
    dfs(cnt + 1, l, r + 1);
}

int main()
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        diff[i] = arr[i] - arr[i - 1];
    }
    sort(diff + 2, diff + 1 + n);

    d[n] = diff[2];
    dfs(1, n, n);

    printf("%lld\n", ans);
    return 0;
}