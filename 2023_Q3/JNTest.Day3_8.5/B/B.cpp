#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 20004;

inline int read()
{
    char c=getchar();
    int res=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

int n,m;
int prc[MAXN],val[MAXN];

bool G[MAXN][MAXN];
bool vis[MAXN];

int dfs(int cur)
{
    int res=val[cur];
    int nxt=0;
    for(int i=1;i<=n;i++)
    {
        if(G[cur][i] && !vis[i])
        {
            vis[i]=true;
            nxt=max(nxt,dfs(i));
            vis[i]=false;
        }
    }
    return res+nxt;
}

int main()
{
    // scanf("%d %d",&n,&m);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        //scanf("%d %d",&prc[i],&val[i]);
        prc[i]=read(),val[i]=read();
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        // scanf("%d %d",&u,&v);
        u=read(),v=read();
        G[u][v]=true;
    }

    double ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) vis[j]=false;
        vis[i]=true;
        ans=max(ans,1.0*dfs(i)/prc[i]);
    }
    printf("%.2lf\n",ans);
    return 0;
}