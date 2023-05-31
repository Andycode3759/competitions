#include <cstdio>
using namespace std;
const int MAXN = 1000006;

struct SegTreeNode
{
    int l, r;
    long long sum = 0;
    long long mark = 0;
};

int arr[MAXN];
int n, q;
SegTreeNode st[MAXN << 2];

void gatherUp(int idx)
{
    SegTreeNode &nd = st[idx];
    nd.sum = st[idx * 2].sum + st[idx * 2 + 1].sum;
}
void passDown(int idx)
{
    SegTreeNode &nd = st[idx];
    SegTreeNode &lc = st[idx * 2], &rc = st[idx * 2 + 1];
    lc.sum += (lc.r - lc.l + 1) * nd.mark;
    rc.sum += (rc.r - rc.l + 1) * nd.mark;
    lc.mark += nd.mark, rc.mark += nd.mark;
    nd.mark = 0;
}
void build(int l, int r, int idx)
{
    SegTreeNode &nd = st[idx];
    nd.l = l, nd.r = r;
    if (l == r)
    {
        nd.sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    gatherUp(idx);
}
void update(int l, int r, long long dlt, int idx)
{
    SegTreeNode &nd = st[idx];
    if (nd.l >= l && nd.r <= r)
    {
        nd.sum += (nd.r - nd.l + 1) * dlt;
        nd.mark += dlt;
        return;
    }
    passDown(idx);
    int nmid = (nd.r + nd.l) >> 1;
    if (l <= nmid)
        update(l, r, dlt, idx * 2);
    if (r > nmid)
        update(l, r, dlt, idx * 2 + 1);
    gatherUp(idx);
}
long long query(int l, int r, int idx)
{
    SegTreeNode &nd = st[idx];
    if (nd.l >= l && nd.r <= r)
    {
        return nd.sum;
    }
    passDown(idx);
    long long res = 0;
    int nmid = (nd.r + nd.l) >> 1;
    if (l <= nmid)
        res += query(l, r, idx * 2);
    if (r > nmid)
        res += query(l, r, idx * 2 + 1);
    return res;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    build(1, n, 1);
    while (q--)
    {
        int op, l, r, x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &l, &r, &x);
            update(l, r, x, 1);
        }
        else if (op == 2)
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r, 1));
        }
    }
    return 0;
}
