#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2008;

char canvas[MAXN][MAXN];
int n,m;
bool mark[30];  //字母标记

bool check(char l,int ax,int ay,int bx,int by)
{
    for(int i=ax;i<=bx;i++)
    {
        if(canvas[i][ay]!=l || canvas[i][by]!=l) return false;
    }
    for(int j=ay;j<=by;j++)
    {
        if(canvas[ax][j]!=l || canvas[bx][j]!=l) return false;
    }
    return true;
}

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    int lc = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",canvas[i]+1);
        for(int j=1;j<=m;j++)
        {
            if(!mark[canvas[i][j]-'a']) lc++;
            mark[canvas[i][j]-'a']=true;
        }
    }
    if(lc==1)   //sp
    {
        //printf("isSp!\n");
        printf("%lld\n",1LL*m*n*(m-1)*(n-1)/4);
        return 0;
    }
    long long ans=0;
    for(int t=0;t<26;t++)
    {
        if(!mark[t]) continue;
        char l=t+'a';
        for(int ax=1;ax<n;ax++)
        {
            for(int ay=1;ay<m;ay++)
            {
                for(int bx=ax+1;bx<=n;bx++)
                {
                    for(int by=ay+1;by<=m;by++)
                    {
                        if(check(l,ax,ay,bx,by)) ans++;
                    }
                }
            }
        }
    }
    
    printf("%lld\n",ans);
    return 0;
}
