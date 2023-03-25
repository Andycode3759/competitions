// AC
#include <bits/stdc++.h>
using namespace std;
int x, y;
long long m;

int force()
{
    int cntN = 1, cntG = 1;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (cntG == cntN)
            ans++;

        cntN++;
        cntG++;
        if (cntN > x)
            cntN = 1;
        if (cntG > y)
            cntG = 1;
    }
    return ans;
}

int trueAns()
{
    int loop = x * y / __gcd(x, y);
    int ans = (m / loop) * min(x, y);
    long long cut = (m / loop) * loop;
    ans += min(m - cut, 1LL * min(x, y));
    return ans;
}

int main()
{
    scanf("%d%d%lld", &x, &y, &m);
    int ans;
    // ans = force();
    ans = trueAns();
    printf("%d\n", ans);
    return 0;
}
