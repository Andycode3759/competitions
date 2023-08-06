#include <cstdio>
using namespace std;
const int MOD=998244853;
const int MAXN = 100005;
const int STICKS[10]={6,2,5,5,4,5,6,3,7,5};

int n;
int cur[MAXN],ans[MAXN];
int curLen,ansLen;
long long pow10[MAXN];

void assign()
{
    for(int i=1;i<=curLen;i++)
    {
        ans[i]=cur[i];
    }
    ansLen=curLen;
}
void tryUpdateAns()
{
    if(curLen<ansLen)
    {
        assign();
        return;
    }
    else if(curLen==ansLen)
    {
        for(int i=curLen;i>=1;i--)
        {
            if(cur[i]>ans[i]) return;
            if(cur[i]<ans[i])
            {
                assign();
                return;
            }
        }
    }
}
void dfs(int step,int left)
{
    if(left==0)
    {
        if(cur[curLen]!=0) tryUpdateAns();
        return;
    }
    for(int i=0;i<=9;i++)
    {
        if(STICKS[i]<=left)
        {
            cur[step]=i;
            curLen=step;
            dfs(step+1,left-STICKS[i]);
            curLen=step;
        }
    }
}

int main()
{
    pow10[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        pow10[i]=pow10[i-1]*10%MOD;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        curLen=0;
        ansLen=1145141919;
        scanf("%d",&n);
        if(n==6) printf("0\n");
        else
        {
            dfs(1,n);
            long long res=0;
            for(int i=1;i<=ansLen;i++)
            {
                res=(res+1LL*ans[i]*pow10[i-1]%MOD)%MOD;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}
