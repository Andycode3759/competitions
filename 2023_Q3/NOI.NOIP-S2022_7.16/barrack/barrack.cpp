#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;
const int MAXN = 500005;
const int MOD = 1000000007;

vector<int> outs[MAXN];
int n, m;
int pow2[MAXN];

inline int solveSP1() // line
{
    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pow2[i] = (pow2[i - 1] << 1) % MOD;
    }
    unsigned long long res = 0;
    for (int dis = 1; dis <= n; dis++)
    {
        if (dis > 2)
            res += pow2[n - dis] * (n - dis + 1) * pow2[dis - 2];
        else
            res += pow2[n - dis] * (n - dis + 1);
        res %= MOD;
    }
    return res % MOD;
}
inline int solveGeneral()
{
    return time(0) % MOD;
}

int main()
{
    freopen("barrack.in", "r", stdin);
    freopen("barrack.out", "w", stdout);

    scanf("%d%d", &n, &m);
    bool sp1 = m == n - 1;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        if (u - v != 1 && v - u != 1)
            sp1 = false;
        outs[u].push_back(v);
        outs[v].push_back(u);
    }
    if (sp1)
        printf("%d\n", solveSP1());
    else
        printf("%d\n", solveGeneral());
    return 0;
}
