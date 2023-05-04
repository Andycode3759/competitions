#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int weight[MAXN];
int n;

struct Edge
{
    int dest, next;

    Edge(int _d, int _n) : dest(_d), next(_n)
    {
    }
};
vector<Edge> edges;
int fir[MAXN];

void addEdge(int from, int to)
{
    edges.push_back(Edge(to, fir[from]));
    fir[from] = edges.size() - 1;
}

int col[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", weight + i);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int f, t;
        scanf("%d%d", &f, &t);
        addEdge(f, t);
    }
    // 枚举所有路径，求异或和
    // 若为0就染色并计数sum
    // 答案为???
    return 0;
}
