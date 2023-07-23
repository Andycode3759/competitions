#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 303;
const int MAXM = 2000006;

struct Operation
{
    Operation(int _t = 0, int _a = 0, int _b = 0) : t(_t), a(_a), b(_b)
    {
    }
    int t, a, b;
};
Operation ops[MAXM];
int cnt;

int n, m, k;
int pile[MAXM], head;
deque<int> S[MAXN], S2[MAXN];

inline void finalOutput()
{
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
    {
        Operation o = ops[i];
        if (o.t == 1)
            printf("1 %d\n", o.a);
        else if (o.t == 2)
            printf("2 %d %d\n", o.a, o.b);
    }
}
inline void opPut(int stackId)
{
    deque<int> &target = S[stackId];
    int cur = pile[head];
    if (!target.empty() && target.back() == cur)
    {
        target.pop_back();
    }
    else
    {
        target.push_back(cur);
    }
    head++;
    ops[++cnt] = (Operation(1, stackId, 0));
}
inline void opMatch(int stack1, int stack2)
{
    deque<int> &s1 = S[stack1], &s2 = S[stack2];
    if (!s1.empty() && !s2.empty() && s1.front() == s2.front())
    {
        s1.pop_front();
        s2.pop_front();
    }
    ops[++cnt] = (Operation(2, stack1, stack2));
}

inline void solve1() // k=2n-2
{
    cnt = 0;
    while (head <= m)
    {
        int cur = pile[head];
        int t = (cur + 1) >> 1;
        if (!S[t].empty() && S[t].front() == cur)
        {
            opPut(n);
            opMatch(t, n);
        }
        else
        {
            opPut(t);
        }
    }
}
bool allEmpty()
{
    for (int i = 1; i <= n; i++)
    {
        if (!S2[i].empty())
            return false;
    }
    return true;
}
bool dfs(int step)
{
    if (step >= m + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            S2[i] = S[i];
        }
        while (!allEmpty())
        {
            cnt = m;
            bool flag = false;
            for (int l = 1; l <= n; l++)
            {
                for (int r = l + 1; r <= n; r++)
                {
                    // printf("l=%d r=%d\n", l, r);
                    if (!S2[l].empty() && !S2[r].empty() && S2[l].front() == S2[r].front())
                    {
                        S2[l].pop_front();
                        S2[r].pop_front();
                        ops[++cnt] = Operation(2, l, r);
                        flag = true;
                    }
                }
            }
            if (!flag)
            {
                cnt = m;
                return false;
            }
        }
        return true;
    }
    for (int d = 1; d <= n; d++)
    {
        // printf("put %d: \n", d);
        bool clear = !S[d].empty() && S[d].back() == pile[step];
        int cur = pile[step];
        if (clear)
            S[d].pop_back();
        else
            S[d].push_back(cur);
        ops[step] = Operation(1, d, 0);
        if (dfs(step + 1))
        {
            // ops.pop_back();
            return true;
        }
        // printf("failed\n");
        if (clear)
            S[d].push_back(cur);
        else
            S[d].pop_back();
    }
    return false;
}
inline void solve2() // k=2n-1
{
    dfs(1);
}

int main()
{
    freopen("meow.in", "r", stdin);
    freopen("meow.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);

        head = 1;
        for (int i = 1; i <= n; i++)
            S[i].clear();

        for (int i = 1; i <= m; i++)
            scanf("%d", pile + i);

        if (k == 2 * n - 2)
            solve1();
        else
            solve2();
        finalOutput();
    }

    return 0;
}
