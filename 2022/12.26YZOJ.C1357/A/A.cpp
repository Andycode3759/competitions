//ACCEPTED
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 302;
char sa[MAXN],sb[MAXN];
int numa[MAXN],numb[MAXN];

int main()
{
    scanf("%s %s",sa,sb);
    int la=strlen(sa),lb=strlen(sb);
    for(int i=la-1;i>=0;i--)
    {
        numa[la-i-1]=sa[i]-'0';
    }
    for(int i=lb-1;i>=0;i--)
    {
        numb[lb-i-1]=sb[i]-'0';
    }

    for(int i=0;i<MAXN;i++)
    {
        numa[i]+=numb[i];
        numa[i+1]+=numa[i]/10;
        numa[i]%=10;
    }

    bool flag=false;
    for(int i=MAXN-1;i>=0;i--)
    {
        if(numa[i]>0) flag=true;
        if(flag)
        {
            printf("%d",numa[i]);
        }
    }
    if(!flag) printf("0");
    printf("\n");

    return 0;
}
