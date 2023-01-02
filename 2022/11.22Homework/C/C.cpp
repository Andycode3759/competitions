/*
    Score: 100/100
    ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

double mem[300]; //f(n) = mem[n]

double getF(int n)
{
    if(mem[n]>0.0) return mem[n];
    double sum=0.0;
    for(int i=2;i<=n+1;i++)
    {
        sum+=1.0/i;
    }
    mem[n]=sum;
    return sum;
}

int main()
{
    double c;
    while(scanf("%lf",&c)==1 && c>0.0)
    {
        for(int i=0;;i++)
        {
            if(getF(i)>=c)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}