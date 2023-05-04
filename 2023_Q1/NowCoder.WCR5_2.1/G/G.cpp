// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 65540;
int code[MAXN];
int n;

int getBitAt(int num, int bit)
{
    return (num >> bit) & 1;
}
void setBitAt(int &num, int bit, bool val)
{
    int mask = 1 << bit;
    mask = ~mask;
    num = num & mask;
    num += val << bit;
}
bool existed(int _code, int upbound)
{
    for (int i = 0; i < upbound; i++)
    {
        if (_code == code[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n / 2; i++)
    {
        scanf("%d", &code[i * 2]);
    }
    for (int i = 1; i < n; i += 2)
    {
        int up = code[i - 1], down = code[i + 1];
        int diff = up ^ down;
        bool flag = false;
        int result = 0;
        int bit = 0;
        for (; bit <= 16; bit++)
        {
            if (getBitAt(diff, bit))
            {
                int resTemp = result;
                flag = false;
                if (flag)
                {
                    setBitAt(resTemp, bit, getBitAt(down, bit));
                }
                else
                {
                    setBitAt(resTemp, bit, getBitAt(up, bit));
                    flag = true;
                }
                if (existed(resTemp, n))
                {
                    flag = false;
                    if (flag)
                    {
                        setBitAt(resTemp, bit, getBitAt(up, bit));
                    }
                    else
                    {
                        setBitAt(resTemp, bit, getBitAt(down, bit));
                        flag = true;
                    }
                }
                result = resTemp;
            }
            else
            {
                setBitAt(result, bit, getBitAt(up, bit));
            }
        }
        code[i] = result;
    }
    if (n % 2 == 0)
    {
        code[n - 1] = code[0];
        int bit = 0;
        while (existed(code[n - 1], n - 1))
        {
            code[n - 1] = code[n - 2];
            code[n - 1] = code[n - 1] ^ (1 << bit);
            bit++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", code[i]);
    }
    printf("\n");
    return 0;
}
