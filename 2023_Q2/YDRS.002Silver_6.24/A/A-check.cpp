#include <cstdio>
using namespace std;
const int MAXN = 1000006;

int n;
int arr[MAXN << 1];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[n + i] = arr[i];
    }
    long long ans = 0;

    for (int len = 2; len <= n; len += 2)
    {
        for (int l = 1, r = l + len - 1; l <= n; l++, r++)
        {
            int cntOdd = 0, cntEve = 0;
            for (int i = l; i <= r; i++)
            {
                if (arr[i] % 2 == 0)
                    cntEve++;
                else
                    cntOdd++;
            }
            if (cntEve == cntOdd)
                ans++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
