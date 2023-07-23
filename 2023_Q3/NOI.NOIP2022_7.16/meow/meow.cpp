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

inline void finalOutput() // 最后输出答案
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
int id[MAXN * 2], id2[MAXN * 2]; // 表示某种牌所在的栈编号，0表示没有出现。
// 本解法能够保证某个牌在所有栈中最多同时出现1次，且所有栈的元素个数不超过2。

inline void copyId()
{
    for (int i = 1; i <= k; i++)
    {
        id2[i] = id[i];
    }
}

// 两个函数模拟栈状态并记录操作
inline void opPut(int stackId)
{
    deque<int> &target = S[stackId];
    int cur = pile[head];
    if (!target.empty() && target.back() == cur)
    {
        id[target.back()] = 0;
        target.pop_back();
    }
    else
    {
        id[cur] = stackId;
        target.push_back(cur);
    }
    head++;
    Operation o;
    o.t = 1, o.a = stackId;
    ops.push_back(o);
}
inline void opMatch(int stack1, int stack2)
{
    deque<int> &s1 = S[stack1], &s2 = S[stack2];
    if (!s1.empty() && !s2.empty() && s1.front() == s2.front())
    {
        id[s1.front()] = 0, id[s2.front()] = 0;
        s1.pop_front();
        s2.pop_front();
    }
    Operation o;
    o.t = 2, o.a = stack1, o.b = stack2;
    ops.push_back(o);
}

inline void solve1() // k=2n-2
{
    // 把 1~n-1 号栈分别和 1+2, 3+4, ..., 2n-3+2n-2 号牌对应起来
    while (head <= m)
    {
        int cur = pile[head];
        int t = (cur + 1) >> 1;
        if (!S[t].empty() && S[t].front() == cur) // 对应牌在栈底就借助中转栈消掉
        {
            opPut(n);
            opMatch(t, n);
        }
        else // 在栈顶/对应栈为空就直接放
        {
            opPut(t);
        }
    }
}

queue<int> magicQ; // 魔法队列，满足这样一个性质：
                   // 对于非中转栈，记其元素个数为a，它的编号在魔法队列里出现的次数为2-a；
                   // 对于中转栈，它的编号一定不会出现在魔法队列里。
int spStack; // 中转栈编号，一般情况下需要保证它是空的
int cnt[MAXN];
inline void clearCnt()
{
    for (int i = 1; i <= k; i++)
        cnt[i] = 0;
}
inline void solve2() // k=2n-1
{
    spStack = n;
    queue<int>().swap(magicQ);
    for (int i = 1; i <= n - 1; i++) // 魔法队列的默认状态
    {
        magicQ.push(i);
        magicQ.push(i);
    }
    while (head <= m)
    {
        int cur = pile[head];
        if (id[cur] == 0) // 这张牌没有出现过
        {
            if (magicQ.empty()) // 魔法队列为空，说明所有的非中转栈已经“饱和”，那么当前这张牌就是“多余的牌”（记作p）
            {
                clearCnt();
                // 从p后面出发，找到一段区间，使得区间内的所有牌都有同种牌在栈顶
                int p = cur;
                int ptr = head + 1;
                for (; ptr <= m; ptr++)
                {
                    int pos = id[pile[ptr]];
                    if (pos == 0 || S[pos].back() != pile[ptr])
                        break;
                    cnt[pile[ptr]]++;
                }
                // 把区间后面的第一张牌记作g
                int g = pile[ptr];
                if (g == p)
                {
                    // 如果g和p相同，两者可以都放进中转栈里消掉，区间内的牌都直接丢进对应的栈即可
                    // 因为每次调用op操作都会影响id，所以需要复制一份
                    copyId();
                    for (int i = 1; i <= k; i++) // 维护魔法队列
                    {
                        if (cnt[i] % 2 == 1)
                        {
                            magicQ.push(id2[i]);
                        }
                    }
                    opPut(spStack);
                    for (int i = head; i < ptr; i++)
                        opPut(id2[pile[i]]);
                    opPut(spStack);
                    continue;
                }
                else // 否则g是前面n-1个栈中某个栈的栈底的同种牌
                {
                    // 方便起见记g所在的栈为pos，pos的栈顶为h
                    int pos = id[g];
                    int h = S[pos].back();
                    if (cnt[h] % 2 == 1) // 如果h在区间中出现了奇数次，那就把p放入中转栈，区间中间的牌丢进对应栈
                    {
                        copyId();
                        opPut(spStack);
                        for (int i = head; i < ptr; i++)
                            opPut(id2[pile[i]]);
                        // 这时h一定全都消完了，pos的栈顶变成原栈底g，这样就可以把当前的g放进pos里消掉了
                        // pos就会变成新的中转栈
                        opPut(pos);
                        for (int i = 1; i <= k; i++) // 维护魔法队列
                        {
                            if (cnt[i] % 2 == 1)
                            {
                                magicQ.push(id2[i]);
                            }
                        }
                        // TODO: 维护魔法队列
                        spStack = pos;
                        continue;
                    }
                    else // 如果h在区间中出现了偶数次，那就把p放入pos，所有的h放进中转栈里消掉，剩下的放进对应栈
                    {
                        copyId();
                        opPut(pos);
                        for (int i = head; i < ptr; i++)
                        {
                            if (pile[i] == h)
                                opPut(spStack);
                            else
                                opPut(id2[pile[i]]);
                        }
                        // TODO: 维护魔法队列
                        // 此时原来的中转栈依然为空，pos的栈底还是g，那就借助中转栈把最后的g消掉
                        opPut(spStack);
                        opMatch(spStack, pos);
                        continue;
                    }
                }
            }
            else // 非中转栈中有空余位置，直接放即可
            {
                opPut(magicQ.front());
                magicQ.pop();
            }
        }
        else // 这张牌已经出现过，用和k=2n-2相同的方法消掉
        {
            int x = id[cur];
            if (S[x].front() == cur)
            {
                opPut(spStack);
                opMatch(spStack, x);
            }
            else
            {
                opPut(x);
            }
            magicQ.push(x);
        }
    }
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
        for (int i = 1; i <= k; i++)
            id[i] = 0;

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
