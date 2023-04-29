// AC
// Fixed: 2023/4/22
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 27;

int n;
int sticks[MAXN];
bool mark[MAXN];

bool isTri(int a, int b, int c)
{
    return a + b > c && a + c > b && b + c > a;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        memset(mark, false, sizeof(mark));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", sticks + i);
        }
        sort(sticks, sticks + n);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (mark[i] || mark[j] || mark[k])
                        continue;
                    if (isTri(sticks[i], sticks[j], sticks[k]))
                    {
                        ans++;
                        mark[i] = true;
                        mark[j] = true;
                        mark[k] = true;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
