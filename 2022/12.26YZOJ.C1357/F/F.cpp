//ACCEPTED
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,p,ans=1;
    scanf("%lld%lld%lld",&a,&b,&p);
    while(b)
    {
        if(b&1)
        {
            ans*=a%p;
            ans%=p;
        }
        a=(a%p)*(a%p);
        b=b>>1;
    }
    printf("%lld\n",ans%p);
    return 0;
}
