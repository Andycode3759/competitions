#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int ans=0;
    for(int c=1;c<=n;c++)
    {
        for(int i=n/c;i>=2;i--)
        {
            int a=i*c;
            if((a^c)==a-c) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
