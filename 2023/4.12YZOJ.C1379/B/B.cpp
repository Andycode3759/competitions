// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;

int n;
long long atm[MAXN];
long long diff[MAXN];

/*
// 20%
int preSum[MAXN];
int atm[MAXN * 2];
int main()
{
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", atm + i);
        atm[i + n] = atm[i];
        tot += atm[i];
    }
    int avg = tot / n;
    for (int i = 1; i <= 2 * n; i++)
    {
        preSum[i] = preSum[i - 1] + atm[i];
    }
    int ans = (1 << 30) - 1;
    int half = n / 2;
    for (int i = 1; i <= half; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            int idx = i + j;
            int realSum = preSum[idx] - preSum[i - 1];
            int diff = abs(realSum - avg * (j + 1));
            sum += diff;
        }
        ans = min(ans, sum);
    }
    printf("%d\n", ans);

    return 0;
}
*/
int main()
{
    scanf("%d", &n);
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", atm + i);
        tot += atm[i];
    }
    long long avg = tot / n;

    for (int i = 1; i <= n; i++)
    {
        diff[i] = diff[i - 1] + avg - atm[i];
    }
    sort(diff + 1, diff + 1 + n);
    long long mid = diff[n / 2 + 1];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(diff[i] - mid);
    }

    printf("%lld\n", ans);
    return 0;
}