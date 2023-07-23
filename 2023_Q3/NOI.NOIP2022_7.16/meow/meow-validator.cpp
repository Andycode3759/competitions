#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 303;
const int MAXM = 2000006;

int n, m, k;
int pile[MAXM], head;
deque<int> S[MAXN];

inline void opPut(int stackId)
{
    // printf("[DEBUG] opPut %d: ", stackId);

    deque<int> &target = S[stackId];
    int cur = pile[head];
    if (!target.empty() && target.back() == cur)
    {
        target.pop_back();
        // printf("success\n");
    }
    else
    {
        target.push_back(cur);
        // printf("failed\n");
    }
    head++;
}
inline void opMatch(int stack1, int stack2)
{
    // printf("[DEBUG] opMatch %d %d: ", stack1, stack2);

    deque<int> &s1 = S[stack1], &s2 = S[stack2];
    if (!s1.empty() && !s2.empty() && s1.front() == s2.front())
    {
        s1.pop_front();
        s2.pop_front();
        // printf("success\n");
    }
    else
    {
        // printf("failed\n");
    }
}

int main()
{
    FILE *input = fopen("meow.in", "r");
    FILE *output = fopen("meow.out", "r");

    int T;
    fscanf(input, "%d", &T);
    for (int Kase = 1; Kase <= T; Kase++)
    {
        fscanf(input, "%d%d%d", &n, &m, &k);
        head = 1;
        for (int i = 1; i <= n; i++)
            S[i].clear();
        for (int i = 1; i <= m; i++)
            fscanf(input, "%d", pile + i);

        int op;
        fscanf(output, "%d", &op);
        for (int i = 1; i <= op; i++)
        {
            int t, a, b;
            fscanf(output, "%d", &t);
            if (t == 1)
            {
                fscanf(output, "%d", &a);
                opPut(a);
            }
            else
            {
                fscanf(output, "%d%d", &a, &b);
                opMatch(a, b);
            }
        }
        if (op < m)
        {
            printf("Case %d: FAILED (too few operations: Got %d, at least %d)\n", Kase, op, m);
            continue;
        }
        if (op > 2 * m)
        {
            printf("Case %d: FAILED (too many operations: Got %d, at most %d)\n", Kase, op, 2 * m);
            continue;
        }
        if (head <= m)
        {
            printf("Case %d: FAILED (%d card(s) remain in pile)\n", Kase, m - head + 1);
            continue;
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (!S[i].empty())
            {
                printf("Case %d: FAILED (stack %d is not empty)\n", Kase, i);
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("Case %d: Passed\n", Kase);
        }
    }
}
