// WA 9%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6006;
typedef vector<int>::iterator intIter;

int happiness[MAXN];
bool hasBoss[MAXN];
int maxHappiness[MAXN][2];
vector<int> childrenOf[MAXN];

int getMaxHappinessFrom(int root, bool containsRoot)
{
    int cr = containsRoot ? 1 : 0;
    if (maxHappiness[root][cr] >= 0)
        return maxHappiness[root][cr];
    int &ans = maxHappiness[root][cr];

    if (childrenOf[root].empty())
    {
        return ans = containsRoot ? happiness[root] : 0;
    }

    if (containsRoot)
    {
        ans = happiness[root];
        for (intIter child = childrenOf[root].begin(); child != childrenOf[root].end(); child++)
        {
            ans += getMaxHappinessFrom(*child, false);
        }
    }
    else
    {
        ans = 0;
        for (intIter child = childrenOf[root].begin(); child != childrenOf[root].end(); child++)
        {
            ans += max(ans, max(getMaxHappinessFrom(*child, true), getMaxHappinessFrom(*child, false)));
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", happiness + i);
    }
    int boss, child;
    while (scanf("%d%d", &child, &boss) == 2 && child != 0 && boss != 0)
    {
        childrenOf[boss].push_back(child);
        hasBoss[child] = true;
    }

    int root;
    for (int i = 1; i <= n; i++)
    {
        if (!hasBoss[i])
        {
            root = i;
            break;
        }
    }

    memset(maxHappiness, -1, sizeof(maxHappiness));
    printf("%d\n", max(getMaxHappinessFrom(root, true), getMaxHappinessFrom(root, false)));

    return 0;
}
