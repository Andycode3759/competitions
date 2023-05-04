// TLE
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int arr[MAXN];

int read()
{
    int res = 0;
    int neg = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            neg = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * neg;
}

int MxAb(int i, int j)
{
    return abs(arr[i]) + abs(arr[j]);
}

int main()
{
    int K = read();
    while (K--)
    {
        int n = read();
        for (int i = 0; i < n; i++)
        {
            arr[i] = read();
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans += MxAb(i, j);
            }
        }
        ans *= 2;
        for (int i = 0; i < n; i++)
        {
            ans += MxAb(i, i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
