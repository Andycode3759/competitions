#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;

int n;
int atm[MAXN * 2];

int preSum[MAXN];

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