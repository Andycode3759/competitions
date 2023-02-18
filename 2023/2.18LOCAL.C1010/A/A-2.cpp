// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXM = 105;
const int INF = (1 << 20) - 1;
int minDiff[MAXM][2];
int coins[MAXM];

int minByAbs(int a, int b)
{
    return abs(a) < abs(b) ? a : b;
}
int maxByAns(int a, int b)
{
    return abs(a) > abs(b) ? a : b;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(minDiff, 0, sizeof(minDiff));
        memset(coins, 0, sizeof(coins));
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", coins + i);
        }
        // minDiff[0][0] = minDiff[0][1] = INF;

        for (int i = 1; i <= m; i++)
        {
            printf("i=%d  ", i);

            for (int j = 0; j <= 1; j++)
            {
                int expectA = minByAbs(minDiff[i - 1][0], minDiff[i - 1][1]) + coins[i];
                int expectB = minByAbs(minDiff[i - 1][0], minDiff[i - 1][1]) - coins[i];
                bool betterForA = abs(expectA) < abs(expectB);
                betterForA = (j == 1) ? !betterForA : betterForA;
                if (betterForA)
                    minDiff[i][j] = expectA;
                else
                    minDiff[i][j] = expectB;

                printf("%d  ", minDiff[i][j]);
                if (j == 1)
                    printf("\n");
            }
        }

        printf("%d\n", abs(minByAbs(minDiff[m][0], minDiff[m][1])));
    }
    return 0;
}
