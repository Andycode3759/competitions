// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = (1 << 30) - 1;

int nums[MAXN], ans[MAXN];
int tb[MAXN];
int n, m;

struct Node
{
    int type; // 0修改，1查询
    int val, pos;
    int l, r;
};

Node opAll[MAXN * 2];
vector<Node> opLeft, opRight;

int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int d)
{
    while (x <= n)
    {
        tb[x] += d;
        x += lowbit(x);
    }
}
int getSum(int pos)
{
    int res = 0;
    while (pos > 0)
    {
        res += tb[pos];
        pos -= lowbit(pos);
    }
    return res;
}

void pbin(int l, int r, int vl, int vr)
{
    if (l > r)
        return;
    if (vl == vr)
    {
        for (int i = l; i <= r; i++)
        {
            if (opAll[i].type == 1)
                ans[opAll[i].pos] = vl;
        }
        return;
    }

    int vmid = (vl + vr) >> 1;
    vector<Node>().swap(opLeft);
    vector<Node>().swap(opRight);
    for (int i = l; i <= r; i++)
    {
        Node &nd = opAll[i];
        if (nd.type == 0)
        {
            if (nd.val <= vmid)
            {
                add(nd.pos, 1);
                opLeft.push_back(nd);
            }
            else
            {
                opRight.push_back(nd);
            }
        }
        else if (nd.type == 1)
        {
            int flags = getSum(nd.r) - getSum(nd.l - 1);
            if (nd.val > flags)
            {
                Node nn = nd;
                nn.val -= flags;
                opRight.push_back(nn);
            }
            else
            {
                opLeft.push_back(nd);
            }
        }
    }

    for (int i = 0; i < opLeft.size(); i++)
    {
        Node &nd = opLeft[i];
        if (nd.type == 0)
        {
            add(nd.pos, -1);
        }
    }

    for (int i = 0; i < opLeft.size(); i++)
    {
        opAll[l + i] = opLeft[i];
    }
    int ls = opLeft.size();
    for (int i = 0; i < opRight.size(); i++)
    {
        opAll[l + ls + i] = opRight[i];
    }
    pbin(l, l + ls - 1, vl, vmid);
    pbin(l + ls, r, vmid + 1, vr);
}

int main()
{
    scanf("%d%d", &n, &m);
    int minVal = INF, maxVal = -INF;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", nums + i);
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
        Node &nd = opAll[i];
        nd.type = 0;
        nd.val = nums[i], nd.pos = i;
    }
    for (int i = n + 1; i <= n + m; i++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        Node &nd = opAll[i];
        nd.type = 1;
        nd.l = l, nd.r = r;
        nd.val = k, nd.pos = i - n;
    }
    pbin(1, m + n, minVal, maxVal);
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
