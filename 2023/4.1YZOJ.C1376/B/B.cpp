// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000007;
const int MAXA = 1001;

int n;
int a[MAXN], b[MAXN], prodCnt[MAXN];
int maxProd;

int force() // 30%
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] * b[i] == a[j] * b[j])
                ans++;
        }
    }
    return ans;
}

int trueAns() // AC
{
    int ans = 0;
    for (int i = 1; i <= maxProd; i++)
    {
        int x = prodCnt[i];
        ans += (x * x - x) / 2;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", a + i, b + i);
        prodCnt[a[i] * b[i]]++;
        maxProd = max(maxProd, a[i] * b[i]);
    }

    // printf("%d\n", force());
    printf("%d\n", trueAns());
    return 0;
}
