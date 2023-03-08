// Fixed on 2023.1.2
// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char str[MAXN], ans[MAXN];
bool covered[MAXN];

void plant(char feed, int pos, int k, int n)
{
    while (ans[pos] != '.') // 已经种了草，那就向后移动
    {
        pos++;
    }
    ans[pos] = feed;
    int lb = max(1, pos - k), rb = min(n - 1, pos + k);
    for (int i = lb; i <= rb; i++)
    {
        if (str[i] == feed)
        {
            covered[i] = true;
        }
    }
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, k;
        scanf("%d%d%s", &n, &k, str);
        memset(ans, '.', n);
        memset(covered, 0, sizeof(covered));
        ans[n] = '\0'; // 手动设置字符串结尾，不然输出有问题
        int feedCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (!covered[i])
            {
                plant(str[i], i + k >= n - 1 ? i : i + k, k, n);
                // 如果越界那就种在i的位置
                feedCount++;
            }
        }
        printf("%d\n%s\n", feedCount, ans);
    }
    return 0;
}
