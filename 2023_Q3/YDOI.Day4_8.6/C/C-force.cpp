#include <cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const int MOD = 998244353;

int n;
int arr[MAXN];
ll ans[MAXN];
int lastSub[MAXN];
int cnt[MAXN];

bool isSub(int x,int y) //x is a subset of y
{
    while(x>0)
    {
        int lb=(x&(-x));
        if((y&lb)==0) return false;
        x-=lb;
    }
    return true;
}

ll dfs(int cur)
{
    ll res=1;
    for(int i=cur-1;i>=1;i--)
    {
        if(isSub(arr[i],arr[cur])) res=(res+dfs(i))%MOD;
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld\n",dfs(i));
    }
    return 0;
}
