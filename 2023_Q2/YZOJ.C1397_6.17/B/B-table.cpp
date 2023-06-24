#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000006;

int num;
bool fmark[MAXN], dmark[MAXN];
int k;

int main()
{
    fmark[1] = true;
    for (int d = 2; d < MAXN; d++)
    {
        if (fmark[d])
            continue;
        for (int f = 1; f * d < MAXN; f++)
        {
            fmark[d * f] = true;
        }
    }
    int T;
    scanf("%d", &T);
    for (int num = 1; num <= T; num++)
    {
        k = 0;
        memset(dmark, false, sizeof(dmark));
        if (fmark[num])
        {
            for (int i = 1; i <= num; i++)
            {
                dmark[i] = fmark[i] ? (__gcd(i, num) == 1) : true;
                if (dmark[i])
                    k++;
            }
            int count = 0;
            for (int i = 1; i <= num; i++)
            {
                if (dmark[i])
                    count++;
                if (count == (k + 1) / 2)
                {
                    printf("num=%d ans=%d\n", num, i);
                    break;
                }
            }
        }
        else
        {
            printf("num=%d ans=%d\n", num, num >> 1);
        }
    }
    return 0;
}