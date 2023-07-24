#include <algorithm>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;
const ull MOD = 100000000000000000ULL;
const int MAXN = 128;

int n;
ull ans = 0;

struct State
{
    int c[4];
    int rs[MAXN];
    bool isClear()
    {
        for (int i = 1; i <= 3; i++)
        {
            if (c[i] != 0)
                return false;
        }
        for (int i = 1; i <= n; i++)
        {
            if (rs[i] != 0)
                return false;
        }
        return true;
    }
};
State st;

void dfs(int x, int y)
{
    if (y > n)
    {
        if (st.isClear())
        {
            ans++;
            if (ans >= MOD)
                ans -= MOD;
        }
        return;
    }
    if (x == 3)
    {
        if (st.rs[y] > st.c[x])
            return;
        int t = st.rs[y];
        st.rs[y] = 0, st.c[x] -= t;
        dfs(1, y + 1);
        st.rs[y] = t, st.c[x] += t;
        return;
    }
    int maxNum = max(st.c[x], st.rs[y]);
    for (int i = 1; i <= maxNum; i++)
    {
        st.c[x] -= i;
        st.rs[y] -= i;
        dfs(x + 1, y);
        st.c[x] += i;
        st.rs[y] += i;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 3; i++)
    {
        scanf("%d", st.c + i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", st.rs + i);
    }
    dfs(1, 1);
    printf("%llu\n", ans);
    return 0;
}
