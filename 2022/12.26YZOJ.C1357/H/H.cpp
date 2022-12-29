//ACCEPTED
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
int book[MAXN];
int n,ans;

void solve(int remain,int step)
{
    if(remain==0)
    {
        if(step==2) return;
        printf("%d=",n);
        for(int i=1;i<=step-2;i++)
        {
            printf("%d+",book[i]);
        }
        printf("%d\n",book[step-1]);
        ans++;
    }

    for(int i=book[step-1];i<=remain;i++)
    {
        book[step]=i;
        solve(remain-i,step+1);
    }
}


int main()
{
    scanf("%d",&n);
    book[0]=1;
    solve(n,1);
    printf("%d\n",ans);
    return 0;
}
