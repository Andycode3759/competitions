#include <cstdio>
#include <utility>
using namespace std;
const int MAXN = 1000006;

int data[MAXN];
int digit = 0;
int x, left, r;
char c;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        c = getchar();
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

        if (digit <= 1 && data[0] <= 2)
            printf("1\n");
        else if (data[0] % 2 == 1)
        {
            data[0] -= 1;
            for (int i = 0; data[i] < 0; i++)
            {
                r = (-data[i] - 1) / 10 + 1;
                data[i + 1] -= r;
                data[i] += 10 * r;
            }
            if (data[digit - 1] == 0)
                digit--;
            left = 0;
            for (int i = digit - 1; i >= 0; i--)
            {
                left = left * 10 + data[i];
                data[i] = left / 2;
                left %= 2;
            }
            if (data[digit - 1] == 0)
                digit--;
            if (digit == 0)
            {
                printf("0\n");
            }
            else
            {
                for (int i = digit - 1; i >= 0; i--)
                {
                    printf("%c", data[i] + '0');
                }
            }
            printf("\n");
        }
        else
        {
            x = ((data[0] + data[1] * 10) % 4 == 0) ? 1 : 2;
            left = 0;
            for (int i = digit - 1; i >= 0; i--)
            {
                left = left * 10 + data[i];
                data[i] = left / 2;
                left %= 2;
            }
            if (data[digit - 1] == 0)
                digit--;
            data[0] -= x;
            for (int i = 0; data[i] < 0; i++)
            {
                r = (-data[i] - 1) / 10 + 1;
                data[i + 1] -= r;
                data[i] += 10 * r;
            }
            if (data[digit - 1] == 0)
                digit--;
            if (digit == 0)
            {
                printf("0\n");
            }
            else
            {
                for (int i = digit - 1; i >= 0; i--)
                {
                    printf("%c", data[i] + '0');
                }
            }
            printf("\n");
        }
    }
    return 0;
}
