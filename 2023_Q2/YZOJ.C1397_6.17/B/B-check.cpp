#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000006;

long long num;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &num);
        if (num <= 2)
            printf("1\n");
        else if (num % 2 == 1)
            printf("%lld\n", (num - 1) / 2);
        else
            printf("%lld\n", num / 2 - ((num % 4LL == 0) ? 1 : 2));
    }

    return 0;
}