#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
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
    int maxNum = 1;
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
struct StateCmp
{
    bool operator()(State a, State b)
    {
        return a.nums[0] > b.nums[0];
    }
};

Frac goal(0, 0);
vector<State> ans;

bool dfs(int step, int maxStep, State s)
{
    if (step > maxStep)
        return false;
    if (s.getRes() == goal && step == maxStep)
    {
        ans.push_back(s);
        return true;
    }

    bool flag = false;
    for (int i = s.maxNum + 1; i < MAXN; i++)
    {
        State next = s;
        next.nums.push_back(i);
        next.maxNum = i;

        if (dfs(step + 1, maxStep, next))
            flag = true;
        // if (dfs(step + 1, maxStep, next))
        // {
        //     // ans = next;
        //     return true;
        // }
    }
    return flag;
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

    sort(ans.begin(), ans.end(), StateCmp());
    ans[0].print();

    return 0;
}
