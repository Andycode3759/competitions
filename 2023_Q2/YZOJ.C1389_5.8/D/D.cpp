#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 100005;

struct Fenwick
{
    Fenwick(int _s = 0) : size(_s)
    {
    }

    int data[MAXN];
    int size;

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

    void clear()
    {
        memset(data, 0, sizeof(data));
    }
};
struct Node
{
    Node(int _p, int _x, int _t)
    {
        pos = _p;
        x = _x;
        time = _t;
    }

    int pos, x, time;
};

int n, m;
int nums[MAXN];
int org[MAXN];
Fenwick fw(MAXN);
vector<Node> nodes;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", nums + i);
        nodes.push_back(Node(i, nums[i], 0));
    }
    for (int i = n; i > 0; i--)
    {
        org[nums[i]] += fw.getSum(nums[i]);
        fw.add(nums[i], 1);
    }
    fw.clear();

    // printf("     org\n");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%4d%4d\n", i, org[i]);
    // }

    int tt = n;
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
    }
    return 0;
}
