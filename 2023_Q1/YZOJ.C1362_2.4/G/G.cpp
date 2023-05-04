#include <bits/stdc++.h>
using namespace std;
const int MAXS = 1e5 + 5;
int coins[4];

vector<int> items;
int ans[MAXS];

int getAns(int leftover)
{
    int &curAns = ans[leftover];
    if (curAns != -1)
        return curAns;

    curAns = -100;
    
}

int main()
{
    int n;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", coins + i);
    }
    scanf("%d", &n);
    while (n--)
    {
        vector<int>().swap(items);
        memset(ans, -1, sizeof(ans));
        // int amount[4];
        int price;
        for (int i = 0; i < 4; i++)
        {
            int amount;
            scanf("%d", &amount);
            // splitItem(amount, coins[i]);
        }
        scanf("%d", &price);

        for (int i = 1; i <= items.size(); i++)
        {
            for (int j = 1; j <= price; j++)
            {
                maxValue[i][j] = maxValue[i - 1][j];
                if (j - items[i] >= 0)
                {
                    maxValue[i][j] = max(maxValue[i][j], maxValue[i - 1][j - items[i]] + items[i]);
                }
            }
        }
    }
    return 0;
}
