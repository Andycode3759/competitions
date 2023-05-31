// AC
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
using namespace std;
const int MAXN = 100005;

struct SegTreeNode
{
    int l, r;
    int col;
    int mark;
};
int geth(int x)
{
    int res = 0;
    while (x > 0)
    {
        x -= (x & (-x));
        res++;
    }
    return res;
}

int len, t, o;
SegTreeNode st[MAXN << 2];

void passDown(int idx)
{
	SegTreeNode &node = st[idx];
	SegTreeNode &lc=st[idx*2],&rc=st[idx*2+1];
	lc.mark=node.mark,rc.mark=node.mark;
	lc.col=node.mark,rc.col=node.mark;
	node.mark=0;
}
void gatherUp(int idx)
{
	SegTreeNode &node = st[idx];
	node.col=st[idx*2].col|st[idx*2+1].col;
}
void build(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    node.l=l,node.r=r;
    node.col=1;
    node.mark=0;
    if(l==r)
    {
    	return;
	}
	int mid = (l+r)>>1;
	build(idx*2,l,mid);
	build(idx*2+1,mid+1,r);
	gatherUp(idx);
}
void update(int idx, int l, int r, int c)
{
    SegTreeNode &node = st[idx];
    if(l<=node.l && r>=node.r)
    {
    	node.col=c;
    	node.mark=c;
    	return;
	}
	if(node.mark!=0) passDown(idx);
	int nmid=(node.l+node.r)>>1;
	if(l<=nmid) update(idx*2,l,r,c);
	if(r>nmid) update(idx*2+1,l,r,c);
	gatherUp(idx);
	return;
}
int query(int idx, int l, int r)
{
    SegTreeNode &node = st[idx];
    if(l<=node.l && r>=node.r)
    {
    	return node.col;
	}
	if(node.mark!=0) passDown(idx);
	int res=0;
	int nmid=(node.l+node.r)>>1;
	if(l<=nmid) res=res|query(idx*2,l,r);
	if(r>nmid) res=res|query(idx*2+1,l,r);
	return res;
}

int main()
{
    scanf("%d%d%d", &len, &t, &o);
    build(1, 1, len);
    while (o--)
    {
        char op = ' ';
        while (op != 'C' && op != 'P')
            scanf("%c", &op);
        int a, b, c;
        switch (op)
        {
        case 'C':
            scanf("%d%d%d", &a, &b, &c);
            if (a > b)
                swap(a, b);
            update(1, a, b, 1<<(c-1));
            break;
        case 'P':
            scanf("%d%d", &a, &b);
            if (a > b)
                swap(a, b);
            int ans = geth(query(1, a, b));

            printf("%d\n", ans);
            break;
        }
    }
    return 0;
}
