// AC
#include <cstdio>
#include <utility>
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
            data[digit++] = c - '0';
            c = getchar();
        }
        for (int i = 0; i < digit / 2; i++)
        {
            swap(data[i], data[digit - i - 1]);
        }
    }
    void print()
    {
        if (digit == 0)
        {
            printf("0\n");
            return;
        }
        for (int i = digit - 1; i >= 0; i--)
        {
            printf("%c", data[i] + '0');
        }
        printf("\n");
    }
    void subtract(int x)
    {
        data[0] -= x;
        for (int i = 0; data[i] < 0; i++)
        {
            int r = (-data[i] - 1) / 10 + 1;
            data[i + 1] -= r;
            data[i] += 10 * r;
        }
        updateDigit();
    }
    void half()
    {
        int left = 0;
        for (int i = digit - 1; i >= 0; i--)
        {
            left = left * 10 + data[i];
            data[i] = left / 2;
            left %= 2;
        }
        updateDigit();
    }
    void updateDigit()
    {
        for (int i = digit - 1; i >= 0; i--)
        {
            if (data[i] != 0)
                break;
            else
                digit--;
        }
    }
};

BigInt num;
// long long num;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        num.clearAndRead();
        if (num.digit <= 1 && num.data[0] <= 2)
            printf("1\n");
        else if (num.data[0] % 2 == 1)
        {
            num.subtract(1);
            num.half();
            num.print();
        }
        else
        {
            bool isMult = (num.data[0] + num.data[1] * 10) % 4 == 0;
            num.half();
            num.subtract(isMult ? 1 : 2);
            num.print();
        }
    }
    return 0;
}