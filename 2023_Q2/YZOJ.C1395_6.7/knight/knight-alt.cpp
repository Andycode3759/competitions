#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1000006;
const long long INF = (1LL << 62) - 1;

struct Point
{
    int x, y;
};
Point points[MAXN];

int cost[MAXN];
int perm[MAXN];
int dist[MAXN], distCp[MAXN];
int n, k;
int maxX[MAXN], maxY[MAXN];
long long sum;

long long solveSPA()
{
    return 2LL * (maxX[0] + maxY[0]);
}
long long solveSPB()
{
    return 2 * sum;
}
long long solveSPC()
{
    for (int i = 2; i <= n; i++)
    {
        cost[i] = points[i - 1].x + points[i].y;
    }
    sort(cost + 2, cost + n + 1);
    long long res = points[1].y + points[n].x;
    for (int i = 1; i < k; i++)
    {
        res += cost[i + 1];
    }
    return 2LL * res;
}
long long solveSub()
{
    // printf("dist: ");
    for (int i = 1; i <= k; i++)
    {
        distCp[i] = dist[i];
        maxX[i] = 0, maxY[i] = 0;
        // printf("%d ", dist[i]);
    }
    // printf("\n");
    int ck = 1;
    for (int i = 1; i <= n; i++)
    {
        maxX[ck] = max(maxX[ck], points[perm[i]].x);
        maxY[ck] = max(maxY[ck], points[perm[i]].y);
        distCp[ck]--;
        if (distCp[ck] == 0)
            ck++;
    }
    long long res = 0;
    for (int i = 1; i <= k; i++)
    {
        res += 2LL * (maxX[i] + maxY[i]);
    }
    // printf("res: %lld\n", res);
    return res;
}
void dfs(int left, int curK, long long &res)
{
    if (curK > k)
    {
        if (left == 0)
        {
            res = min(res, solveSub());
        }
        return;
    }
    else if (left <= 0)
        return;
    for (int i = 1; i <= left; i++)
    {
        dist[curK] = i;
        dfs(left - i, curK + 1, res);
    }
}
long long solveGeneral()
{
    for (int i = 1; i <= n; i++)
    {
        perm[i] = i;
    }
    long long res = INF;
    do
    {
        // printf("perm: ");
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d ", perm[i]);
        // }
        // printf("\n");
        dfs(n, 1, res);
        // printf("\n");
    } while (next_permutation(perm + 1, perm + 1 + n));
    return res;
}

int main()
{
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &points[i].x, &points[i].y);
        maxX[0] = max(maxX[0], points[i].x);
        maxY[0] = max(maxY[0], points[i].y);
        sum += points[i].x + points[i].y;
    }

    if (k == 1)
        printf("%lld\n", solveSPA());
    else if (n == k)
        printf("%lld\n", solveSPB());
    else if (n <= 12)
        printf("%lld\n", solveGeneral());
    else
        printf("%lld\n", solveSPC());

    return 0;
}
