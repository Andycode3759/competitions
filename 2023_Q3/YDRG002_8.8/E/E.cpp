#include <cstdio>
using namespace std;
constexpr int MAXN = 200005;

int n, k;
int arr[MAXN];

long long getF(long long x)
{
    return ((x + 2) * (x + 1)) >> 1;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }

    long long res = getF(n / k + 1) * (n % k) + getF(n / k) * (k - n % k);
    printf("%lld\n", res);

    return 0;
}