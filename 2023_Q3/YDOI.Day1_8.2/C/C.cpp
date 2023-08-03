#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXK = 12;
const int MAXN = 1000006;

struct Point
{
    int idx;
    ll pos[MAXK];
    ll d1,d2;
};

struct PointCmp
{
    PointCmp(int _m):mode(_m){}
    int mode;
    bool operator()(Point &a,Point &b)
    {
        if(mode==1) return a.d1<b.d1;
        else return a.d2<b.d2;
    }
};

int n,k;
ll v,v1,v2;
Point p1,p2;
Point key[MAXN],key2[MAXN];
bool mark[MAXN];
int rank2[MAXN];

ll distance(Point &a,Point &b)
{
    ll res=0;
    for(int i=1;i<=k;i++)
    {
        ll d=a.pos[i]-b.pos[i];
        res+=d*d;
    }
    return res;
}

int main()
{
    scanf("%d %d %lld %lld %lld",&n,&k,&v,&v1,&v2);
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&p1.pos[i]);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&p2.pos[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            scanf("%lld",&key[i].pos[j]);
        }
        key[i].idx=i;
        key[i].d1=distance(key[i],p1)*v1;
        key[i].d2=distance(key[i],p2)*v2;
        key2[i]=key[i];
    }

    sort(key+1,key+1+n,PointCmp(1));
    sort(key2+1,key2+1+n,PointCmp(2));
    for (int i=1; i<=n; i++) rank2[key2[i].idx] = i;
    int ans=0;
    int cur=1,cnt2=0;
    for (int cnt1=n;cnt1>=0;cnt1--) 
    {
        ll maxR2 = v-key[cnt1].d1;
        while (cur<=n && key2[cur].d2<=maxR2)
        {
            if (mark[key2[cur].idx]) ++cnt2;
            ++cur;
        }
        if (maxR2>=0) ans = max(ans, cnt1+cnt2);
        if (rank2[key[cnt1].idx] < cur) ++cnt2;
        mark[key[cnt1].idx] = true;
    }
    printf("%d\n",ans);

    return 0;
}