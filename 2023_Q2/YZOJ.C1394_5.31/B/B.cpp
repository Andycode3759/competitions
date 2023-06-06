// AC
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100005;

vector<int> xs;

struct Operation
{
    int op;
    int x;
    /*
        1 插入
        2 删除
        3 查询x的排名
        4 查询排名为x的数
        5 求小于x的最大数
        6 求大于x的最小数
    */
};
Operation ops[MAXN];

struct SegTreeNode
{
    int l, r;
    int val;
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
void add(int num, int dlt, int idx)
{
    SegTreeNode &node = st[idx];
    if (node.l == node.r)
    {
    	node.val += dlt;
    	return;
	}

    int nmid = (node.l + node.r) >> 1;
    if (num <= nmid)
        add(num, dlt, idx << 1);
    else
        add(num, dlt, (idx << 1) | 1);
    node.val = st[idx << 1].val + st[(idx << 1) | 1].val;
}
int getSum(int l, int r, int idx)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        return node.val;
    }

    int nmid = (node.l + node.r) >> 1;
    int res = 0;
    if (l <= nmid)
        res += getSum(l, r, idx << 1);
    if (r > nmid)
        res += getSum(l, r, (idx << 1) | 1);
    return res;
}
int getAt(int rank, int idx)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx << 1], &rc = st[(idx << 1) | 1];
    if (node.l == node.r)
        return node.l;

    if (rank <= lc.val)
        return getAt(rank, idx << 1);
    else
        return getAt(rank - lc.val, (idx << 1) | 1);
}

int n;

int main()
{
	xs.push_back(0);	// 占位
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &ops[i].op, &ops[i].x);
        if (ops[i].op != 4)
            xs.push_back(ops[i].x);
    }

    sort(xs.begin() + 1, xs.end());
    unique(xs.begin() + 1, xs.end());
    build(1, xs.size() - 1, 1);

    for (int i = 1; i <= n; i++)
    {
        Operation &co = ops[i];
        int slIdx;
        if (co.op != 4)
            slIdx = lower_bound(xs.begin() + 1, xs.end(), co.x) - xs.begin();

        int res, rank;
        switch (co.op)
        {
        case 1:
            add(slIdx, 1, 1);
            break;
        case 2:
            add(slIdx, -1, 1);
            break;
        case 3:
            res = getSum(1, slIdx - 1, 1);
            printf("%d\n", res + 1);
            break;
        case 4:
            printf("%d\n", xs[getAt(co.x, 1)]);
            break;
        case 5:
            rank = getSum(1, slIdx - 1, 1);
            printf("%d\n", xs[getAt(rank, 1)]);
            break;
        case 6:
            rank = getSum(1, slIdx, 1);
            printf("%d\n", xs[getAt(rank + 1, 1)]);
            break;
        }
    }
    return 0;
}