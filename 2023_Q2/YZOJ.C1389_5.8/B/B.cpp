// AC
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 30005;
const int INF = (1 << 30) - 1;

struct Fenwick
{
    Fenwick(int _s) : size(_s)
    {
    }
    int data[MAXN], size;

    void add(int pos, int dlt)
    {
        while (pos <= size)
        {
            data[pos] += dlt;
            pos += (pos & (-pos));
        }
    }

    int getSum(int pos)
    {
        int res = 0;
        while (pos > 0)
        {
            res += data[pos];
            pos -= (pos & (-pos));
        }
        return res;
    }
};

struct Node
{
    Node(int _t, int _l, int _r, int _v, int _p)
    {
        type = _t;
        l = _l;
        r = _r;
        val = _v;
        pos = _p;
    }

    int type; // 0修改，1查询，2删除
    int val, pos;
    int l, r;
};

int nums[MAXN];
int ans[MAXN];
int n, m;
Fenwick fw(0);
vector<Node> opAll, opLeft, opRight;

void pbin(int l, int r, int vl, int vr)
{
    if (l > r)
        return;
    if (vl == vr)
    {
        for (int i = l; i <= r; i++)
        {
            Node &nd = opAll[i];
            if (nd.type == 1)
                ans[nd.pos] = vl;
        }
        return;
    }

    int vmid = (vl + vr) >> 1;
    vector<Node>().swap(opLeft);
    vector<Node>().swap(opRight);
    for (int i = l; i <= r; i++)
    {
        Node &nd = opAll[i];
        int flags;
        switch (nd.type)
        {
        case 0: // add number
            if (nd.val <= vmid)
            {
                fw.add(nd.pos, 1);
                opLeft.push_back(nd);
            }
            else
            {
                opRight.push_back(nd);
            }
            break;
        case 1: // query
            flags = fw.getSum(nd.r) - fw.getSum(nd.l - 1);
            if (nd.val > flags)
            {
                opRight.push_back(Node(1, nd.l, nd.r, nd.val - flags, nd.pos));
            }
            else
            {
                opLeft.push_back(nd);
            }
            break;
        case 2: // delete number
            if (nd.val <= vmid)
            {
                fw.add(nd.pos, -1);
                opLeft.push_back(nd);
            }
            else
            {
                opRight.push_back(nd);
            }
            break;
        }
    }

    for (int i = 0; i < opLeft.size(); i++)
    {
        Node &nd = opLeft[i];
        if (nd.type == 0)
        {
            fw.add(nd.pos, -1);
        }
        else if (nd.type == 2)
        {
            fw.add(nd.pos, 1);
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
    fw = Fenwick(n);
    int minVal = INF, maxVal = -INF;
    int qs = 0;
    opAll.push_back(Node(0, 0, 0, 0, 0)); // 凑数
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", nums + i);
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
        opAll.push_back(Node(0, 0, 0, nums[i], i));
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            opAll.push_back(Node(1, l, r, k, ++qs));
        }
        else if (op == 2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            minVal = min(minVal, y);
            maxVal = max(maxVal, y);
            opAll.push_back(Node(2, 0, 0, nums[x], x));
            opAll.push_back(Node(0, 0, 0, y, x));
            nums[x] = y;
        }
    }
    pbin(1, opAll.size() - 1, minVal, maxVal);
    for (int i = 1; i <= qs; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
