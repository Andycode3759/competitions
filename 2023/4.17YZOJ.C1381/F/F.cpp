#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;
const int MAXN = 67;

int n;
int sticks[MAXN];
bool mark[MAXN];

bool combine(int org) // issue
{
    // printf("org=%d:\n", org);
    memset(mark, false, sizeof(mark));

    int sum = 0, cnt = 0;
    while (cnt < n)
    {
        bool flag = false;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mark[i] || sum + sticks[i] > org)
                continue;

            // printf("chosen %d\n", sticks[i]);

            mark[i] = true;
            sum += sticks[i];
            cnt++;
            if (sum == org)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}

int main()
{
    while (scanf("%d", &n) == 1 && n != 0)
    {
        // memset(sticks, 0, sizeof(sticks));
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", sticks + i);
            sum += sticks[i];
        }
        sort(sticks, sticks + n, greater<int>());
        int ans = sum;
        for (int i = 1; i <= (sum >> 1); i++)
        {
            if (sum % i != 0)
                continue;
            if (combine(i))
            {
                ans = i;
                break;
            }
            // printf("false\n");
        }
        printf("%d\n", ans);
    }
    return 0;
}
