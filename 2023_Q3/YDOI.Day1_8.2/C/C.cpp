#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int MAXK = 12;
const int MAXN = 1000006;

struct Point
{
    int pos[MAXK];
    ull d1,d2;
};

int n,k;
ull v,v1,v2;
Point p1,p2;
Point key[MAXN];


ull distance(Point &a,Point &b)
{
    ull res=0;
    for(int i=1;i<=k;i++)
    {
        int d=a.pos[i]-b.pos[i];
        res+=d*d;
    }
    return res;
}

int ans=0;
void dfs(int step,ull c1,ull c2,int res)
{
    if(c1+c2<=v) ans=max(ans,res);
    else return;
    if(step>n) return;

    Point &cur = key[step];

    dfs(step+1,c1,c2,res);
    // if(min(cur.d1,cur.d2)>v-c1-c2) return;

    if(cur.d1<cur.d2)
    {
        dfs(step+1,max(c1,cur.d1),c2,res+1);
    }
    else if(cur.d1>cur.d2)
    {   
        dfs(step+1,c1,max(c2,cur.d2),res+1);
    }
    else // cur.d1==cur.d2
    {
        dfs(step+1,max(c1,cur.d1),c2,res+1);
        dfs(step+1,c1,max(c2,cur.d2),res+1);
    }
}

int main()
{
    scanf("%d%d%llu%llu%llu",&n,&k,&v,&v1,&v2);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&p1.pos[i]);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&p2.pos[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&key[i].pos[j]);
        }
        key[i].d1=distance(key[i],p1)*v1;
        key[i].d2=distance(key[i],p2)*v2;
        // printf("d1[%d]=%llu d2[%d]=%llu\n",i,key[i].d1,i,key[i].d2);
    }

    dfs(1,0,0,0);
    printf("%d\n",ans);

    return 0;
}
