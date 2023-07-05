// AC
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 55;
const double INF = (1LL << 50);

struct Hand
{
    int len, dr;
    int tFwd, tBak;
};
Hand hands[MAXN];
double ans[MAXN][2];
int n;
long long t1, t2, t;

int main()
{
    scanf("%d", &n);
    hands[0].dr = 60;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &hands[i].dr);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &hands[i].len);
    }
    scanf("%lld%lld", &t1, &t2);
    t = abs(t1 - t2);

    for (int i = 0; i < n; i++)
    {
        Hand &h = hands[i];
        h.tFwd = t % h.dr;
        h.tBak = h.dr - h.tFwd;
        t /= h.dr;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     Hand &h = hands[i];
    //     printf("i=%d len=%d dr=%d fwd=%d bak=%d\n", i, h.len, h.dr, h.tFwd, h.tBak);
    // }

    for (int i = 0; i <= n; i++)
    {
        ans[i][0] = ans[i][1] = INF;
    }
    ans[0][0] = 0;

    long long dd = 1;
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        dd *= hands[i].dr;
        if (dd * hands[cnt].len > hands[i].len)
        {
            hands[++cnt] = hands[i];
            dd = 1;
        }
        else
        {
            hands[cnt].tFwd += hands[i].tFwd * dd * hands[cnt].dr / hands[i].dr;
            hands[cnt].tBak += (hands[i].tBak - 1) * dd * hands[cnt].dr / hands[i].dr;
        }
    }
    n = cnt + 1;

    for (int i = 1; i <= n; i++)
    {
        for (int dir = 0; dir <= 1; dir++)
        {
            int t = hands[i - 1].tFwd + dir;
            ans[i][0] = min(ans[i][0], ans[i - 1][dir] + 1.0 * t * hands[i - 1].len / hands[i - 1].dr);
            t = hands[i - 1].tBak - dir;
            ans[i][1] = min(ans[i][1], ans[i - 1][dir] + 1.0 * t * hands[i - 1].len / hands[i - 1].dr);
        }
    }

    printf("%.5lf\n", min(ans[n][0], ans[n][1]) * 2 * M_PI);
    return 0;
}
