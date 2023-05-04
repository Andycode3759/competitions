// Unfinished
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int kase = 0; kase < t; kase++)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        k = k % (n + 1);
        printf("%d\n", k);
        for (int i = 1; i <= n; i++)
        {
            printf("%d %d\n", i <= k ? (i - k + n) : i - k, i);
        }
    }
    return 0;
}
/*
n=2 k=1
1 2 0
0 1 2
2 0 1
1 2 0


*/