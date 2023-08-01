#include<cstdio>
using namespace std;

bool check7(int x)
{
    while(x>0)
    {
        if(x%10==7) return true;
        x/=10;
    }
    return false;
}

bool isOk(int x)
{
    if(check7(x)) return false;
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0 && check7(i)) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x;
        scanf("%d",&x);
        if(!isOk(x))
        {
            printf("-1\n");
            continue;
        }
        do x++; while(!isOk(x));
        printf("%d\n",x);
    }
}