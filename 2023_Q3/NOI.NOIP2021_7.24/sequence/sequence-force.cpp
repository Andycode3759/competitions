#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 105;
const ll MOD = 998244353;

int n,m,k;
int v[MAXN];
int a[MAXN];
ll ans;

int count1(ll x)
{
	int res=0;
	while(x>0)
	{
		x-=(x&(-x));
		res++;
	}
	return res;
}

void dfs(int step,ll s,ll val)
{
	if(step>=n+1)
	{
		int cnt=count1(s);
		if(cnt<=k) ans=(ans+val)%MOD;
		return;
	}
	for(int i=0;i<=m;i++)
	{
		a[step]=i;
		dfs(step+1,s+(1<<i),val*v[i]%MOD);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
        scanf("%d",v+i);
    }
	dfs(1,0,1);
	printf("%lld\n",ans);
	return 0;
}