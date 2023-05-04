// AC
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 100005;

int n, k;
bool mark[MAXN];

struct Node
{
    Node(int _n, int _s = 0) : n(_n), step(_s)
    {
    }

    int n;
    int step;
};

int main()
{
    scanf("%d%d", &n, &k);
    queue<Node> Q;
    Q.push(Node(n));
    int ans = -1;
    while (!Q.empty())
    {
        Node cur = Q.front();
        Q.pop();
        if (cur.n < 0 || cur.n > 100000 || mark[cur.n])
            continue;
        mark[cur.n] = true;

        if (cur.n == k)
        {
            ans = cur.step;
            break;
        }

        if (cur.n < k)
            Q.push(Node(cur.n + 1, cur.step + 1));
        if (cur.n < k)
            Q.push(Node(cur.n * 2, cur.step + 1));
        Q.push(Node(cur.n - 1, cur.step + 1));
    }
    printf("%d\n", ans);
    return 0;
}
