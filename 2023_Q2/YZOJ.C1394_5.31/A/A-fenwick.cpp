// AC
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;

struct Fenwick
{
    int size;
    int *data;

    void init(int _s)
    {
        size = _s;
        data = new int[size + 4];
        memset(data, 0, sizeof(int) * (size + 4));
    }

    void add(int pos, int dlt)
    {
        while (pos <= size)
        {
            data[pos] += dlt;
            pos += (pos & (-pos));
        }
    }
    int getSum(int pos)
    {
        int res = 0;
        while (pos > 0)
        {
            res += data[pos];
            pos -= (pos & (-pos));
        }
        return res;
    }

    void free()
    {
        delete data;
        size = 0;
    }
};

Fenwick fw;
int arr[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    fw.init(MAXN);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    long long ans = 0;
    for (int i = n; i >= 1; i--)
    {
        fw.add(arr[i], 1);
        ans += fw.getSum(arr[i] - 1);
    }
    printf("%lld\n", ans);
    fw.free();
    return 0;
}
