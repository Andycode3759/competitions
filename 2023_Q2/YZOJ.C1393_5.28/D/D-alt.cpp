#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 4000006;

long long uniNum[MAXN];

bool digi[11];
bool check(long long num)
{
    memset(digi, false, sizeof(digi));
    while (num > 0)
    {
        if (digi[num % 10])
            return false;
        digi[num % 10] = true;
        num /= 10;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    long long num = 1;
    for (int i = 1; i <= n; i++)
    {
        while (!check(num))
            num++;
        uniNum[i] = num;
        num++;
    }
    printf("%lld\n", uniNum[n]);
}