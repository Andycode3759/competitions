#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 10004;

struct Node
{
    int x=0,y=0,tm=0;
};

vector<int> hshot[MAXN],vshot[MAXN];
queue<Node> Q;
int n,m,r;

bool isSafe(Node nd)
{
    for(int i=0;i<hshot[nd.x].size();i++)
    {
        if(hshot[nd.x][i]==nd.tm) return false;
    }
    for(int i=0;i<vshot[nd.y].size();i++)
    {
        if(vshot[nd.y][i]==nd.tm) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            vector<int>().swap(hshot[i]);
        }
        for(int i=1;i<=m;i++)
        {
            vector<int>().swap(vshot[i]);
        }
        queue<Node>().swap(Q);
        scanf("%d",&r);
        int t,d,co;
        for(int i=1;i<=r;i++)
        {
            scanf("%d%d%d",&t,&d,&co);
            if(d==1)
            {
                hshot[co].push_back(t);
            }
            else if(d==2)
            {
                vshot[co].push_back(t);
            }
        }
        Node init;
        Q.push(init);
        bool suc=false;
        while(!Q.empty())
        {
            Node nd = Q.front();
            Q.pop();
            if(nd.x==n&&nd.y==m)
            {
                printf("%d\n",nd.tm);
                suc=true;
                break;
            }
            Node g1=nd,g2=nd,g3=nd;
            g1.x++,g1.tm++;
            g2.y++,g2.tm++;
            g3.tm++;
            if(isSafe(g1)) Q.push(g1);
            if(isSafe(g2)) Q.push(g2);
            if(isSafe(g3)) Q.push(g3);
        }
        if(!suc) printf("-1\n");
    }

    return 0;
}
