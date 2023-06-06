// AC
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100005;

vector<int> dc;

struct SegTreeNode
{
    int l, r;
    long long val;
};
SegTreeNode st[MAXN << 2];

void build(int l, int r, int idx)
{
    SegTreeNode &node = st[idx];
    node.l = l, node.r = r;
    node.val = 0;
    if (l == r)
        return;

    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, (idx << 1) | 1);
}
void add(int num, int idx)
{
    SegTreeNode &node = st[idx];
    node.val++;
    if (node.l == node.r)
        return;

    int nmid = (node.l + node.r) >> 1;
    if (num <= nmid)
        add(num, idx << 1);
    else
        add(num, (idx << 1) | 1);
}
long long getSum(int l, int r, int idx)
{
    if (l <= 0 || r <= 0)
        return 0;
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        return node.val;
    }

    int nmid = (node.l + node.r) >> 1;
    long long res = 0;
    if (l <= nmid)
        res += getSum(l, r, idx << 1);
    if (r > nmid)
        res += getSum(l, r, (idx << 1) | 1);
    return res;
}

int n;
int arr[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        dc.push_back(arr[i]);
    }

    sort(dc.begin(), dc.end());
    unique(dc.begin(), dc.end());
    build(1, dc.size(), 1);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = lower_bound(dc.begin(), dc.end(), arr[i]) - dc.begin() + 1;
    }

    long long res = 0;
    for (int i = n; i >= 1; i--)
    {
        add(arr[i], 1);
        res += getSum(1, arr[i] - 1, 1);
    }
    printf("%lld\n", res);
    return 0;
}