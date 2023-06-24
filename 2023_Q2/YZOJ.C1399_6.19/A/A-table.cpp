#include <cstdio>
using namespace std;
const int MAXN = 20;

long long f[MAXN];

int main()
{
    f[1] = 1, f[2] = 3;
    for (int i = 3; i < MAXN; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        printf("f[%d]=%lld\n", i, f[i]);
    }

    long long sum = f[1] * f[1];
    for (int i = 2; i < MAXN - 1; i++)
    {
        sum += f[i] * f[i];
        printf("n=%d f(n)=%lld form1=%lld form2=%lld\n", i, f[i], f[i] * f[i] - f[i + 1] * f[i - 1], sum);
    }

    return 0;
}
