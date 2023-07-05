#include <cstdio>
using namespace std;
const int MAXN = 505;
const int MAXM = 124758;

struct Node
{
    int l, r;
};

int n, m;
int ans[MAXM]; // 上一次念的是第i个8g
Node op[MAXM];

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &op[i].l, &op[i].r);
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // ans[i]=...ans[j]...
            }
        }
    }
    return 0;
}
