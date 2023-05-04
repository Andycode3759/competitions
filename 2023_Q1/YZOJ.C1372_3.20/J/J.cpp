// RE -70%
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 1000006;
int circle[MAXN];
int n;
int ans;

int notR[MAXN];

int force(int step) // 30%
{
    if (n == 1)
        return 3;

    if (step > n)
    {
        if (circle[n] == circle[1])
            return ans;
        else
            return ans = (ans + 1) % MOD;
    }
    for (int c = 1; c <= 3; c++)
    {
        if ((circle[step - 1] == c))
        {
            continue;
        }
        circle[step] = c;
        force(step + 1);
    }
    return ans;
}

int trueAns() // 30%
{
    /*
    r[i] => 树的第i层里r的数量
    n[i] => 数的第i层里不是r的数量
    这一层的r数 = 上一层不是r的数量
    这一层不是r的数量 = 这一层的总元素-r数

    r[i]=n[i-1]
    n[i]=2^(i-1)-r[i]

    n[i]=2^(i-1)-n[i-1]


    */
    notR[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        notR[i] = ((1 << (i - 1)) % MOD - notR[i - 1] % MOD) % MOD;
    }
    return (notR[n] * 3) % MOD;
}

int main()
{
    scanf("%d", &n);
    // printf("%d\n", force(1));
    printf("%d\n", trueAns());
    return 0;
}
