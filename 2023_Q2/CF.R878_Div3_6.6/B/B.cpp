#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXB = 31;

int n,k;
int dp[MAXB];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        k=min(k,30);
        dp[0]=1;
    }
}
