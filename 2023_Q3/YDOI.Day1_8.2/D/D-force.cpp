#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int ans=0;
    for(int l=1;l<=n;l++)
    {
        for(int r=l+1;r<=n;r++)
        {
            if((l^r)==__gcd(l,r)) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
