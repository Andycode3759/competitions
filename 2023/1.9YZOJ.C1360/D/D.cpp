// Score: 20/100
// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;

struct Point
{
    int x, y;

    int distanceTo(Point another)
    {
        return abs(x - another.x) + abs(y - another.y);
    }

} points[MAXN];

priority_queue<int, vector<int>, greater<int>> dis[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = points[i].distanceTo(points[j]);
            dis[i].push(d);
            dis[j].push(d);
        }
    }
    int maxDis = -1;
    for (int i = 0; i < n; i++)
    {

        maxDis = max(maxDis, dis[i].top());
    }
    printf("%d\n", (maxDis - 1) / 2 + 1);
    return 0;
}
