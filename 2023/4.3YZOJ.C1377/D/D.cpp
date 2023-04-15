// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int n, q;
vector<int> child[MAXN];

vector<int> dfsOrder;
int mp[MAXN];
void dfs(int x)
{
    dfsOrder.push_back(x);
    vector<int> &c = child[x];
    for (int i = 0; i < c.size(); i++)
    {
        dfs(c[i]);
    }
}

int subSize[MAXN];
int dfsCnt(int x)
{
    vector<int> &c = child[x];
    int cnt = 1;
    for (int i = 0; i < c.size(); i++)
    {
        cnt += dfsCnt(c[i]);
    }
    return subSize[x] = cnt;
}

int query(int u, int k)
{
    int idx = mp[u];
    if (idx + k - 1 >= n)
        return -1;
    return k > subSize[u] ? -1 : dfsOrder[idx + k - 1];
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++)
    {
        int fa;
        scanf("%d", &fa);
        child[fa].push_back(i);
    }
    dfs(1);
    dfsCnt(1);
    for (int i = 0; i < dfsOrder.size(); i++)
    {
        mp[dfsOrder[i]] = i;
    }
    // printf("%6s%6s\n", "i", "mp[i]");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%6d%6d\n", i, mp[i]);
    // }
    // printf("\n");
    while (q--)
    {
        int u, k;
        scanf("%d%d", &u, &k);
        printf("%d\n", query(u, k));
    }
    return 0;
}
