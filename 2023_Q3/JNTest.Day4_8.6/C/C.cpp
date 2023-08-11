#include <cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const int MOD = 998244353;

inline int read()
{
    int res=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

int n;
int arr[MAXN];
ll mem[MAXN];

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
    if(mem[cur]>0) return mem[cur];
    ll res=1;
    for(int i=cur-1;i>=1;i--)
    {
        if(isSub(arr[i],arr[cur])) res=(res+dfs(i))%MOD;
    }
    return mem[cur]=res;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        arr[i]=read();
        printf("%lld\n",dfs(i));
    }
    return 0;
}
