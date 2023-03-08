// WA
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, delta, k, n;
    long long t;
    scanf("%d%d%d%d%lld", &x, &delta, &k, &n, &t);
    long long profit = 0;
    long long totalSold = 0;
    for (int i = n; i >= 1; i--)
    {
        int price = totalSold / k * delta + x;
        profit += price * i;
        totalSold += i;
        if (profit >= t)
        {
            printf("%d\n", n - i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
