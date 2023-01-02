/*
    Score: 100/100
    ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int mem[1002];

int getNum(int n)
{
    if(mem[n]>0) return mem[n];
    int sum=1;
    for(int i=1;i<=n/2;i++)
    {
        sum+=getNum(i);
    }
    mem[n]=sum;
    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",getNum(n));
    return 0;
}