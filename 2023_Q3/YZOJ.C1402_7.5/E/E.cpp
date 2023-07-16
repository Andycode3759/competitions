// AC
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 16006;
const int INF = (1 << 30) - 1;

int n;
int val[MAXN], ans[MAXN];
vector<int> outs1[MAXN], outs2[MAXN];

bool vis[MAXN];
inline void convert(int root)
{
    vis[root] = true;
    int len = outs1[root].size();
    for (int i = 0; i < len; i++)
    {
        int v = outs1[root][i];
        if (vis[v])
            continue;
        outs2[root].push_back(v);
        // printf("%d -> %d\n", root, v);
        convert(v);
    }
}
inline int getAns(int root)
{
    if (vis[root])
        return ans[root];
    vis[root] = true;
    int childSum = 0;
    int len = outs2[root].size();
    for (int i = 0; i < len; i++)
    {
        int v = outs2[root][i];
        childSum += max(0, getAns(v));
    }
    return ans[root] = max(0, val[root] + childSum);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", val + i);
    int u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        outs1[u].push_back(v);
        outs1[v].push_back(u);
    }

    convert(1);
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    getAns(1);

    int res = -INF;
    for (int i = 1; i <= n; i++)
        res = max(res, ans[i]);
    printf("%d\n", res);
    return 0;
}
