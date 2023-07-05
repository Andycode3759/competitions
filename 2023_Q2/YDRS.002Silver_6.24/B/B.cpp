#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 500005;
const int BASE = 29;
char str[MAXN];
unsigned long long strHash[MAXN];
unsigned long long basePow[MAXN];
int minF[MAXN];
int n, q;

struct Factor
{
    int val = 0, pow = 0;
};
vector<Factor> factors;
vector<int> primes;

int read()
{
    char c = getchar();
    int res = 0;
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int solve(int l, int r)
{
    int len = r - l + 1;

    factors.clear();
    Factor fa;
    int lt = len;
    while (lt > 1)
    {
        fa.val = minF[lt], fa.pow = 0;
        while (lt % fa.val == 0)
        {
            fa.pow++;
            lt /= fa.val;
        }
        factors.push_back(fa);
    }

    int ans = len;
    for (int i = 0; i < factors.size(); i++)
    {
        while (factors[i].pow > 0)
        {
            int newLen = ans / factors[i].val;
            unsigned long long hash1 = strHash[r - newLen] - strHash[l - 1] * basePow[r - newLen - l + 1];
            unsigned long long hash2 = strHash[r] - strHash[l + newLen - 1] * basePow[r - l - newLen + 1];
            if (hash1 == hash2)
            {
                factors[i].pow--;
                ans /= factors[i].val;
            }
            else
                break;
        }
    }
    return ans;
}

int main()
{
    n = read();
    for (int i = 2; i <= n; i++)
    {
        if (minF[i] > 0)
            continue;
        for (int j = 1; j * i <= n; j++)
        {
            if (minF[i * j] == 0)
                minF[i * j] = i;
        }
    }
    scanf("%s", str + 1);
    basePow[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        basePow[i] = basePow[i - 1] * BASE;
        strHash[i] = strHash[i - 1] * BASE + str[i] - 'a';
    }
    q = read();
    while (q--)
    {
        int l, r;
        l = read(), r = read();
        printf("%d\n", solve(l, r));
    }
    return 0;
}
