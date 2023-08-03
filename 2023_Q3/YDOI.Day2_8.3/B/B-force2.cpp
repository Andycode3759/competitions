#include <vector>
#include <cstdio>
using namespace std;
const int MAXN = 200005;

int arr[MAXN];
int n;
int ans=0;
bool mark[MAXN];
int len;

bool check()
{
    int t=(2*len+1)/3;
    for(int i=1,cnt=0,lst=-1;i<=n;i++)
    {
        if(!mark[i]) continue;
        cnt++;
        if(cnt<=t)
        {
            if(lst!=-1 && arr[i]!=lst+1) return false;
            lst=arr[i];
        }
        else
        {
            if(lst!=-1 && arr[i]!=lst-1) return false;
            lst=arr[i];
        }
    }
    return true;
}

void dfs(int step)
{
    if(step>n)
    {
        if(check()) ans=max(ans,len);
        return;
    }
    mark[step]=true;
    len++;
    dfs(step+1);
    mark[step]=false;
    len--;
    dfs(step+1);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
