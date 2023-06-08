#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000006;
const int INF = (1<<30)-1;

struct Edge
{
    Edge(int _p1,int _p2,int _c)
    {
        p1=_p1,p2=_p2;
        cost=_c;
    }
    int p1,p2;
    int cost;
};
vector<Edge> edges;

int n,p;
int arr[MAXN];

//segtree
int stMin[MAXN<<2];
void stBuild(int l,int r,int idx)
{
    if(l==r)
    {
        stMin[idx]=arr[l];
        return;
    }

    int mid=(l+r)>>1;
    stBuild(l,mid,idx<<1);
    stBuild(mid+1,r,(idx<<1)|1);
    stMin[idx]=min(stMin[idx<<1],stMin[(idx<<1)|1]);
}
int stGetMin(int l,int r,int nl,int nr,int idx)
{
    if(l<=nl&&r>=nr)
    {
        return stMin[idx];
    }
    int nmid=(nl+nr)>>1;
    int res=INF;
    if(l<=nmid) res=min(res,stGetMin(l,r,l,nmid,idx<<1));
    if(r>nmid) res=min(res,stGetMin(l,r,nmid+1,r,(idx<<1)|1));
    return res;
}

//union find set
int ufsFa[MAXN];
void ufsInit()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
void ufsAdd(int a,int b)
{
    ufsFa[a]=ufsGetFa(b);
}
int ufsGetFa(int a)
{
    if(ufsFa[a]==a) return a;
    else return ufsFa[a]=ufsGetFa(ufsFa[a]);
}

bool checkGcd(int l,int r)
{
}

int main()
{
    freopen("mst.in","r",stdin);
    freopen("mst.out","w",stdout);

    int mxa=1;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
        mxa=max(mxa,arr[i]);
        if(i>1) edges.push_back(Edge(i-1,i,p));
    }
    stBuild(1,n,1);
    if(p==1 || mxa==1)
    {
        printf("%d\n",n-1);
        return 0;
    }
    for(int l=1;i<=n;l++)
    {
        for(int r=l+1;r<=n;r++)
        {
            if(checkGcd(l,r)) edges.push_back(Edge(l,r,stGetMin(l,r,1,n,1)));
        }
    }
    return 0;
}
