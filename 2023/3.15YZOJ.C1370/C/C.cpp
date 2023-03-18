// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 29;

vector<int> outEdges[MAXN];
int n, m;

int mark[MAXN];
vector<char> seq;
bool dfs(int u)
{
    mark[u] = -1;
    for (int i = 1; i <= n; i++)
    {
        if ((mark[i] == -1) || (mark[i] == 0 && !dfs(i)))
            return false;
    }
    mark[u] = 1;
    seq.push_back(u - 1 + 'A');
    return true;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2 && n != 0 && m != 0)
    {
        char str[4];
        for (int i = 1; i <= m; i++)
        {
            scanf("%s", str);
            char a = str[0], b = str[2];
            outEdges[a - 'A' + 1].push_back(b - 'A' + 1);
        }
    }

    return 0;
}
