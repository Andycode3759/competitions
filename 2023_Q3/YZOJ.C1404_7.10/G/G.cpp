// AC
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 13;
const int MAXS = (1 << 11) + 2;

inline void memset(void *dest, int ch, unsigned int cnt)
{
    char *d = (char *)dest;
    while (cnt--)
        *(d++) = (char)ch;
}

int h, w;
vector<int> okStates[MAXS];
long long ans[MAXN][MAXS];

void dfs(int col, int s1, int s2, int f1, int f2)
{
    if (col >= w)
    {
        if (!f1 && !f2)
            okStates[s1].push_back(s2);
        return;
    }
    dfs(col + 1, (s1 << 1) | f1, ((s2 << 1) | 1) ^ f2, 0, 0);
    if (!f1)
    {
        if (!f2)
        {
            dfs(col + 1, (s1 << 1) | 1, s2 << 1, 0, 0);
            dfs(col + 1, (s1 << 1) | 1, s2 << 1, 1, 0);
            dfs(col + 1, (s1 << 1) | 1, s2 << 1, 0, 1);
        }
        dfs(col + 1, (s1 << 1) | 1, ((s2 << 1) | 1) ^ f2, 1, 0);
        dfs(col + 1, (s1 << 1) | 1, ((s2 << 1) | 1) ^ f2, 1, 1);
    }
    if (!f2)
    {
        dfs(col + 1, (s1 << 1) | f1, s2 << 1, 1, 1);
    }
}

int main()
{
    while (scanf("%d%d", &h, &w) == 2)
    {
        if (h == 0 && w == 0)
            break;
        memset(ans, 0, sizeof ans);
        int maxState = (1 << w) - 1;
        for (int i = 0; i <= maxState; i++)
            okStates[i].clear();
        ans[0][maxState] = 1;
        dfs(0, 0, 0, 0, 0);
        for (int i = 1; i <= h; i++)
        {
            for (int j = 0; j <= maxState; j++)
            {
                for (int k = 0, len = okStates[j].size(); k < len; k++)
                {
                    ans[i][j] += ans[i - 1][okStates[j][k]];
                }
            }
        }
        printf("%lld\n", ans[h][maxState]);
    }
    return 0;
}
