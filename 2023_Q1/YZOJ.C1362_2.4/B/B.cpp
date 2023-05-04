// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int arrayA[MAXN];
int arrayB[MAXN];

struct Node
{
    int a, b;

    Node(int _a, int _b)
    {
        a = _a;
        b = _b;
    }

    int getValue()
    {
        return arrayA[a] + arrayB[b];
    }
};
struct NodeCmp
{
    bool operator()(Node a, Node b)
    {
        return a.getValue() > b.getValue();
    }
};
priority_queue<Node, vector<Node>, NodeCmp> nodeq;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arrayA + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arrayB + i);
    }
    nodeq.push(Node(0, 0));
    for (int i = 0; i < n; i++)
    {
        Node t = nodeq.top();
        printf("%d ", t.getValue());
        nodeq.pop();
        // int na = t.a + 1, nb = t.b + 1;
        if (t.a + 1 < n)
        {
            nodeq.push(Node(t.a + 1, t.b));
        }
        if (t.a == 0 && t.b + 1 < n)
        {
            nodeq.push(Node(t.a, t.b + 1));
        }
    }
    printf("\n");
    return 0;
}
