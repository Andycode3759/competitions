#include <cstdio>
#include <cmath>
using namespace std;
const int MOD = 1e9+9;
const int MAXN = 1000006;

int n,m;

int solveSP1() // n,m<=8
{
	int mx = pow(m, n);
	int res = 0;
	for (int i = 1; i <= mx; i++)
	{
	    int a = i;
	    bool ok = true;
	    for (int j = 1; j <= n; j++)
	    {
	    	if (a == 1)
	        {
	            ok = false;
	            break;
	        }
	        if (a % m == 0)
	            a /= m;
	        else
	            a++;
	    }
	    if (a == 1 && ok)
	        res++;
	    if (res >= MOD)
	        res -= MOD;
	}
	return res;
}

int f[MAXN];
int solveSP2() // m=2
{
	f[1]=1,f[2]=1;
	for(int i=3;i<=n;i++)
	{
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	return f[n];
}
int solveSP3() // n<m
{
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=(f[i-1]<<1)%MOD;
	}
	return f[n];
}
int solveGeneral()
{
	return solveSP1();
}
int main()
{
	scanf("%d%d",&m,&n);
	if(n==1) printf("1\n");
	else if(n<=8 && m<=8) printf("%d\n",solveSP1());
	else if(m==2) printf("%d\n",solveSP2());
	else if(n<m) printf("%d\n",solveSP3());
	else printf("%d\n",solveGeneral());
	return 0;
}