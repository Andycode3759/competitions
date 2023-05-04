#include <bits/stdc++.h>
using namespace std;
const char MSG_YES[] = "Divisible";
const char MSG_NO[] = "Not divisible";
const int MAXN = 10086;
int arr[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", arr + i);
        }
        int signs = 0;
        bool flag = true;
        while (signs < (1 << n + 1))
        {
            long long sum = 0;
            for (int i = 0; i <= n; i++)
            {
                sum += (signs & (1 << i)) ? arr[i] : -arr[i];
            }
            if (sum % k == 0)
            {
                printf("%s\n", MSG_YES);
                flag = false;
                break;
            }
            signs++;
        }
        if (flag)
        {
            printf("%s\n", MSG_NO);
        }
    }
    return 0;
}
