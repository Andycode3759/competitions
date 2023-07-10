#include <cstdio>
using namespace std;
const int MAXN = 500005;

int inCnt[MAXN], inCntExist[MAXN], sum;
int n, m, q;

int main()
{
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);

    scanf("%d%d", &n, &m);
    int op, u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        inCnt[u]++, inCntExist[u]++;
        sum += inCnt[u];
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &op);
        if (op == 1 || op == 3)
        {
            scanf("%d%d", &u, &v);
            if (op == 1)
                inCnt[u]--, sum--;
            else // op == 3
                inCnt[u]++, sum++;
        }
        else
        {
            scanf("%d", &u);
            if (op == 2)
            {
                if (inCnt[u] > 0)
                {
                    sum -= inCnt[u];
                    inCnt[u] = 0;
                }
            }
            else // op == 4
            {
                inCnt[u] = inCntExist[u];
                sum += inCnt[u];
            }
        }
        printf(sum == n ? "YES\n" : "NO\n");
    }
    return 0;
}