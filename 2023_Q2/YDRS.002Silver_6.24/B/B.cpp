#include <cstdio>
using namespace std;
const int MAXN = 500005;

char str[MAXN];
int n, q;

int solve(int l, int r)
{
    int len = r - l + 1;
    for (int ans = 1; ans <= len; ans++)
    {
        if (len % ans != 0)
            continue;
        int ps = len / ans;
        bool ok = true;
        for (int i = 1; i <= ans; i++)
        {
            char c = 0;
            for (int j = 0; j < ps; j++)
            {
                char dest = str[l + i + j * ans - 1];
                if (c == 0 || dest == c)
                {
                    c = dest;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            return ans;
    }
    return len;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str + 1);
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", solve(l, r));
    }
    return 0;
}
