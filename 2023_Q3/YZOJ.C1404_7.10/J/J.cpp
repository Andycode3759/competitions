// AC
#include <cstdio>
using namespace std;
const int MAXN = 102;
const int MAXM = 100005;

inline int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        res = res * 10 + c - '0', c = getchar();
    return res;
}

int n, m;
int val[MAXN], cnt;
int coins[MAXM], coinsCnt = 0;
bool isOk[MAXM];

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        if (m == 0 && n == 0)
            break;
        coinsCnt = 0;
        for (int i = 1; i <= n; i++)
            val[i] = read();
        for (int i = 1; i <= n; i++)
        {
            cnt = read();
            int mult = 1;
            while (cnt >= mult)
            {
                coins[coinsCnt++] = mult * val[i];
                cnt -= mult;
                mult = mult << 1;
            }
            if (cnt > 0)
                coins[coinsCnt++] = cnt * val[i];
        }

        for (int i = 1; i <= m; i++)
            isOk[i] = false;
        isOk[0] = true;
        for (int i = 0; i < coinsCnt; i++)
        {
            for (int j = m; j >= coins[i]; j--)
            {
                isOk[j] = isOk[j] || isOk[j - coins[i]];
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (isOk[i])
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
