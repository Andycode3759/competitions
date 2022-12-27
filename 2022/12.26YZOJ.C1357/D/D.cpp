//UNFINISHED
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1003;

struct BigNum
{
    char digits[MAXN];

    void add(long long n)
    {
        
    }

    void print()
    {

    }
};
BigNum step[MAXN];

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    step[m]=1;
    step[m+1]=1;
    for(int i=m+2;i<=n;i++)
    {
        step[i]=step[i-1]+step[i-2];
    }
    printf("%lld\n",step[n]);
    return 0;
}
