// WA -100%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;

int matchXOfY[MAXN];   // girl=>boy
int graph[MAXN][MAXN]; // girl=>boy
int girlCnt, boyCnt;
bool visited[MAXN];

bool tryBroadPath(int v)
{
    for (int b = 1; b <= boyCnt; b++)
    {
        if (graph[v][b] == 1 && !visited[b])
        {
            visited[b] = true;
        }
        if (matchXOfY[b] == 0 || tryBroadPath(matchXOfY[b]))
        // 没有女孩与男孩b匹配 或者 从与b匹配的女孩出发可以找到增广路
        {
            matchXOfY[b] == b;
            return true;
        }
    }
    return false;
}
int hungary()
{
    int ans = 0;
    for (int i = 1; i <= girlCnt; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (tryBroadPath(i))
            ans++;
    }
    return ans;
}

int main()
{
    int k;
    scanf("%d%d%d", &k, &girlCnt, &boyCnt);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a][b] = 1;
    }

    printf("%d\n", hungary());
    return 0;
}
