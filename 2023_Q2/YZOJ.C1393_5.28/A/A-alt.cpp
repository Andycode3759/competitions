#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;

int n;
int graph[MAXN];

int main()
{
    scanf("%d", &n);
    if (n > 500)
        return 0;
    int s, t, h;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &s, &t, &h);
        for (int j = s; j < t; j++)
        {
            graph[j] = max(graph[j], h);
        }
    }
    long long res = 0;
    for (int i = 1; i < MAXN; i++)
    {
        res += graph[i];
    }
    printf("%lld\n", res);
    return 0;
}