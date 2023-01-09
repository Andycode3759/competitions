#include "A.cpp"
#include "moveTo.hpp"
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
char gameMap[MAXN][MAXN];
const int _dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n;
bool move_to(char position, int x, int y)
{
    int d;
    switch (position)
    {
    case 'W':
        d = 0;
        break;
    case 'A':
        d = 1;
        break;
    case 'S':
        d = 2;
        break;
    case 'D':
        d = 3;
        break;
    default:
        return false;
    }
    int nx = x + _dirs[d][0], ny = y + _dirs[d][1];
    return nx >= 1 && nx <= n && ny >= 1 && ny <= n && gameMap[nx][ny] == '0';
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int sx, sy;
        scanf("%d%d%d", &n, &sx, &sy);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", gameMap[i] + 1);
        }
        printf("%s\n", find_out_map(sx, sy, n).c_str());
    }
    return 0;
}
