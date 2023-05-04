// AC
// Fixed: 2023/4/30
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100006;

int n, m, k;

vector<int> dest[MAXN];

bool mark[MAXN];
bool vis[MAXN];

int main()
{
    freopen("catch.in", "r", stdin);
    freopen("catch.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%*d"); // 直接忽略点权
    }
    for (int i = 0; i < m; i++)
    {
        int f, t;
        scanf("%d%d", &f, &t);
        if ((f == 1 && t == n) || (f == n && t == 1))
        {
            if (k == 1 && n == 2)
            {
                printf("impossible\n");
                return 0;
            }
            if (k >= 2)
            {
                for (int i = 1; i <= k - 1; i++)
                    printf("U");
                for (int i = 1; i <= n - k; i++)
                    printf("P");
                printf("U");
            }
            else
            {
                for (int i = 1; i <= n - k - 1; i++)
                    printf("P");
                for (int i = 1; i <= k; i++)
                    printf("U");
                printf("P");
            }
            printf("\n");
            return 0;
        }
        dest[f].push_back(t);
        dest[t].push_back(f);
    }

    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (vis[u])
            continue;
        if (k == 0)
            break;

        vis[u] = true;
        mark[u] = true;
        k--;

        vector<int> &d = dest[u];
        for (int i = 0; i < d.size(); i++)
        {
            Q.push(d[i]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%c", mark[i] ? 'U' : 'P');
    }
    printf("\n");
    return 0;
}
