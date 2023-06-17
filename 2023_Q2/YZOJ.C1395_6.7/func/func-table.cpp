#include <cstdio>
#include <map>
#include <queue>
using namespace std;
const int MAXN = 20;

struct Node
{
    Node(int _s, long long _x) : step(_s), x(_x)
    {
    }
    int step;
    long long x;
};
queue<Node> Q;

map<long long, bool> M;

int main()
{
    for (int maxStep = 1; maxStep <= MAXN; maxStep++)
    {
        long long res = 0;
        while (!Q.empty())
            Q.pop();
        M.clear();
        Q.push(Node(0, 1));
        M[1] = true;
        while (!Q.empty())
        {
            Node n = Q.front();
            Q.pop();
            if (n.step == maxStep)
            {
                res++;
                continue;
            }
            long long n1 = n.x - 1, n2 = n.x * 2;
            if (n.x % 2 == 0 && !M[n1] && n1 > 1)
            {
                Q.push(Node(n.step + 1, n1));
                M[n1] = true;
            }
            if (!M[n2] && n2 > 1)
            {
                Q.push(Node(n.step + 1, n2));
                M[n2] = true;
            }
        }
        printf("n=%d ans=%lld\n", maxStep, res);
    }
    return 0;
}
