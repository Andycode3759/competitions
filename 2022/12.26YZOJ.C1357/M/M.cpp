// ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const int MAXCOUNT = 200006;
int n;       // ore count
int m;       // range count
long long s; // standard value
struct Ore
{
    Ore(long long _w = 0, long long _v = 0)
    {
        weight = _w;
        value = _v;
    }
    long long weight, value;
};
struct Range
{
    int left, right;
};
Ore ores[MAXCOUNT];
Ore sortedOres[MAXCOUNT];
Range ranges[MAXCOUNT];
Ore presum[MAXCOUNT];

long long getQuality(int W)
{
    for (int i = i; i <= n; i++)
    {
        presum[i] = Ore(0, 0);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ores[i].weight >= W)
        {
            presum[i].weight = presum[i - 1].weight + 1;
            presum[i].value = presum[i - 1].value + ores[i].value;
        }
        else
        {
            presum[i] = presum[i - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        long long count, value;
        count = presum[ranges[i].right].weight - presum[ranges[i].left - 1].weight;
        value = presum[ranges[i].right].value - presum[ranges[i].left - 1].value;
        res += count * value;
    }
    return res;
}

bool cmp(Ore a, Ore b)
{
    return a.weight > b.weight;
}

int main()
{

    scanf("%d%d%lld", &n, &m, &s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &ores[i].weight, &ores[i].value);
        sortedOres[i] = ores[i];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &ranges[i].left, &ranges[i].right);
    }
    sort(sortedOres + 1, sortedOres + n + 1, cmp);
    // 二分W
    long long ans = -1, rec;
    int l = 0, r = sortedOres[1].weight;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        long long q = getQuality(mid);
        if ((abs(q - s) < ans && q > 0) || ans < 0)
        {
            // printf("New Record: W=%d => Y=%lld\n", mid, q);

            ans = abs(q - s);
            rec = mid;
        }
        if (q > s || q < 0) // q<0 => overflow, much bigger than s
        {
            l = mid + 1;
        }
        else if (q < s)
        {
            r = mid - 1;
        }
        else // q==s nice
        {
            ans = 0;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
