#include <bits/stdc++.h>
using namespace std;
const int MOD = 12580;
const int MAXN = 1005;

bool isBomb[MAXN];

int planCount[MAXN];

int main()
{
    memset(isBomb, false, sizeof(isBomb));
    memset(planCount, 0, sizeof(planCount));
    planCount[0] = 1;
    int n, m;
    scanf("%d%d", &n, &m);
    int input;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &input);
        isBomb[input] = true;
    }
    if (isBomb[0])
    {
        printf("-1\n");
        return 0;
    }

    for (int dest = 1; dest <= n; dest++)
    {
        if (isBomb[dest])
        {
            planCount[dest] = 0;
            continue;
        }
        for (int step = 1; step <= 3; step++)
        {
            int source = dest - step;
            if (source >= 0)
                planCount[dest] = (planCount[dest] + planCount[source]) % MOD;
        }
    }
    printf("%d\n", (planCount[n] == 0) ? -1 : planCount[n]);

    // planCount[i]=planCount[i-1]+planCount[i-2]+planCount[i-3];

    return 0;
}
