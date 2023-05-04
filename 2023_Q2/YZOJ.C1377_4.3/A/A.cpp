// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
const int MOD = 1e9 + 7;
const int MAX_LOGM = 61;

int n, k;
long long m;
int arr[MAXN];

int force()
{
    int step = 1;
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        // printf("step=%d\n", step);
        sum += arr[step];
        if (sum >= MOD)
            sum -= MOD;
        step = (step + k) % n + 1;
    }
    return sum % MOD;
}

int nextLg[MAX_LOGM][MAXN];
int sumLg[MAX_LOGM][MAXN];
int modAdd(int a, int b)
{
    if (a + b >= MOD)
        return a + b - MOD;
    else
        return a + b;
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        nextLg[0][i] = (i + k) % n + 1;
        sumLg[0][i] = arr[i];
    }
    for (int lg = 1; lg < MAX_LOGM; lg++)
    {
        for (int i = 1; i <= n; i++)
        {
            nextLg[lg][i] = nextLg[lg - 1][nextLg[lg - 1][i]];
            sumLg[lg][i] = modAdd(sumLg[lg - 1][i], sumLg[lg - 1][nextLg[lg - 1][i]]);
        }
    }
}
int trueAns()
{
    int sum = 0, step = 1;
    for (int b = 0; m > 0; b++)
    {
        if (((1LL << b) & m) == 0)
            continue;
        m -= (1LL << b);
        sum = modAdd(sum, sumLg[b][step]);
        step = nextLg[b][step];
    }
    return sum % MOD;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    scanf("%lld", &m);

    // printf("%d\n", force());
    init();
    printf("%d\n", trueAns());
    return 0;
}