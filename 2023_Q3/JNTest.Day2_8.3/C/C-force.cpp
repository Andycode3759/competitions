#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 500005;

int n,q;
int col[MAXN];
vector<int> child[MAXN];

bool mark[MAXN];
void dfs(int cur)
{
    mark[cur]=true;
    for(int i=0,len=child[cur].size();i<len;i++)
    {
        int v=child[cur][i];
        if(col[v]==col[cur]) dfs(v);
    }
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",col+i);
    for(int i=2;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        child[t].push_back(i);
    }
    for(int i=1;i<=q;i++)
    {
        int x,t;
        scanf("%d %d",&x,&t);
        col[x]=t;
        for(int i=1;i<=n;i++) mark[i]=false;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!mark[i]) dfs(i),ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
