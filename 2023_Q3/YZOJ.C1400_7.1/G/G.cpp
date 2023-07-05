#include <cstdio>
using namespace std;

int n;

int main()
{
    int T;
    scanf("%d", &T);
    for (int Kase = 1; Kase <= T; Kase++)
    {
        scanf("%d", &n);
        if (n % 2 == 1)
        {
            printf("Case #%d: 0\n", Kase);
            continue;
        }
        n /= 2;
        long long ans = 0;
        for (int l = 1; l < n; l++)
        {
            int r = n - l;
                }
    }
    return 0;
}
