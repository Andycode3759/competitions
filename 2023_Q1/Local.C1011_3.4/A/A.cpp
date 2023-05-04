// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 103;

struct Pearl
{
    Pearl(int h = 0, int t = 0)
    {
        head = h, tail = t;
    }
    int head, tail;
};

struct Result
{
    Result(int _s = -1, Pearl _l = Pearl())
    {
        sum = _s, leftover = _l;
    }
    int sum;
    Pearl leftover;
};

Pearl pearls[2 * MAXN];
Result maxEnergy[2 * MAXN][2 * MAXN];

int merge(Pearl a, Pearl b)
{
    return a.head * a.tail * b.tail;
}

Result getMaxEnergy(int left, int right)
{
    Result &ans = maxEnergy[left][right];
    if (ans.sum >= 0)
        return ans;

    ans = Result(0, Pearl(pearls[left].head, pearls[right].tail));
    if (left == right)
        return ans;
    // if (right - left == 1)
    //   return ans = merge(left, right);
    ans.sum = -1;
    // int cut = left;
    for (int k = left; k < right; k++)
    {
        Result resL = getMaxEnergy(left, k);
        Result resR = getMaxEnergy(k + 1, right);

        int totalSum = resL.sum + resR.sum + merge(resL.leftover, resR.leftover);
        if (totalSum > ans.sum)
        {
            ans.sum = totalSum;
            // cut = k;
        }
    }
    // printf("left=%d right=%d cut=%d ans=%d\n", left, right, cut, ans.sum);
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int input;
        scanf("%d", &input);
        pearls[i - 1].tail = pearls[i].head = input;
        pearls[i - 1 + n].tail = pearls[i + n].head = input;
    }
    // memset(maxEnergy, -1, sizeof(maxEnergy));
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, getMaxEnergy(i, i + n - 1).sum);
    }
    printf("%d\n", ans);
    return 0;
}
