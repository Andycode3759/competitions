// TLE -10%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const int INF = (1 << 30) - 1;

int n, m, k;
int arr[MAXN];

int force() // 90%
{
    int ans = 0;
    for (int i = 1; i <= n - m + 1; i++)
    {
        int maxn = -INF;
        for (int j = 0; j < m; j++)
        {
            maxn = max(maxn, arr[i + j]);
        }
        if (maxn <= k)
        {
            ans++;
        }
    }
    return ans;
}

int coverable[MAXN];
int trueAns()
{
    for (int i = 1; i <= n; i++)
    {
        coverable[i] = min(min(n - i + 1, i), m);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }

    printf("%d\n", force());
    return 0;
}
