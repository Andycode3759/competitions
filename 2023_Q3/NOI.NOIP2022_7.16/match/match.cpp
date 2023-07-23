#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ulong;
const int MAXN = 3003;
const int MAX_LOG = 19;

inline const int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        res = res * 10 + c - '0', c = getchar();
    return res;
}

inline const int max(const int &a, const int &b)
{
    return a < b ? b : a;
}

int id;
int n;
int pwrA[MAXN], pwrB[MAXN];
int q;
int ql[MAXN], qr[MAXN];
int stMaxA[MAX_LOG][MAXN], stMaxB[MAX_LOG][MAXN];
int lg2[MAXN];
ulong sum[MAXN][MAXN];

inline int getMaxA(int l, int r)
{
    int lg = lg2[r - l + 1];
    return max(stMaxA[lg][r], stMaxA[lg][l + (1 << lg) - 1]);
}
inline int getMaxB(int l, int r)
{
    int lg = lg2[r - l + 1];
    return max(stMaxB[lg][r], stMaxB[lg][l + (1 << lg) - 1]);
}

int main()
{
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);

    // scanf("%d%d", &id, &n);
    id = read(), n = read();

    lg2[1] = 0;
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i >> 1] + 1;

    for (int i = 1; i <= n; i++)
        // scanf("%d", pwrA + i), stMaxA[0][i] = pwrA[i];
        pwrA[i] = read(), stMaxA[0][i] = pwrA[i];
    for (int i = 1; i <= n; i++)
        // scanf("%d", pwrB + i), stMaxB[0][i] = pwrB[i];
        pwrB[i] = read(), stMaxB[0][i] = pwrB[i];
    // scanf("%d", &q);
    q = read();
    for (int i = 1; i <= q; i++)
        // scanf("%d%d", ql + i, qr + i);
        ql[i] = read(), qr[i] = read();

    for (int lg = 1, len = 2; len <= n; lg++, len = (len << 1))
    {
        int halfLen = len >> 1;
        for (int i = n; i > halfLen; i--)
        {
            stMaxA[lg][i] = max(stMaxA[lg - 1][i], stMaxA[lg - 1][i - halfLen]);
            stMaxB[lg][i] = max(stMaxB[lg - 1][i], stMaxB[lg - 1][i - halfLen]);
        }
    }

    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            sum[l][r] = sum[l][r - 1] + getMaxA(l, r) * getMaxB(l, r);
        }
    }

    for (int i = 1; i <= q; i++)
    {
        ulong res = 0;
        int l = ql[i], r = qr[i];
        for (int i = l; i <= r; i++)
        {
            res += sum[i][r];
        }
        printf("%llu\n", res);
    }
    return 0;
}
