#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2505;
const int MOD = 1000000007;
typedef unsigned long long ull;

int v[MAXN][MAXN];
int n;
ull cnt,tot=0;

int findMod(ull x,ull y)
{
    for(int res=0;;res++)
    {
        if(res*y%MOD==x) return res;
    }
}

void dfs(int step,ull g)
{
    if(step>n)
    {
        cnt++;
        tot+=g;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        dfs(step+1,max(g,1ULL*v[step][i]));
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
    dfs(1,0);
    printf("%d\n",findMod(tot,cnt));
    return 0;
}
