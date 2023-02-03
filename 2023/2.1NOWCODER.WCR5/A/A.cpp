//AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int item[MAXN];
long long itemSum[MAXN];

bool compBigger(int a, int b)
{
    return a > b;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &item[i]);
    }
    sort(item + 1, item + 1 + n, compBigger);
    // printf("itemSum[%d]=%lld\n", n, itemSum[n]);

    for (int i = 1; i <= n; i++)
    {
        itemSum[i] = itemSum[i - 1] + item[i];

        // printf("itemSum[%d]=%lld\n", i, itemSum[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int maxCount, maxVal;
        scanf("%d%d", &maxCount, &maxVal);
        int lb = (lower_bound(item + 1, item + 1 + n, maxVal, compBigger) - item), rb;
        long long ans;
        if (lb > n)
            ans = 0;
        else
        {
            rb = lb + maxCount - 1;
            rb = min(rb, n);
            ans = itemSum[rb] - itemSum[lb - 1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
