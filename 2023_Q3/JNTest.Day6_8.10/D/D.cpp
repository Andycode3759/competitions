#include <algorithm>
#include <cstdio>
using namespace std;

int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    if (k == 2)
    {
        int cur = n - 1, ans = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            ans = max(ans, cur * i);
            cur--;
        }
        printf("%d\n", ans);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}