#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 300006;

long long read()
{
    char c = getchar();
    long long res = 0;
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

struct SegTreeNode
{
    int l, r;
    long long area = 0;
    long long mark = 0;
};
struct Rect
{
    long long s, t, h;
    const bool operator<(const Rect &a) const
    {
        return h < a.h;
    }
};
SegTreeNode st[MAXN << 3];
Rect rects[MAXN];

vector<long long> pos;
map<long long, int> posRank;

void passDown(int idx)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx * 2], &rc = st[idx * 2 + 1];
    if (node.mark > lc.mark)
    {
        lc.mark = node.mark;
        lc.area = (pos[lc.r] - pos[lc.l - 1]) * node.mark;
    }
    if (node.mark > rc.mark)
    {
        rc.mark = node.mark;
        rc.area = (pos[rc.r] - pos[rc.l - 1]) * node.mark;
    }
    node.mark = 0;
    node.area = lc.area + rc.area;
}
void gatherUp(int idx)
{
    SegTreeNode &node = st[idx];
    SegTreeNode &lc = st[idx * 2], &rc = st[idx * 2 + 1];
    node.area = lc.area + rc.area;
}
void build(int l, int r, int idx)
{
    SegTreeNode &node = st[idx];
    node.l = l, node.r = r;
    node.area = 0;
    node.mark = 0;
    if (l == r)
        return;

    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    gatherUp(idx);
}
void update(int l, int r, long long height, int idx)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        node.mark = height;
        node.area = (pos[node.r] - pos[node.l - 1]) * height;
        return;
    }
    if (node.mark > 0)
        passDown(idx);

    int nmid = (node.l + node.r) >> 1;
    if (l <= nmid)
        update(l, r, height, idx * 2);
    if (r > nmid)
        update(l, r, height, idx * 2 + 1);
    gatherUp(idx);

    // printf("update: [%d,%d] area=%lld mark=%lld\n", node.l, node.r, node.area, node.mark);
}
long long query(int l, int r, int idx)
{
    SegTreeNode &node = st[idx];
    if (l <= node.l && r >= node.r)
    {
        return node.area;
    }
    if (node.mark > 0)
        passDown(idx);

    int nmid = (node.l + node.r) >> 1;
    long long res = 0;
    if (l <= nmid)
        res += query(l, r, idx * 2);
    if (r > nmid)
        res += query(l, r, idx * 2 + 1);
    return res;
}

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // scanf("%lld%lld%lld", &rects[i].s, &rects[i].t, &rects[i].h);
        rects[i].s = read(), rects[i].t = read(), rects[i].h = read();
        pos.push_back(rects[i].s);
        pos.push_back(rects[i].t);
    }
    sort(pos.begin(), pos.end());
    unique(pos.begin(), pos.end());
    for (int i = 0; i < pos.size(); i++)
    {
        // printf("posRank[%d]=%d\n", pos[i], i + 1);

        posRank[pos[i]] = i + 1;
    }
    sort(rects, rects + n);
    build(1, pos.size() - 1, 1);

    for (int i = 0; i < n; i++)
    {
        Rect &r = rects[i];
        update(posRank[r.s], posRank[r.t] - 1, r.h, 1);
    }

    printf("%lld\n", query(1, pos.size() - 1, 1));
    return 0;
}
