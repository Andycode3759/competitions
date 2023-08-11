#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 500005;

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

int n,q;
int col[MAXN];
int fa[MAXN];
vector<int> child[MAXN];
map<int,int> colCnt[MAXN];

int main()
{
    // scanf("%d %d",&n,&q);
    n=read(),q=read();
    for(int i=1;i<=n;i++) 
        //scanf("%d",col+i);
        col[i]=read();
    
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        int t;
        //scanf("%d",&t);
        t=read();
        child[t].push_back(i);
        fa[i]=t;
        if(col[i]!=col[t]) ans++;
        colCnt[t][col[i]]++;
    }

    for(int i=1;i<=q;i++)
    {
        int x,t;
        //scanf("%d %d",&x,&t);
        x=read(),t=read();
        if(t==col[x])
        {
            printf("%d\n",ans);
            continue;
        }
        
        // for(int i=0,len=child[x].size();i<len;i++)
        // {
        //     int v=child[x][i];
        //     if(col[x]==col[v]) ans++;
        //     if(t==col[v]) ans--;
        // }
        ans+=colCnt[x][col[x]];
        ans-=colCnt[x][t];
        if(col[x]==col[fa[x]]) ans++;
        else if(t==col[fa[x]]) ans--;

        colCnt[fa[x]][col[x]]--;
        colCnt[fa[x]][t]++;
        col[x]=t;
        printf("%d\n",ans);
    }
    return 0;
}
