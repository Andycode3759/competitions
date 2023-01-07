// ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202;
// const int INF = 1e9 + 9;
bool graph[MAXN][MAXN];
// graph[i][j] = true  =>  i可以把资料发给j
bool hasData[MAXN];
int source[MAXN];
// source[i] => i最高可以找谁要资料（并查集）

int getSource(int me)
{
    if (source[me] == me)
        return me;
    else
        return source[me] = getSource(source[me]);
}
void merge(int a, int b)
{
    if (source[a] == source[b])
        return;
    // printf("merge: %d -> %d\n", b, a);
    source[b] = a;
}

int main()
{
    int n;
    scanf("%d", &n);

    // init
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = i == j; // 自己当然可以把资料给自己
        }
        source[i] = i;
    }

    // read paths
    for (int i = 1; i <= n; i++)
    {
        int input;
        while (scanf("%d", &input) && input != 0)
        {
            graph[i][input] = true;
        }
    }

    // Floyd
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                // 如果i不愿意把资料给j，那就找k中转一下，i把资料给k，k再把资料给j
                // 这么做的前提是i愿意给资料给k 且 k愿意给资料给j
            }
        }
    }

    // make ans
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j])
            {
                // printf("try merge %d -> %d\n", j, i);
                merge(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        getSource(i); // compress path
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (source[i] == i)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
