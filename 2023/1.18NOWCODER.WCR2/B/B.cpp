// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    scanf("%d", &K);
    while (K--)
    {
        int n;
        int l1, r1, l2, r2;
        scanf("%d%d%d%d%d", &n, &l1, &r1, &l2, &r2);
        int revL2 = n - r2, revR2 = n - l2;
        int tl = max(l1, revL2), tr = min(r1, revR2);
        int ans = max(0, tr - tl + 1);
        printf("%d\n", ans);
    }
    return 0;
}
