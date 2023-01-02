//ACCEPETD
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+6;
int cc[MAXN]; //count of cost
//cc[i] => 学费为i的奶牛有多少头

int main()
{
	int n,input,maxc=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input);
		cc[input]++;
		if(input>maxc) maxc=input;
	}
	long long profit;
	long long maxProfit=-1;
	int ansCost;
	for(int i=maxc;i>=1;i--)
	{
		cc[i]+=cc[i+1];
		profit=1LL*cc[i]*i;
		if(profit>=maxProfit)
		{
			maxProfit=profit;
			ansCost=i;
		}
	}
	printf("%lld %d\n",maxProfit,ansCost);
	return 0;
}
