#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000006;

struct BigInt
{
    int data[MAXN];
    int digit = 0;

    void clearAndRead()
    {
        char c = getchar();
        digit = 0;
        while (c < '0' || c > '9')
            c = getchar();
        while (c >= '0' && c <= '9')
        {
            c = getchar();
            data[digit++] = c - '0';
        }
    }
};

// BigInt num;
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
    while (T--)
    {
        k = 0;
        memset(dmark, false, sizeof(dmark));
        // num.clearAndRead();
        scanf("%d", &num);
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
                    printf("%d\n", i);
                    break;
                }
            }
        }
        else
        {
            printf("%d\n", num >> 1);
        }
    }

    return 0;
}
