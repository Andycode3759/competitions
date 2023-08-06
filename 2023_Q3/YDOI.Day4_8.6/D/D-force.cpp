#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000006;
const int MOD = 1e9+7;

int n;
int perm[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        perm[i]=i;
    }
    int ans=0;
    do
    {
        perm[n+1]=perm[1];
        bool flag=true;
        for(int i=2;i<=n+1;i++)
        {
            if(perm[i]%perm[i-1]>2)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            ans++;
            if(ans>=MOD) ans-=MOD;
        }
    } while (next_permutation(perm+1,perm+1+n));
    printf("%d\n",ans);
    return 0;
}
