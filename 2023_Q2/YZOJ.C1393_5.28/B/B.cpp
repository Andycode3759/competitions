// AC
// Fixed: 2023.5.29
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200006;

struct Task
{
    int comp, exec;
    const bool operator<(const Task &t) const
    {
        return min(t.exec, comp) < min(exec, t.comp);
    }
};

Task tasks[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &tasks[i].comp, &tasks[i].exec);
    }
    sort(tasks + 1, tasks + n + 1);
    // long long tTime = 0;
    long long ct = 0, et = 0;
    for (int i = 1; i <= n; i++)
    {
        Task &t = tasks[i];
        ct += t.comp;
        et = max(ct, et) + t.exec;
    }
    printf("%lld\n", et);
    return 0;
}
