// AC
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 500005;
const int MAX_LOG = 24;

struct Node
{
    int dest, ans;
};

int n, k;
Node edges[MAXN];
Node st[MAX_LOG][MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &edges[i].dest);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &edges[i].ans);
    }

    for (int i = 1; i <= n; i++)
    {
        st[0][i].ans = edges[i].ans;
        st[0][i].dest = edges[i].dest;
        // printf("st[0][%d]=(%d,%d)\n", i, st[0][i].ans, st[0][i].dest);
    }
    for (int lg = 1; (1 << (lg - 1)) <= k; lg++)
    {
        for (int i = 1; i <= n; i++)
        {
            st[lg][i].ans = max(st[lg - 1][i].ans, st[lg - 1][st[lg - 1][i].dest].ans);
            st[lg][i].dest = st[lg - 1][st[lg - 1][i].dest].dest;
            // printf("st[%d][%d]=(%d,%d)\n", lg, i, st[lg][i].ans, st[lg][i].dest);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int ans = 0, step = k, lg = 0, cur = i;
        while (step > 0)
        {
            if (step & 1 == 1)
            {
                ans = max(ans, st[lg][cur].ans);
                cur = st[lg][cur].dest;
            }
            step = (step >> 1), lg++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
