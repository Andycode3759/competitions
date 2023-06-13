// AC
// Fixed: 2023.6.10
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1000006;
const int INF = (1 << 30) - 1;

struct Node
{
    int val, idx;

    const bool operator<(const Node &a) const
    {
        return val < a.val;
    }
};

int arr[MAXN];
Node nodes[MAXN];
bool flag[MAXN];
int n, p;

int main()
{
    freopen("mst.in", "r", stdin);
    freopen("mst.out", "w", stdout);

    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        nodes[i].val = arr[i];
        nodes[i].idx = i;
    }
    sort(nodes + 1, nodes + 1 + n);

    long long contribute = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = nodes[i].val, xi = nodes[i].idx;

        // printf("x=%d xi=%d\n", x, xi);

        if (x >= p)
            break;
        if (flag[xi])
            continue;
        int l = xi, r = xi;
        for (; l >= 1 && arr[l] % x == 0; l--)
            flag[l] = true;
        flag[l++] = false;
        for (; r <= n && arr[r] % x == 0; r++)
            flag[r] = true;
        flag[r--] = false;
        contribute += 1LL * (r - l) * (p - x);

        // printf("chunk [%d,%d] gcd=%d\n", l, r, x);
    }

    printf("%lld\n", 1LL * p * (n - 1) - contribute);
    return 0;
}