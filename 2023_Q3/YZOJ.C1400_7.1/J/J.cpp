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
int query[12], maxq = -1;

int main()
{
    int T;
    scanf("%d", &T);
    ans[0].assign1();
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", query + i);
        maxq = max(maxq, query[i]);
    }

    for (int i = 1; i <= MAXN; i++)
    {
        ans[i].assign0();
    }
    for (int m = 1; m <= maxq; m++)
    {
        for (int i = m; i <= maxq; i++)
        {
            ans[i].add(ans[i - m]);
        }
    }

    for (int i = 1; i <= T; i++)
    {
        ans[query[i]].print();
    }

    return 0;
}