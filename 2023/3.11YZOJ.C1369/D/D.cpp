// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const int INF = (1 << 30);

struct VertexCmp
{
    bool operator()(int a, int b)
    {
        return dis[a] > dis[b];
    }
};
priority_queue<int, vector<int>, VertexCmp> vertexies;

vector<int> destFrom[MAXN];

int weight[MAXN];
int dis[MAXN];

int main()
{
    int n, m, k;
    bool direct = false;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", weight + i);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        if ((a == 1 && b == n) || (a == n && b == 1))
        {
            direct = true;
            // 防止输入没读完卡出奇奇怪怪的问题，特殊情况打标记判断
        }
        scanf("%d%d", &a, &b);
        destFrom[a].push_back(b);
        destFrom[b].push_back(a);
    }
    if (direct)
    {
        printf((n == 2 && k == 1) ? "impossible\n" : "UP\n");
        return 0;
    }

    // Dijkstra
    dis[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dis[i] = INF;
    }
    for (int i = 0; i < destFrom[1].size(); i++)
    {
        int &connected = destFrom[1][i];
        dis[connected] = weight[connected];
    }
    for (int i = 2; i <= n; i++)
    {
        vertexies.push(i);
    }
    while (!vertexies.empty())
    {
        int v = vertexies.top();
        vector<int> &outEdges = destFrom[v];
        for (int j = 0; j < outEdges.size(); j++)
        {
            int &dest = outEdges[j];
            dis[dest] = min(dis[dest], dis[v] + weight[dest]);
        }
        vertexies.pop();
    }

    // TODO: 找出点11到nn的所有最短路中包含的所有边

    // TODO: 拓扑排序

    // TODO: 输出方案+判断存在有长度大于等于3的最短路

    return 0;
}
