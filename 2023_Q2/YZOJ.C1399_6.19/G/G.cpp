// AC
#include <cstdio>
using namespace std;

int n;
unsigned long long k;
char bits[68];

int main()
{
    scanf("%d%llu", &n, &k);
    bits[n] = '0', bits[0] = '0';

    for (int i = n - 1; i >= 0; i--)
    {
        bits[i] = ((k & (1LL << i)) > 0) ? '1' : '0';
    }
    for (int i = n; i >= 1; i--)
    {
        bits[i] = ((int)(bits[i] - '0')) ^ ((int)(bits[i - 1] - '0')) + '0';
        // bits[i] = xor(bits[i], bits[i - 1]);
        printf("%c", bits[i]);
    }
    printf("\n");
    return 0;
}
