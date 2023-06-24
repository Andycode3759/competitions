// AC
#include <cstdio>
using namespace std;
const int MAXN = 20;

int n, m;
int row[1 << MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    int x = 0;
    int dir = 1;
    for (int num = 0; num < (1 << (n + m)); num++)
    {
        row[x] = (num ^ (num << 1)) >> 1;
        x += dir;
        if (x >= (1 << m) || x < 0)
        {
            x -= dir, dir *= -1;
            for (int i = 0; i < (1 << m); i++)
            {
                printf("%d ", row[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
