// AC
#include <cstdio>
using namespace std;
const int MAXN = 5005;
const long long BASE = 100000000LL; // 1e8
const int MAX_DIGIT = 80;

int max(int a, int b)
{
    return a > b ? a : b;
}

struct BigInt
{
    unsigned long long data[MAX_DIGIT];
    int digit = 0;

    void assign0()
    {
        for (int i = 0; i < MAX_DIGIT; i++)
        {
            data[i] = 0;
        }
        digit = 0;
    }
    void assign1()
    {
        assign0();
        digit = 1;
        data[0] = 1;
    }
    void add(BigInt x)
    {
        digit = max(digit, x.digit);
        for (int i = 0; i < digit; i++)
        {
            data[i] += x.data[i];
        }
        for (int i = 0; i <= digit; i++)
        {
            data[i + 1] += data[i] / BASE;
            data[i] %= BASE;
        }
        while (data[digit] > 0)
            digit++;
    }
    void print()
    {
        for (int i = digit - 1; i >= 0; i--)
        {
            // printf("%c", data[i] + '0');
            if (i == digit - 1)
                printf("%llu", data[i]);
            else
                printf("%08llu", data[i]);
        }
        printf("\n");
    }
};

BigInt ans[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    ans[0].assign1();
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= MAXN; i++)
        {
            ans[i].assign0();
        }
        for (int m = 1; m <= n; m++)
        {
            for (int i = m; i <= n; i++)
            {
                ans[i].add(ans[i - m]);
            }
        }
        ans[n].print();
    }

    return 0;
}