// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const long long SCORE = 600;
#define lson(cur) cur * 2
#define rson(cur) cur * 2 + 1
#define parent(cur) cur / 2
#define mid(l, r) (l + r) / 2
int n;
long long talent;
long long hard[MAXN];

struct LTNode
{
    int l, r, conf;
} lt[19 * MAXN];

int ltLen = 0;

int cacheAddr[MAXN]; // cacheAddr[i] => hard[i]单点对应线段树中的节点编号

int buildLT(int cur, int l, int r)
{
    ltLen++;
    lt[cur].l = l, lt[cur].r = r;
    if (l == r)
    {
        cacheAddr[l] = cur;
        return lt[cur].conf = (hard[l] > 0 && talent >= hard[l]) ? 1 : 0;
    }
    return lt[cur].conf = buildLT(lson(cur), l, mid(l, r)) + buildLT(rson(cur), mid(l, r) + 1, r);
}
void modifyLT(int cur, long long val)
{
    if (lt[cur].l == lt[cur].r) // 修改叶节点
    {
        lt[cur].conf = (talent >= hard[lt[cur].l] && hard[lt[cur].l] > 0) ? 1 : 0;
    }
    else // 修改非叶节点
    {
        lt[cur].conf = lt[lson(cur)].conf + lt[rson(cur)].conf;
        // 左右儿子相加
    }

    // printf("modify: cur=%d [%d,%d] => %d\n", cur, lt[cur].l, lt[cur].r, lt[cur].conf);

    if (cur <= 1) // 递归到根节点
        return;
    modifyLT(parent(cur), val); // 上传信息
}
void modify(int i, long long val)
{
    // val<=0 => Overflow
    hard[i] = val <= 0 ? -1 : val;
    modifyLT(cacheAddr[i], val);
    // printf("modify success: hard[%d]=>%d\n", i, val);
}
int query(int cur, int l, int r)
{
    // printf("query [%d,%d] in lt[%d]\n", l, r, cur);

    if (l <= 0 || r > n || r < l) // 越界
    {
        // printf("query success: [%d,%d]: 0 (OOB)\n", l, r);
        return 0;
    }
    if (l == r) // 单点查询
    {
        // printf("query success: %d: %d\n", l, talent >= hard[l] ? 1 : 0);
        return (hard[l] > 0 && talent >= hard[l]) ? 1 : 0;
    }
    if (l == lt[cur].l && r == lt[cur].r) // 查询的区间刚好就是目前线段
    {
        return lt[cur].conf;
        // 目前线段树节点值
    }
    if (r <= mid(lt[cur].l, lt[cur].r)) // 区间全在目前线段的左边
    {
        int t = query(lson(cur), l, r);
        // printf("query success: [%d,%d]: %d\n", l, r, t);
        return t; // 直接查左儿子
    }
    if (l > mid(lt[cur].l, lt[cur].r)) // 区间全在目前线段的右边
    {
        int t = query(rson(cur), l, r);
        // printf("query success: [%d,%d]: %d\n", l, r, t);
        return t; // 直接查右儿子
    }
    // 最后情况：查询区间分别在目前线段中点左右两侧
    int t = query(lson(cur), l, mid(lt[cur].l, lt[cur].r)) + query(rson(cur), mid(lt[cur].l, lt[cur].r) + 1, r);
    // printf("query success: [%d,%d]: %d\n", l, r, t);
    return t;
    // 左儿子查左边+右儿子查右边
}

int main()
{
    memset(cacheAddr, -1, sizeof(cacheAddr));
    scanf("%d%lld", &n, &talent);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &hard[i]);
    }
    buildLT(1, 1, n);

    // for (int i = 1; i <= ltLen; i++)
    // {
    //     printf("lt[%d]: [%d,%d] conf=%d\n", i, lt[i].l, lt[i].r, lt[i].conf);
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     printf("cache[%d] :%d\n", i, cacheAddr[i]);
    // }

    int q;
    scanf("%d", &q);
    while (q--)
    {
        char op[10];
        int arg1, arg2;
        scanf("%s%d%d", op, &arg1, &arg2);
        switch (op[0])
        {
        case 'B': // (BookCity) difficulty decrease
            if (hard[arg1] <= 0)
                break; // Overflowed
            if (hard[arg1] - arg2 <= 0)
                modify(arg1, 1);
            else
                modify(arg1, hard[arg1] - arg2);
            break;
        case 'G': // (Guy) difficulty multiply
            if (hard[arg1] <= 0)
                break; // Overflowed
            modify(arg1, hard[arg1] * arg2);
            break;
        case 't': // (tingtime) difficulty set
            modify(arg1, arg2);
            break;
        case 'Z': // (Zero) query
            if (arg1 > arg2)
                swap(arg1, arg2);
            printf("%lld\n", query(1, arg1, arg2) * SCORE);
            break;
        }
    }
    return 0;
}