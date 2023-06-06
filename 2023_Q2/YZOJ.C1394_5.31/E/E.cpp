// TLE: 67%
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
const int INF = (1 << 30) - 1;

int dc[MAXN];
int dcSize;
struct SegTreeNode
{
    int val = 0;
    int lc = -1, rc = -1;
};
SegTreeNode st[MAXN * 21];
int nodeCnt;
int roots[MAXN];

// 新建一颗树，根节点表示[l,r]区间。
// 返回新树的根节点指针。
int build(int l, int r)
{
    int root = ++nodeCnt;
    SegTreeNode &node = st[root];
    node.val = 0;
    if (l == r)
        return root;

    int mid = (l + r) >> 1;
    node.lc = build(l, mid);
    node.rc = build(mid + 1, r);

    return root;
}

// 在以pre为根节点的线段树为初始状态的情况下，插入数据k并根据需要新建节点，产生一颗新树。
// l,r是当前节点的左右端点。
// 返回新树的根节点指针。
int update(int pre, int k, int l, int r)
{
    int cur = ++nodeCnt;
    SegTreeNode &node = st[cur], &preNode = st[pre];
    node.lc = preNode.lc, node.rc = preNode.rc;
    node.val = preNode.val + 1;
    if (l == r)
        return cur;

    int nmid = (l + r) >> 1;
    if (k <= nmid)
        node.lc = update(preNode.lc, k, l, nmid);
    else
        node.rc = update(preNode.rc, k, nmid + 1, r);
    return cur;
}

// 在以root为根节点的树中查询小于等于k的数的个数。
// l,r是当前节点的左右端点。
int query(int root, int k, int l, int r)
{
    SegTreeNode &node = st[root];

    // printf("query: [%d,%d]\n", node.l, node.r);

    if (l == r)
    {
        return l <= k ? node.val : 0;
    }
    int nmid = (l + r) >> 1;
    int res = 0;
    res += query(node.lc, k, l, nmid);
    if (k > nmid)
        res += query(node.rc, k, nmid + 1, r);
    return res;
}

int n, m;
int arr[MAXN];

void initCase()
{
    memset(arr, 0, sizeof(arr));
    n = 0, m = 0;
    nodeCnt = 0;
    memset(roots, 0, sizeof(roots));
    memset(dc, 0, sizeof(dc));
    dcSize = 1;
}

int main()
{
    int T, K;
    scanf("%d", &T);
    for (K = 1; K <= T; K++)
    {
        initCase();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", arr + i);
            dc[dcSize++] = arr[i];
        }
        sort(dc + 1, dc + dcSize);
        dcSize = unique(dc + 1, dc + dcSize) - dc - 1;

        roots[0] = build(1, dcSize);
        for (int i = 1; i <= n; i++)
        {
            int idx = lower_bound(dc + 1, dc + 1 + dcSize, arr[i]) - dc;
            roots[i] = update(roots[i - 1], idx, 1, dcSize);
        }

        // for (int i = 1; i <= nodeCnt; i++)
        // {
        //     SegTreeNode &node = st[i];
        //     printf("Node #%d: [%d,%d] lc=%d rc=%d val=%d\n", i, node.l, node.r, node.lc, node.rc, node.val);
        // }
        // for (int i = 0; i <= n; i++)
        // {
        //     printf("Root #%d = %d\n", i, roots[i]);
        // }

        int l, r, k;
        printf("Case %d:\n", K);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &l, &r, &k);
            l++, r++;
            int idx = upper_bound(dc + 1, dc + 1 + dcSize, k) - dc - 1;

            // printf("idx=%d\n", idx);
            // printf("r=%d l=%d\n", query(roots[q.r], idx), query(roots[q.l - 1], idx));

            printf("%d\n", query(roots[r], idx, 1, dcSize) - query(roots[l - 1], idx, 1, dcSize));
        }
    }
    return 0;
}
