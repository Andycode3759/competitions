// AC
// Fixed: 2023.5.29
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, x, y;
        scanf("%lld%lld%lld", &n, &x, &y);
        long long cnt = n / __gcd(x, y);
        printf(cnt % 2 == 0 ? "lose\n" : "win\n");
    }
    return 0;
}
