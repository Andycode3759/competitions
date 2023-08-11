#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int MAXN = 505;
constexpr int MOD = 1e9 + 7;
constexpr int PRIME[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,
                         71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
                         167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
                         271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383,
                         389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
constexpr int MULT = 318608048;

inline int quickPow(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = (1LL * a * a) % MOD)
    {
        if (b & 1)
        {
            ret = 1LL * ret * a % MOD;
        }
    }
    return ret;
}
inline int getinv(int x)
{
    return quickPow(x, MOD - 2);
}

int n;
bool bugu[MAXN][500005];
int len[MAXN];
char input[55];

int fcnt[MAXN], mcnt[MAXN];
int cnt[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int l;
        scanf("%d", &l);
        len[i] = l;
        scanf("%s", input + 1);
        for (int j = 1; j <= l; j++)
        {
            bugu[i][j] = (input[j] == 'O');
        }

        int p = 0;
        while (l > 1)
        {
            if (l % PRIME[p] == 0)
                fcnt[p]++, l /= PRIME[p];
            else
                p++;
        }

        for (int i = 0; i < 95; i++)
        {
            mcnt[i] = max(mcnt[i], fcnt[i]);
            fcnt[i] = 0;
        }
    }

    long long lcm = 1;
    for (int i = 0; i < 95; i++)
    {
        while (mcnt[i] > 0)
            lcm *= PRIME[i], mcnt[i]--;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = len[i] + 1; j <= lcm; j++)
        {
            int r = j % len[i];
            if (r == 0)
                r = len[i];
            bugu[i][j] = bugu[i][r];
        }
    }

    for (int i = 1; i <= lcm; i++)
    {
        int c = 0;
        for (int j = 1; j <= n; j++)
        {
            c += bugu[j][i];
        }
        cnt[c] = (cnt[c] + MULT) % MOD;
    }

    int inv = getinv(lcm);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", (1LL * cnt[i] * inv) % MOD);
    }
    return 0;
}