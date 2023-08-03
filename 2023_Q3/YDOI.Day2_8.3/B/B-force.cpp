#include <vector>
#include <cstdio>
using namespace std;
const int MAXN = 200005;

int arr[MAXN];
int n;

bool check(vector<int> &v)
{
    int len=v.size();
    int t=(2*len+1)/3;
    for(int i=0;i<t-1;i++)
    {
        if(v[i]!=v[i+1]-1) return false;
    }
    for(int i=t;i<len;i++)
    {
        if(v[i]!=v[i-1]-1) return false;
    }
    return true;
}

int ans=0;
bool mark[MAXN];
void dfs(int step)
{
    if(step>n)
    {
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            if(mark[i]) v.push_back(arr[i]);
        }
        if(check(v)) ans=max(ans,(int)v.size());
        return;
    }
    mark[step]=true;
    dfs(step+1);
    mark[step]=false;
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
