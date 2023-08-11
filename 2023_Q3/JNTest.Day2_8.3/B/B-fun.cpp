// 模拟退火，图一乐 :)
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAXN = 200005;

inline int randInt(int l,int r)
{
    return rand()%(r-l+1)+l;
}
inline int roll(int prob)
{
    return randInt(1,100)<=prob;
}

int arr[MAXN];
int n;
int ans=0;
bool mark[MAXN];
int len=0;

inline bool check()
{
    if(len==1) return true;
    int t=(2*len+1)/3;
    for(int i=1,cnt=0,lst=-1;i<=n;i++)
    {
        if(!mark[i]) continue;
        cnt++;
        if(cnt<=t)
        {
            if(lst!=-1 && arr[i]!=lst+1) return false;
            lst=arr[i];
        }
        else
        {
            if(lst!=-1 && arr[i]!=lst-1) return false;
            lst=arr[i];
        }
    }
    return true;
}

int main()
{
    srand(time(0));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    long startTime = clock();
    while(ans<n && 1.0*(clock()-startTime)/CLOCKS_PER_SEC<=0.95)
    {
        int t=randInt(1,n);
        while(mark[t]) t=randInt(1,n);
        mark[t]=true;
        len++;

        // for(int i=1;i<=n;i++)
        // {
        //     if(mark[i]) printf("%d ",arr[i]);
        // }
        // printf("\n");

        if(check()) ans=max(ans,len);
        else if(roll(len*160/n)) mark[t]=false,len--;
    }
    printf("%d\n",ans);
    return 0;
}
