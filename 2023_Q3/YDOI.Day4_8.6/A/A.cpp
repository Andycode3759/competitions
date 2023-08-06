#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,a,b;

void solveSP()
{
    printf("%d\n",max(0,n-m));
}
void solveGeneral()
{
    int lstA=b,lstB=a;
    while(n>0&&m>0)
    {
        lstA-=m;
        lstB-=n;
        while(lstA<=0&&n>0) lstA+=b,n--;
        while(lstB<=0&&m>0) lstB+=a,m--;
    }
    printf("%d\n",n);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&m,&a,&b);
        if(a==1&&b==1) solveSP();
        else solveGeneral();
    }    
    return 0;
}
