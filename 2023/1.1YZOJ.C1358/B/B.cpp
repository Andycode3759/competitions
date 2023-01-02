// Score: 33/100
#include<bits/stdc++.h>
using namespace std;
const int MAXN=808;
int mapSize;
int ground[MAXN][MAXN];

int main()
{
	long long cakeSum=0;
	scanf("%d",&mapSize);
	for(int x=1;x<=mapSize;x++)
	{
		for(int y=1;y<=mapSize;y++)
		{
			int input;
			scanf("%d",&input);
			ground[x][y]=input;
			cakeSum+=input;
		}
	}
	
	//如果mapSize为奇数 则一定可以遍历所有点
	
	if(mapSize%2==1)
	{
		printf("%lld\n",cakeSum);
	}
	else
	{
		long long ans=-1;
		for(int i=0;i<DZ;i++)
		{
			long long nowAns = cakeSum-ground[deadZone[i][0]][deadZone[i][1]];
			if(nowAns>ans) ans=nowAns;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
