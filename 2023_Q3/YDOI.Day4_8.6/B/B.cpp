#include <cstring>
#include <cstdio>
using namespace std;
const int MOD = 998244853;
const int MAXN = 100005;
const int STICKS[10] = {6,2,5,5,4,5,6,3,7,5};

int n,len;
int cur[MAXN],ans[MAXN];
int mem[MAXN];
long long pow10[MAXN];

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

void tryUpdateAns()
{
    for(int i=len;i>=1;i--)
    {
        if(cur[i]>ans[i]) return;
        if(cur[i]<ans[i]) break;
    }
    for(int i=1;i<=len;i++) ans[i]=cur[i];
}
void dfs(int step,int left)
{
    if(step*7<left) return;
    if(step*7==left)
    {
        for(int i=step;i>=1;i--)
        {
            cur[i]=8;
        }
        tryUpdateAns();
        return;
    }
    if(step==0)
    {
        if(left==0) tryUpdateAns();
        return;
    }
    for(int i=0;i<=9;i++)
    {
        if(step==len&&i==0) continue;
        if(STICKS[i]<=left && i<=ans[step])
        {
            cur[step]=i;
            dfs(step-1,left-STICKS[i]);
        }
    }
}

int main()
{
    memset(mem,-1,sizeof mem);
    mem[6]=0;
    pow10[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        pow10[i]=pow10[i-1]*10%MOD;
    }
    int T;
    // scanf("%d",&T);
    T=read();
    while(T--)
    {
        // scanf("%d",&n);
        n=read();
        if(mem[n]>=0) printf("%d\n",mem[n]);
        else
        {
            len=(n+6)/7;
            for(int i=1;i<=len;i++) ans[i]=114;
            dfs(len,n);
            long long res=0;
            for(int i=1;i<=len;i++)
            {
                res=(res+1LL*ans[i]*pow10[i-1]%MOD)%MOD;
            }
            printf("%d\n",mem[n]=res);
        }
    }
    return 0;
}
