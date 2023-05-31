#include <cstdio>
using namespace std;
const int MAXN = 100005;

int n, m;
int arr[MAXN];
int fw[MAXN];

void add(int pos, int x)
{
    while (pos <= n)
    {
        fw[pos] += x;
        pos += (pos & (-pos));
    }
}
long long getSum(int pos)
{
    long long res = 0;
    while (pos > 0)
    {
        res += fw[pos];
        pos -= (pos & (-pos));
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int op, a, b, c;
        scanf("%d", &op);
        if (op == 1)
        {
            printf("%lld\n", getSum(b) - getSum(a - 1));
        }
        else if (op == 2)
        {
            scanf("%d%d%d", &a, &b, &c);
            for (int j = a; j <= b; j++)
            {
                int dlt = (arr[j] ^ c) - arr[j];
                arr[j] += dlt;
                add(j, dlt);
            }
        }
    }
    return 0;
}
