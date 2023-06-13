#include <cmath>
#include <cstdio>
using namespace std;
const int SP = 8;
const int MOD = 1e9 + 9;
const int MAXN = 1000006;

int n, m;

int solveSP1() // n<=8, m<=8
{
    int mx = pow(m, n);
    int res = 0;
    for (int i = 1; i <= mx; i++)
    {
        int a = i;
        for (int j = 1; j <= n; j++)
        {
            if (a % m == 0)
                a /= m;
            else
                a++;
        }
        if (a == 1)
            res++;
        if (res >= MOD)
            res -= MOD;
    }
    return res;
}

int solveSP2() // m=2
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = (res << 1) % MOD;
    }
    return res;
}
int solveGeneral()
{
    return 0;
}

int main()
{
    freopen("func.in", "r", stdin);
    // freopen("func.out", "w", stdout);

    scanf("%d%d", &m, &n);
    if (n <= SP && m <= SP)
    {
        printf("%d\n", solveSP1());
    }
    else if (m == 2)
    {
        printf("%d\n", solveSP2());
    }
    else
    {
        printf("%d\n", solveGeneral());
    }

    return 0;
}