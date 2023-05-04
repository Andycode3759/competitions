// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20004;
int father[MAXN];

int find(int p)
{
    if (father[p] == p)
        return p;
    else
        return father[p] = find(father[p]);
}

void merge(int x, int y)
{
    int fatherOfX = find(x), fatherOfY = find(y);
    father[fatherOfX] = fatherOfY;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf(find(a) == find(b) ? "Yes\n" : "No\n");
    }

    return 0;
}
