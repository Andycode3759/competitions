// AC
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int pow10(int x)
{
    return (int)pow(x, 10);
}

int getCoin(long long s)
{
    return (((s % 7 * (int)1e9) % 7) + s % 7) % 7;
}

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    char str[11];
    int cards;
    vector<int> qpos;
    vector<int> unknowns;
    bool isKnown[13];
    while (scanf("%s", str) > 0)
    {
        cards = 0;
        qpos.clear();
        unknowns.clear();
        memset(isKnown, 0, sizeof(isKnown));
        for (int i = 0; i <= 8; i++)
        {
            int a;
            if (str[i] == '?')
            {
                a = 0;
                qpos.push_back(8 - i);
            }
            else
            {
                a = str[i] - '0';
                isKnown[a] = true;
            }
            cards = cards * 10 + a;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (!isKnown[i])
                unknowns.push_back(i);
        }
        printf("cards=%d\n", cards);
        long long coinsum = 0;
        long long stateCount = 1;
        sort(unknowns.begin(), unknowns.end());
        while (next_permutation(unknowns.begin(), unknowns.end()))
        {
            for (int i = 0; i < qpos.size(); i++)
            {
                cards += unknowns[i] * pow10(qpos[i]);
                coinsum += getCoin(cards);
            }
            stateCount++;
        }
        if (qpos.empty())
        {
            printf("%d\n", getCoin(cards));
        }
        else
        {
            long long g = gcd(coinsum, stateCount);
            printf("coinsum=%lld stateCount=%lld gcd=%lld\n", coinsum, stateCount, g);
            coinsum /= g;
            coinsum %= MOD;
            stateCount /= g;
            if (coinsum % stateCount == 0)
            {
                printf("%lld\n", coinsum / stateCount);
            }
            else
            {
                printf("%lf\n", (double)1.0 * coinsum / stateCount);
            }
        }
    }
    return 0;
}
