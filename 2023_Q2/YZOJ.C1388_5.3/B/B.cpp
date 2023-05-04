#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1002;

int a, b;

struct Frac
{
    Frac(int _u, int _d) : u(_u), d(_d)
    {
    }

    int u = 0, d = 0;
    bool operator==(const Frac &f) const
    {
        return u == f.u && d == f.d;
    }
    const Frac operator+(const Frac &f) const
    {
        Frac res(u * f.d + f.u * d, d * f.d);
        int g = __gcd(res.u, res.d);
        res.u /= g;
        res.d /= g;
        return res;
    }
};
struct State
{
    bool mark[MAXN];
    vector<int> nums;

    Frac getRes()
    {
        Frac f(0, 1);
        for (int i = 0; i < nums.size(); i++)
        {
            f = f + Frac(1, nums[i]);
        }
        return f;
    }

    void print()
    {
        for (int i = 0; i < nums.size(); i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
};

Frac goal(0, 0);
State ans;

bool dfs(int step, int maxStep, State s)
{
    if (step > maxStep)
        return false;
    if (s.getRes() == goal && step == maxStep)
    {
        ans = s;
        return true;
    }

    for (int i = 2; i < MAXN; i++)
    {
        if (s.mark[i])
            continue;
        State next;
        next.nums = s.nums;
        next.nums.push_back(i);
        next.mark[i] = true;
        if (dfs(step + 1, maxStep, next))
        {
            ans = next;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &a, &b);
    goal.u = a, goal.d = b;

    State init;
    for (int step = 0;; step++)
    {
        if (dfs(0, step, init))
        {
            break;
        }
    }
    ans.print();
    return 0;
}
