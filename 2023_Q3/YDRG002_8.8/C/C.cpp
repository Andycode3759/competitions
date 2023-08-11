#include <bitset>
#include <cstdio>
#include <cstring>
using namespace std;

unsigned long long a, c, x;
int q, k;
int cnt = 0;
unsigned long long X;

inline unsigned long long read()
{
    if (++cnt <= k)
    {
        scanf("%llu", &X);
        return X;
    }
    else
    {
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        return X = (X + a) % c;
    }
}

unsigned long long solve()
{
    unsigned long long res = 0;
    bitset<66> B(x);

    unsigned long long combo = 0;
    for (int i = 0; i <= 59; i++)
    {
        if (B[i] == 1)
            combo++;
        else
            res += ((combo * (combo + 1)) >> 1), combo = 0;
    }
    res += ((combo * (combo + 1)) >> 1);
    return res;
}

int main()
{
    scanf("%d %d %llu %llu", &q, &k, &a, &c);
    unsigned long long res = 0;
    for (int i = 1; i <= q; i++)
    {
        x = read();
        res = res ^ (i * solve());
    }
    printf("%llu\n", res);
    return 0;
}