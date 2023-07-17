#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 303;
const int MAXM = 2000006;

struct Operation
{
    int t, a, b;
};
deque<Operation> ops;

inline void finalOutput()
{
    int len = ops.size();
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
    {
        Operation o = ops[i];
        if (o.t == 1)
            printf("1 %d\n", o.a);
        else if (o.t == 2)
            printf("2 %d %d\n", o.a, o.b);
    }
}

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
    Operation o;
    o.t = 1, o.a = stackId;
    ops.push_back(o);
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
    Operation o;
    o.t = 2, o.a = stack1, o.b = stack2;
    ops.push_back(o);
}

inline void solveSP1() // n==2, k==3
{
    int goodCard = pile[m];
    for (int i = m - 1; i >= 1; i--)
    {
        if (pile[i] != goodCard)
        {
            goodCard = pile[i];
            break;
        }
    }
    int cntGood = 0;
    for (int i = 1; i <= m; i++)
        if (pile[i] == goodCard)
            cntGood++;
    // printf("[DEBUG] goodCard=%d cntGood=%d\n", goodCard, cntGood);

    while (head <= m)
    {
        int cur = pile[head];
        // printf("[DEBUG] head=%d cur=%d\n", head, cur);
        if (cur == goodCard)
            opPut(1), cntGood--;
        else
        {
            if (cntGood == 0)
            {
                if (!S[2].empty() && S[2].front() == cur)
                {
                    opPut(1);
                    opMatch(1, 2);
                }
                else
                {
                    opPut(2);
                }
            }
            else
            {
                opPut(2);
            }
        }
    }
}
inline void solveSP2() // n==3, k==5
{
    // int goodCard = pile[m];
    // for (int i = m - 1; i >= 1; i--)
    // {
    //     if (pile[i] != goodCard)
    //     {
    //         goodCard = pile[i];
    //         break;
    //     }
    // }
    // int cntGood = 0;
    // for (int i = 1; i <= m; i++)
    //     if (pile[i] == goodCard)
    //         cntGood++;
}
inline void solveGeneral()
{
    // TODO: Write your code here
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
        ops.clear();
        for (int i = 1; i <= n; i++)
            S[i].clear();
        for (int i = 1; i <= m; i++)
            scanf("%d", pile + i);

        if (n == 2)
            solveSP1();
        else if (n == 3)
            solveSP2();
        else
            solveGeneral();
        finalOutput();
    }

    return 0;
}
