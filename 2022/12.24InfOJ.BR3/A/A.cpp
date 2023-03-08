// Score: 0/100
// TLE
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2502;
int arr[MAXN];

int main()
{
    int n, m, ans, count;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int k = 0; k <= n; k++)
    {
        ans = 0;
        for (int t = 1; t <= m; t++)
        {
            count = 0;
            for (int i = 1; i <= n; i++)
            {
                if (t % arr[i] == 0)
                    count++;
            }
            if (count == k)
                ans++;
        }
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}
