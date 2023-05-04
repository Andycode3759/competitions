// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 22;
const int MAXW = 1e5 + 1;
int stones[MAXN];
bool sumable[MAXN * MAXW];

int main()
{
    memset(sumable, 0, sizeof(sumable));
    int n;
    scanf("%d", &n);
    int sum = 0, maxStone = -1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", stones + i);
        sum += stones[i];
        maxStone = max(maxStone, stones[i]);
        // sumable[stones[i]] = true;
    }

    sumable[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= stones[i]; j--)
        {
            sumable[j] = sumable[j] || sumable[j - stones[i]];
        }
    }

    // debug start
    // for (int i = 0; i <= 10086; i++)
    // {
    //     if (sumable[i])
    //     {
    //         printf("%d  ", i);
    //     }
    // }
    // printf("\n");
    // debug end

    int ans = -1;
    for (int j = sum; j >= 0; j--)
    {
        if (!sumable[j])
            continue;
        int pileA = j, pileB = sum - j;
        int diff = pileA - pileB;
        if (diff > ans && diff <= maxStone)
            ans = diff;
    }

    printf("%d\n", ans);

    return 0;
}
