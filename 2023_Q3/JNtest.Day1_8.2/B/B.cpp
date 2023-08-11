#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2505;
const int MOD = 1000000007;
typedef unsigned long long ull;

struct Node
{
    Node(int _l=0,int _v=0):len(_l),val(_v){}
    int len, val;
};
Node arr[MAXN*MAXN];

struct NodeCmp
{
    bool operator()(Node &a,Node &b)
    {
        return a.val==b.val?a.len<b.len:a.val<b.val;
    }
};

int quickPow(ull a,ull x)
{
    ull res=1;
    while(x>0)
    {
        if((x&1)==1) res=(res*a)%MOD;
        a=a*a%MOD;
        x=(x>>1);
    }
    return res;
}
int findMod(ull a,ull b)
{
    return (a%MOD)*(quickPow(b,MOD-2)%MOD)%MOD;
}

int v[MAXN][MAXN],cnt[MAXN][MAXN];
int n;
int flag[MAXN],tot=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&v[i][j]);
            arr[++tot]=Node(i,v[i][j]);
        }
        
    }
    sort(arr+1,arr+1+tot,NodeCmp());
    
    ull ans=0;
    for(int i=1;i<=tot;i++)
    {
        Node &now=arr[i];
        flag[now.len]++;
        ull num=1;
        for(int j=1;j<=n;j++)
        {
            if(j==now.len) continue;
            num*=flag[j];
        }
        ans+=num*now.val;
    }
    printf("%d\n",findMod(ans,quickPow(n,n)));

    return 0;
}
