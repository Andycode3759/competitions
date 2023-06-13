// AC
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 100005;
const int INF = (1 << 30) - 1;
const int CASH[] = {0, 100, 70, 50, 20, 10, 7, 5, 2, 1};

bool mark[MAXN];

int n;
int ans[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 9; i++)
        mark[CASH[i]] = true;

    for (int i = 1; i <= n; i++)
    {
        ans[i] = INF;
        if (mark[i])
        {
            ans[i] = 1;
            continue;
        }

        for (int c = 1; c <= 9; c++)
        {
            if (i - CASH[c] >= 0)
                ans[i] = min(ans[i], ans[i - CASH[c]] + 1);
        }
    }
    printf("%d\n", ans[n]);

    return 0;
}
