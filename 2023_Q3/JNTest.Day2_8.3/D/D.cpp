#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 20000007;

struct Point
{
    Point(int _i,int _w):idx(_i),wei(_w){}
    int idx,wei;
    const bool operator<(const Point &b) const
    {
        return idx==b.idx?wei<b.wei:idx<b.idx;
    }
};
set<Point> mark;

int n, limw, k, limv;
unsigned int a,b;
int v[MAXN],w[MAXN];

long long dp[MAXN];

void myrand(unsigned &a, unsigned &b) {
    unsigned c,d;
    c=a<<15^b;
    d=c>>15^(a^b);
    a=c<<3^d, b=((a<<7)^c)>>3;
}
void getvw(void) {
    for(int i=1;i<=n;++i) 
        myrand(a,b),v[i]=a%1000000000+1,w[i]=b%limv+1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        mark.clear();
        scanf("%d %d %d %u %u %d",&n,&limw,&k,&a,&b,&limv);
        getvw();
        long long res=0;

        for(int i=1;i<=limw;i++) dp[i]=0;
        for(int i=1;i<=k;i++)
        {
            for(int j=limw;j>=w[i];j--)
            {
                if(dp[j-w[i]]+v[i]>dp[j])
                {
                    dp[j]=dp[j-w[i]]+v[i];
                    mark.insert(Point(i,j));
                }
            }
        }
        res=dp[limw];

        for(int s=2;s<=n-k+1;s++)
        {
            int l=s,r=s+k-1;
            long long ans=0;
            for(int i=0;i<=limw;i++)
            {
                if(mark.count(Point(l-1,i)))
                {
                    dp[i]-=v[l-1];
                }
            }
            for(int j=limw;j>=w[r];j--)
            {
                if(dp[j-w[r]]+v[r]>dp[j])
                {
                    dp[j]=dp[j-w[r]]+v[r];
                    mark.insert(Point(r,j));
                }
            }
            ans=dp[limw];
            res^=ans;
        }
        printf("%lld\n",res);
    }
    return 0;
}