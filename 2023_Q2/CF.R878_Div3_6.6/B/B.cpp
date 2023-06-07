// AC
// Fixed:2023.6.7
#include <algorithm>
#include <cstdio>
using namespace std;
int n, k;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        if (k > 30)
            k = 30;
        printf("%d\n", min(n + 1, 1 << k));
    }
    return 0;
}
