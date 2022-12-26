// Score: 5/100
// TLE
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
long long arr[MAXN];
long long gap[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        gap[i] = arr[i] - arr[i - 1];
    }
    int i, j, k, ans = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
            {
                if (arr[i] * j * arr[k] == i + arr[j] + k)
                {
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}