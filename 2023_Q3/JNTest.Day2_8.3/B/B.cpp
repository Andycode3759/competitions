#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 200005;

int arr[MAXN];
int inc[MAXN],dec[MAXN],lst[MAXN];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    for(int i=1;i<=n;i++)
    {
        inc[i] = lst[arr[i]-1]>0 ? inc[lst[arr[i]-1]]+1 : 0;
        lst[arr[i]]=i;
    }
    for(int i=1;i<=n;i++) lst[i]=0;
    for(int i=n;i>=1;i--)
    {
        dec[i] = lst[arr[i]-1]>0 ? dec[lst[arr[i]-1]]+1 : 0;
        lst[arr[i]]=i;
    }
    int ans=0;
    for(int t=1;t<=n;t++)
    {
        ans=max(ans,min(inc[t]/2,dec[t])*3+1);
    }
    printf("%d\n",ans);
    return 0;
}
