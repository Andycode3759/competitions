#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int MAXN = 1000006;

int arr[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", arr + i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            ans = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (arr[i] == 1)
        {
            ans = min(ans, n - i + 1);
            break;
        }
    }

    printf("%d\n", n - (ans - 1) * 2);

    return 0;
}