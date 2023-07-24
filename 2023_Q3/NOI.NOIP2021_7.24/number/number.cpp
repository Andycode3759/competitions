#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 10000007;

bool hasSeven[MAXN], vis[MAXN];
bool isNotPrime[MAXN];
int primeIdx[MAXN];

vector<int> primes;

inline bool checkSeven(int x)
{
    if (vis[x])
        return hasSeven[x];
    while (x > 0)
    {
        if (x % 10 == 7)
            return hasSeven[x] = true;
        x /= 10;
    }
    return hasSeven[x] = false;
}

bool isGood[MAXN], visGood[MAXN];

bool isOk(int x)
{
    if (x == 1)
        return true;
    if (visGood[x])
        return true;
    if (checkSeven(x))
    {
        visGood[x] = true;
        return isGood[x] = false;
    }
    for (int i = primeIdx[x]; i < primes.size(); i++)
    {
        int p = primes[i];
        if (p > x)
            break;
        if (x % p != 0)
            continue;
        if (checkSeven(p))
        {
            visGood[x] = true;
            return isGood[x] = false;
        }
        if (!isOk(x / p))
        {
            visGood[x] = true;
            return isGood[x] = false;
        }
    }
    visGood[x] = true;
    return true;

    /*
    get all factors of x
    check all factors
    */

    // printf("x=%d\n", rx);
    // for (int i = 0, len = breakDown.size(); i < len; i++)
    // {
    //     printf("base=%d exp=%d\n", breakDown[i].base, breakDown[i].exp);
    // }

    // for (int i = 2; i <= x / 2; i++)
    // {
    //     if (x % i == 0 && checkSeven(i))
    //     {
    //         return false;
    //     }
    // }
    // return true;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    isNotPrime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (isNotPrime[i])
            continue;
        primes.push_back(i);
        for (int j = 2; j * i < MAXN; j++)
            isNotPrime[i * j] = true;
    }
    for (int i = 0; i < MAXN; i++)
        primeIdx[i] = -1;
    for (int i = 0, len = primes.size(); i < len; i++)
    {
        int p = primes[i];
        for (int j = 1; j * p < MAXN; j++)
        {
            if (primeIdx[p * j] == -1)
                primeIdx[p * j] = i;
        }
    }

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int x;
        scanf("%d", &x);
        // do stuff
        if (!isOk(x))
        {
            printf("-1\n");
            continue;
        }

        int ans = x + 1;
        for (; !isOk(ans); ans++)
            ;
        printf("%d\n", ans);
    }

    return 0;
}
