#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 2023;

vector<int> G[MAXN];
int n,m,q;

vector<int> path;
bool vis[MAXN];

int inLoop[MAXN];
int stmp=0;
int ord[MAXN];
int atStmp[MAXN];

void dfsLoop(int cur)
{
    ord[cur]=++stmp;
    atStmp[stmp]=cur;
    for(int i=0,len=G[cur].size();i<len;i++)
    {
        int v=G[cur][i];
        if(inLoop[v]||ord[v]>stmp) continue;
        if(ord[v]>0&&ord[v]<stmp)
        {
            int mx=-1;
            for(int j=ord[v];j<=stmp;j++)
            {
                mx=max(mx,atStmp[j]);
            }
            for(int j=ord[v];j<=stmp;j++)
            {
                inLoop[atStmp[j]]=mx;
            }
            continue;
        }
        dfsLoop(v);
    }
}

bool dfs(int cur,int t)
{
    if(cur==t)
    {
        return true;
    }
    for(int i=0,len=G[cur].size();i<len;i++)
    {
        int v=G[cur][i];
        if(vis[v]) continue;
        path.push_back(v);
        vis[v]=true;
        if(dfs(v,t)) return true;
        path.pop_back();
        vis[v]=false;
    }
    return false;
}

int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
    }
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    dfsLoop(1);
    while(q--)
    {
        int s,t,k;
        scanf("%d %d %d",&s,&t,&k);
        for(int i=1;i<=n;i++) vis[i]=false;
        path.clear();
        path.push_back(s);
        vis[s]=true;
        bool flag=false;
        for(int i=0,len=path.size();i<len;i++)
        {
            if(inLoop[path[i]]>0&&inLoop[path[i]]<t)
            {
                printf("-1\n");
                flag=true;
                break;
            }
        }
        if(flag) continue;
        if(!dfs(s,t) || path.size()<k)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",path[k-1]);
    }
    return 0;
}
