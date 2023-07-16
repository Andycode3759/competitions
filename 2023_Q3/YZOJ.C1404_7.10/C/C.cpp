#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 20004;
const int MAXM = 2003;
const int INF = (1 << 30) - 1;

constexpr const int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

int ans[MAXM][MAXM]; // ans[i][j] 倒数第一个黑球在i，倒数第二个黑球在j
int col[MAXN];
int n, m;

int getAns(int i, int j)
{
    if (i <= j)
        return INF;
    int &res = ans[i][j];
    if (res >= 0)
        return res;
    int minVal = INF;
    for (int k = i - m; k <= j - 1; k++)
        minVal = min(minVal, getAns(j, k));
    return res = minVal + col[i];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", col + i);

    memset(ans, -1, sizeof(ans));

    for (int i = 1; i <= m; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            ans[j][i] = col[i] + col[j];
        }
    }

    int res = INF;
    for (int i = n; i >= 1 && i >= n - m + 1; i--)
    {
        for (int j = i - 1; j >= 1 && j >= i - m + 1; j--)
        {
            res = min(res, getAns(i, j));
            // printf("%d\n", getAns(i, j));
        }
    }
    printf("%d\n", res);

    return 0;
}
