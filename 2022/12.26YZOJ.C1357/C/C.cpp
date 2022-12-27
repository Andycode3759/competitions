//ACCEPTED
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10004;
char sa[MAXN],sb[MAXN];
int numa[MAXN],numb[MAXN];
int ans[MAXN*2];

int main()
{
    scanf("%s %s",sa,sb);
    bool sig=true;
    int la=strlen(sa),lb=strlen(sb);
    if(sa[0]=='-')
    {
        sig=!sig;
        //la--;
    }
    if(sb[0]=='-')
    {
        sig=!sig;
        //lb--;
    }
    int shifta = sa[0]=='-'?1:0;
    int shiftb = sb[0]=='-'?1:0;
    int tot=0;
    for(int i=la-1;i>=shifta;i--)
    {
        numa[tot]=sa[i]-'0';
        tot++;
    }
    tot=0;
    for(int i=lb-1;i>=shiftb;i--)
    {
        numb[tot]=sb[i]-'0';
        tot++;
    }

    for(int a=0;a<MAXN;a++)
    {
        for(int b=0;b<MAXN;b++)
        {
            int t=a+b;
            ans[t]+=numa[a]*numb[b];
            ans[t+1]+=ans[t]/10;
            ans[t]%=10;
        }
    }
    if(!sig) printf("-");
    bool flag=false;
    for(int i=2*MAXN-1;i>=0;i--)
    {
        if(ans[i]>0) flag=true;
        if(flag)
        {
            printf("%d",ans[i]);
        }
    }
    if(!flag) printf("0");
    printf("\n");

    return 0;
}
