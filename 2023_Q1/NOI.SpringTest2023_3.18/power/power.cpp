// 10%
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int a = 1; a <= x; a++)
        {
            bool flag = false;
            for (int b = k; b <= n; b++)
            {
                // printf("a=%d b=%d: ", a, b);
                if (pow(a, b) == x)
                {
                    ans++;

                    // printf("yes\n");

                    flag = true;
                    break;
                }
            }
            // printf("no\n");
            if (flag)
                break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
