// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 23;
const int MAXFTR = 81;
int side;
int gameMap[MAXSIZE][MAXSIZE];
bool mark[MAXSIZE][MAXSIZE];
const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Remain
{
    Remain()
    {
        for (int i = 0; i < MAXFTR; i++)
        {
            countOfFtr[i] = 0;
        }
    }

    int countOfFtr[MAXFTR + 3];
};

int getFeature(char c[]) // 把拼图样式看作三进制数，再编码为十进制数
{
    int f = 0;
    for (int i = 3; i >= 0; i--)
    {
        f = f * 3 + c[i] - '0';
    }
    return f;
}

int getCost(int feature)
{
    int cost = 10;
    for (int i = 0; i < 3; i++)
    {
        int s = feature % 3;
        feature /= 3;
        if (s == 1)
            cost -= 1;
        else if (s == 2)
            cost += 1;
    }
    return cost;
}

bool matches(int ftrA, int ftrB, int dir)
{
    if (ftrB < 0)
        return true;
    int thisside, otherside;
    switch (dir)
    {
    case 0: // Up
        thisside = ftrA / 27;
        otherside = ftrB / 3 % 3;
        break;
    case 1: // Right
        thisside = ftrA / 9 % 3;
        otherside = ftrB % 3;
        break;
    case 2: // Down
        thisside = ftrA / 3 % 3;
        otherside = ftrB / 27;
        break;
    case 3: // Left
        thisside = ftrA % 3;
        otherside = ftrB / 9 % 3;
        break;
    }
    return (thisside + otherside) % 3 == 0;
}

void dfs(int x, int y, Remain r, int &ans)
{
    bool done = true;
    for (int i = 0; i < MAXFTR; i++)
    {
        if (r.countOfFtr[i] != 0)
        {
            done = false;
            break;
        }
    }
    if (done)
    {
        int matchFtr = 0;

        for (int i = 0; i < 4; i++)
        {
            int cx = x + dirs[i][0], cy = y + dirs[i][1];
            if (cx <= 0 || cy <= 0 || cx > side || cy > side)
            {
                continue;
            }
            int otherside = 0;
            switch (i)
            {
            case 0: // Up
                otherside = gameMap[cx][cy] / 3 % 3;
                break;
            case 1: // Right
                otherside = gameMap[cx][cy] % 3;
                break;
            case 2: // Down
                otherside = gameMap[cx][cy] / 27;
                break;
            case 3: // Left
                otherside = gameMap[cx][cy] / 9 % 3;
                break;
            }
            matchFtr = matchFtr * 3 + (3 - otherside) % 3;
        }

        printf("missing jigsaw: %d\n", matchFtr);

        ans = getCost(matchFtr);
        return;
    }

    for (int f = 0; f < MAXFTR; f++)
    {
        if (r.countOfFtr[f] == 0)
            continue;
        gameMap[x][y] = f;
        mark[x][y] = true;
        r.countOfFtr[f]--;
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dirs[i][0], cy = y + dirs[i][1];
            if (cx > side || cx <= 0 || cy > side || cy <= 0 || mark[cx][cy] || !matches(f, gameMap[cx][cy], i))
            {
                continue;
            }
            dfs(cx, cy, r, ans);
        }
        mark[x][y] = false;
        r.countOfFtr[f]++;
    }
}

int main()
{
    int K;
    scanf("%d", &K);
    while (K--)
    {
        Remain r;
        memset(gameMap, -1, sizeof(gameMap));
        memset(mark, false, sizeof(mark));

        scanf("%d", &side);
        for (int i = 0; i < side * side - 1; i++)
        {
            char c[6];
            scanf("%s", c);
            r.countOfFtr[getFeature(c)]++;
        }
        int ans;
        dfs(1, 1, r, ans);
        printf("%d\n", ans);
    }
    return 0;
}