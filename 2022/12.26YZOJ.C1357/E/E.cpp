// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;

struct BigNum
{
    int digits[MAXN];

    void init(long long num)
    {
        for (int i = 0; i < MAXN; i++)
        {
            digits[i] = 0;
        }
        add(num);
    }
    void add(long long num)
    {
        int pow = 0;
        while (num)
        {
            digits[pow] += num % 10;
            num /= 10;
            digits[pow + 1] += digits[pow] / 10;
            digits[pow] %= 10;
            pow++;
        }
    }
    void add(BigNum num)
    {
        for (int i = 0; i < MAXN; i++)
        {
            digits[i] += num.digits[i];
            digits[i + 1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }
    void print()
    {
        bool flag = true;
        for (int i = MAXN - 1; i >= 0; i--)
        {
            if (digits[i] > 0)
            {
                flag = false;
            }
            if (!flag)
            {
                printf("%d", digits[i]);
            }
        }
        if (flag)
            printf("0");
    }
};
BigNum step[MAXN];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    step[m].init(1);
    step[m + 1].init(1);
    for (int i = m + 2; i <= n; i++)
    {
        step[i].add(step[i - 1]);
        step[i].add(step[i - 2]);
    }
    step[n].print();
    printf("\n");
    return 0;
}
