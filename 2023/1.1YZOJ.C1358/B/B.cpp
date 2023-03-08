// Fixed on 2023.1.2
// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 808;
int mapSize;
int cakes[MAXN][MAXN];
int minAvoidable = 1e9;

int main()
{
    long long cakeSum = 0;
    scanf("%d", &mapSize);
    for (int x = 1; x <= mapSize; x++)
    {
        for (int y = 1; y <= mapSize; y++)
        {
            int input;
            scanf("%d", &input);
            cakes[x][y] = input;
            cakeSum += input;
            if (x % 2 != y % 2) // 奇偶性不同，是可以放弃的点
            {
                minAvoidable = min(minAvoidable, input);
            }
        }
    }

    printf("%lld\n", mapSize % 2 == 1 ? cakeSum : cakeSum - minAvoidable);

    return 0;
}
