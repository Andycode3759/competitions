// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXM = 105;
bool sumable[MAXM * 500];
int coins[MAXM];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(sumable, 0, sizeof(sumable));
        memset(coins, 0, sizeof(coins));
        int m;
        scanf("%d", &m);
        int sum = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", coins + i);
            sum += coins[i];
        }

        sumable[0] = true;
        for (int i = 1; i <= m; i++)
        {
            for (int j = sum; j >= coins[i]; j--)
            {
                sumable[j] = sumable[j] || sumable[j - coins[i]];
            }
        }

        int ans;

        for (int valA = 0; valA <= sum / 2; valA++)
        {
            if (sumable[valA] && sumable[sum - valA])
            {
                ans = valA * 2 - sum;
            }
        }

        printf("%d\n", abs(ans));
    }
    return 0;
}
