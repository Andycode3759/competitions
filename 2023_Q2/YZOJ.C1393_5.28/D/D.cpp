// AC
// Fixed: 2023.5.29
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 8900000;

long long uniNum[MAXN];
int uCnt = 0;
int n;

bool vis[12];
void dfs(int step, int maxDepth, long long cur)
{
    if (step > maxDepth)
    {
        uniNum[uCnt++] = cur;
        // printf("%lld\n", cur);
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (vis[i] || (step == 1 && i == 0))
            continue;
        cur = cur * 10 + i;
        vis[i] = true;
        dfs(step + 1, maxDepth, cur);
        cur /= 10;
        vis[i] = false;
        if (uCnt >= n)
            return;
    }
    return;
}

int main()
{
    scanf("%d", &n);
    for (int s = 1; s <= 10; s++)
    {
        dfs(1, s, 0);
        if (uCnt >= n)
            break;
    }
    printf("%lld\n", uniNum[n - 1]);
    return 0;
}
