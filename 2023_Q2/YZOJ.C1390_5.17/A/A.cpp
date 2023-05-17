// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 1000000009;

struct Line
{
    int l, r;

    const bool operator<(const Line &a) const
    {
        return (l == a.l) ? r < a.r : l < a.l;
    }
};

Line lines[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &lines[i].l, &lines[i].r);
    }
    sort(lines, lines + n);

    Line last;
    last.l = -INF, last.r = -INF;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        Line &l = lines[i];
        if (l.l >= last.l && l.r <= last.r)
        {
            continue;
        }
        else if (l.l >= last.l && l.l < last.r)
        {
            ans += l.r - last.r;
            last.r = l.r;
        }
        else
        {
            ans += l.r - l.l;
            last = l;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
