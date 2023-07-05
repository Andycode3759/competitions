#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 2505;
const int MAXM = 10004;
const int INF = (1 << 30) - 1;

int readInt()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}
long long readLL()
{
    long long res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

struct Edge
{
    int a, b;
};
Edge edges[MAXM];
struct Place
{
    int idx;
    long long score;

    const bool operator<(const Place &a) const
    {
        return score > a.score;
    }
};
Place places[MAXN];

int n, m, k;
int graph[MAXN][MAXN];

long long solveSP1() // k=0
{
    for (int id1 = 2; id1 <= n; id1++)
    {
        for (int id2 = id1 + 1; id2 <= n; id2++)
        {
            for (int id3 = id2 + 1; id3 <= n; id3++)
            {
                for (int id4 = id3 + 1; id4 <= n; id4++)
                {
                    int perm[] = {id1, id2, id3, id4};
                    do
                    {
                        int d1 = places[perm[0]].idx, d2 = places[perm[1]].idx, d3 = places[perm[2]].idx,
                            d4 = places[perm[3]].idx;
                        if (graph[1][d1] == 1 && graph[d1][d2] == 1 && graph[d2][d3] == 1 && graph[d3][d4] == 1 &&
                            graph[d4][1] == 1)
                        {
                            return places[perm[0]].score + places[perm[1]].score + places[perm[2]].score +
                                   places[perm[3]].score;
                        }
                    } while (next_permutation(perm, perm + 4));
                }
            }
        }
    }
    return -1;
}
long long solveGeneral()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    for (int id1 = 2; id1 <= n; id1++)
    {
        for (int id2 = id1 + 1; id2 <= n; id2++)
        {
            for (int id3 = id2 + 1; id3 <= n; id3++)
            {
                for (int id4 = id3 + 1; id4 <= n; id4++)
                {
                    int perm[] = {id1, id2, id3, id4};
                    do
                    {
                        int d1 = places[perm[0]].idx, d2 = places[perm[1]].idx, d3 = places[perm[2]].idx,
                            d4 = places[perm[3]].idx;
                        if (graph[1][d1] <= k + 1 && graph[d1][d2] <= k + 1 && graph[d2][d3] <= k + 1 &&
                            graph[d3][d4] <= k + 1 && graph[d4][1] <= k + 1)
                        {
                            return places[perm[0]].score + places[perm[1]].score + places[perm[2]].score +
                                   places[perm[3]].score;
                        }
                    } while (next_permutation(perm, perm + 4));
                }
            }
        }
    }
    return -1;
}

int main()
{
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);

    // scanf("%d%d%d", &n, &m, &k);
    n = readInt();
    m = readInt();
    k = readInt();
    for (int i = 2; i <= n; i++)
    {
        // scanf("%lld", score + i);
        places[i].score = readLL();
        places[i].idx = i;
    }
    sort(places + 2, places + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        // scanf("%d%d", &edges[i].a, &edges[i].b);
        edges[i].a = readInt();
        edges[i].b = readInt();
        graph[edges[i].a][edges[i].b] = 1;
        graph[edges[i].b][edges[i].a] = 1;
    }

    if (k == 0)
        printf("%lld\n", solveSP1());
    else
        printf("%lld\n", solveGeneral());

    return 0;
}
