#include <bits/stdc++.h>
using namespace std;
const int MAXN = 103;

const int DX[] = {0, 0, 1, -1}, DY[] = {1, -1, 0, 0};

int n, m, t;
int sx, sy, dx, dy;

struct Node
{
    int x, y;
    int step = 0;

    bool tryGetNext(int dir, Node &next)
    {
        int nx = x + DX[dir], ny = y + DY[dir];
        if (nx < 1 || nx > n || ny < 1 || ny > m)
            return false;
        next.x = nx, next.y = ny;
        next.step = step + 1;
        return true;
    }

    int getWeight(Node goal)
    {
        return abs(x - goal.x) + abs(y - goal.y);
    }

    bool operator==(const Node &a) const
    {
        return x == a.x && y == a.y;
    }
};

Node start, goal;

bool block[MAXN][MAXN];

int ans = 0;

void dfs(int maxStep, Node cur)
{
    if (cur.step > maxStep)
        return;
    if (cur.step == maxStep && cur == goal)
    {
        ans++;
        return;
    }
    if (cur.getWeight(goal) > maxStep - cur.step + 1)
        return;

    for (int d = 0; d < 4; d++)
    {
        Node next;
        if (!cur.tryGetNext(d, next))
            continue;
        if (block[next.x][next.y])
            continue;

        // printf("try: step=%d (%d,%d)\n", next.step, next.x, next.y);

        dfs(maxStep, next);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++)
    {
        char input[MAXN];
        scanf("%s", input + 1);
        for (int j = 1; j <= m; j++)
        {
            block[i][j] = (input[j] == '*') ? true : false;
        }
    }
    scanf("%d%d%d%d", &start.x, &start.y, &goal.x, &goal.y);

    for (int d = 1; d <= t; d++)
    {
        dfs(d, start);
    }

    printf("%d\n", ans);
    return 0;
}
