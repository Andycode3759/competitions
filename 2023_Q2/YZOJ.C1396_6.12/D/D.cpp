// AC
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 100005;
const int INF = (1 << 30) - 1;
const int CASH[] = {0, 1, 2, 5, 7, 10, 20, 50, 70, 100};

int n;
int ans[MAXN];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        ans[i] = INF;
        for (int c = 1; c <= 9; c++)
        {
            if (i >= CASH[c])
                ans[i] = min(ans[i], ans[i - CASH[c]] + 1);
            else
                break;
        }
    }
    printf("%d\n", ans[n]);

    return 0;
}
