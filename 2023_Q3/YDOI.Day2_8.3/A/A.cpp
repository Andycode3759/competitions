#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 20;

struct Point
{
    int day,time;
};
struct Class
{
    int m,k;
    Point tch1[5],tch2[5];
};

int n;
Class cls[MAXN];

int ans=0;
bool mark[10][10];
void dfs(int step,int res)
{
    if(step>n)
    {
        ans=max(ans,res);
        return;
    }

    //dont choose
    dfs(step+1,res);

    bool flag=false;
    Class &cur = cls[step];

    //choose teacher 1
    for(int i=1;i<=cur.k;i++)
    {
        if(mark[cur.tch1[i].day][cur.tch1[i].time])
        {
            flag=true;
            break;
        }
    }
    if(!flag)
    {
        for(int i=1;i<=cur.k;i++)
        {
            mark[cur.tch1[i].day][cur.tch1[i].time]=true;
        }
        dfs(step+1,res+cur.k);
        for(int i=1;i<=cur.k;i++)
        {
            mark[cur.tch1[i].day][cur.tch1[i].time]=false;
        }
    }
    flag=false;

    //choose teacher 2
    if(cur.m==1) return;

    for(int i=1;i<=cur.k;i++)
    {
        if(mark[cur.tch2[i].day][cur.tch2[i].time])
        {
            flag=true;
            break;
        }
    }
    if(!flag)
    {
        for(int i=1;i<=cur.k;i++)
        {
            mark[cur.tch2[i].day][cur.tch2[i].time]=true;
        }
        dfs(step+1,res+cur.k);
        for(int i=1;i<=cur.k;i++)
        {
            mark[cur.tch2[i].day][cur.tch2[i].time]=false;
        }
    }
}

int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        int m,k;
        scanf("%d %d",&m,&k);
        printf("%d\n",k);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&cls[i].m,&cls[i].k);
        for(int j=1;j<=cls[i].k;j++)
        {
            scanf("%d %d",&cls[i].tch1[j].day,&cls[i].tch1[j].time);
        }
        if(cls[i].m>=2)
        {
            for(int j=1;j<=cls[i].k;j++)
            {
                scanf("%d %d",&cls[i].tch2[j].day,&cls[i].tch2[j].time);
            }
        }
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
