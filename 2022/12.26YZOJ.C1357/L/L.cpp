//UNFINISHED
#include<bits/stdc++.h>
using namespace std;
const int MAXSIZE = 50005;
int rocks[MAXSIZE];
 
bool isOK(int maxJump,int moves,int r)
{
    int dis[MAXSIZE];
    memset(dis,0,MAXSIZE*sizeof(int));
    for(int i=1;i<=r;i++)
    {
        dis[i]=rocks[i]-rocks[i-1];
    }
    sort(dis,dis+r);
    return dis[moves-1]>=maxJump;
}
 
int main()
{
    int dis,count,move;
    scanf("%d%d%d",&dis,&count,&move);
    for(int i=1;i<=count;i++)
    {
        scanf("%d", &rocks[i]);
    }
    // int l=1,r=dis;
    // int mid=(l+r)/2;
    // int ans=1;
    // while(l<=r)
    // {
    //     mid=(l+r)/2;
    //     if(isOK(mid,move,count))
    //     {
    //         ans=mid;
    //         l=mid+1;
    //     }
    //     else
    //     {
    //         r=mid-1;
    //     }
    // }
    int k=1;
    while(isOK(k++,move,count));
    printf("%d\n",k);
    return 0;
}
