#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 5000006;
const int MOD = 998244353;

ll ksm(ll a, ll b)
{
    ll ret = 1;
    for(; b; b >>= 1, a = (a * a) % MOD)
    {
        if(b & 1)
        {
            ret = ret * a % MOD;
        }
    }
    return ret;
}
int getinv(int x)
{
    return ksm(x, MOD-2);
}

struct Point
{
    int type;//1 problem, 2 result
    int dest;
};
vector<Point> G[MAXN];

int n;
char input[18];

ll cnt[30];
ll tot;

void dfs(int cur)
{
    for(int i=0,len=G[cur].size();i<len;i++)
    {
        Point v=G[cur][i];
        if(v.type==1)
        {
            dfs(v.dest);
        }
        else if(v.type==2)
        {
            cnt[v.dest]++;
            tot++;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%s",input);
            Point p;
            if(input[0]>='A'&&input[0]<='Z')
            {
                p.type=2;
                p.dest=input[0]-'A'+1;
            }
            else
            {
                sscanf(input,"%d",&p.dest);
                p.type=1;
            }
            G[i].push_back(p);
        }
    }
    dfs(1);
    tot=getinv(tot);
    for(int i=1;i<=26;i++)
    {
        printf("%lld ",cnt[i]*tot%MOD);
        //printf("%lld ",cnt[i]);
    }
    printf("\n");
    return 0;
}