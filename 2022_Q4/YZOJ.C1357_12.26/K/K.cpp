//ACCEPETED

/*
假设可以满足k份订单，二分k
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
long long schedule[MAXN];

struct Order
{
    int count,start,to;
};
Order orders[MAXN];

bool check(int k)
{
    if(k<1) return false;
    long long expect[MAXN],expectSum[MAXN];
    memset(expect,0,MAXN*sizeof(long long));
    memset(expectSum,0,MAXN*sizeof(long long));
    for(int i=1;i<=k;i++)
    {
        expect[orders[i].start]+=orders[i].count;
        expect[orders[i].to+1]-=orders[i].count;
    }
    for(int i=1;i<MAXN;i++)
    {
        expectSum[i]=expect[i]+expectSum[i-1];
        if(expectSum[i]>schedule[i]) return false;
    }
    return true;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&schedule[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&orders[i].count,&orders[i].start,&orders[i].to);
    }

    int l=1,r=n,mid=(l+r)/2;
    int ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(!check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(ans<1||ans>n||check(ans))
        printf("0\n");
    else
        printf("-1\n%d\n",ans);

    return 0;
}
