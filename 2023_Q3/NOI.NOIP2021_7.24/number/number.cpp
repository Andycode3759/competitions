#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 10000007;

bool isBad[MAXN];
int nxt[MAXN];

bool check7(int x)
{
    while(x>0)
    {
        if(x%10==7) return true;
        x/=10;
    }
    return false;
}

int n;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    for(int i=7;i<MAXN;i++)
    {
        if(check7(i))
        {
            for(int j=1;j*i<MAXN;j++)
            {
                isBad[i*j]=true;
            }
        }
    }

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d",&n);
        if(isBad[n])
        {
            printf("-1\n");
            continue;
        }
        if(nxt[n]!=0)
        {
            printf("%d\n",nxt[n]);
            continue;
        }
        int t=n;
        do n++; while(isBad[n]);
        nxt[t]=n;
        printf("%d\n",n);
    }
    // for(int i=3100;i<=3200;i++)
    // {
    //     printf("nxt[%d]=%d isBad[%d]=%d\n",i,nxt[i],i,isBad[i]);
    // }

    return 0;
}
