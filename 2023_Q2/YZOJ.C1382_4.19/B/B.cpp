// AC
// Fixed: 2023/4/22
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1006;
int p[MAXN];
int x;
int n;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        x = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", p + i);
        }
        sort(p + 1, p + n + 1);        // 输入的点坐标不一定有序，记得sort
        for (int i = n; i > 0; i -= 2) // 两两点作为一堆
        {
            x ^= (p[i] - p[i - 1] - 1); // 每一堆的距离求“异或和”（把所有数值用异或运算连接）
        }
        if (x == 0)
        {
            printf("George will win\n");
        }
        else
        {
            printf("Peppa will win\n");
        }
    }
}