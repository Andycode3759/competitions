// AC
// Fixed on 1.9 20:42
#include <bits/stdc++.h>
using namespace std;
#include "moveTo.hpp"

// ===Start the submission from HERE===

// x,y=当前坐标，n=地图大小
string find_out_map(int x, int y, int n)
{
    const int MAXN = 501;
    const int dirDelta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    const char dirs[] = "WASD";
    queue<pair<int, int>> que;
    bool knownMap[MAXN][MAXN];
    // bool book[MAXN][MAXN];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            knownMap[i][j] = true;
        }
    }

    // memset(book, false, sizeof(book));
    knownMap[x][y] = false;

    que.push(make_pair(x, y));
    while (!que.empty())
    {
        pair<int, int> p = que.front();
        int cx = p.first, cy = p.second;
        que.pop();
        // book[cx][cy] = true;

        for (int d = 0; d < 4; d++)
        {
            int nx = cx + dirDelta[d][0], ny = cy + dirDelta[d][1];
            // printf("move %c from (%d,%d): ",dirs[d],cx,cy);
            if (move_to(dirs[d], cx, cy) && knownMap[nx][ny])
            {
                // printf("success\n");
                knownMap[nx][ny] = false;
                que.push(make_pair(nx, ny));
            }
            // else printf("failed\n");
        }
    }
    queue<pair<int, int>>().swap(que);
    string ans = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans.push_back(knownMap[i][j] + '0');
        }
    }
    return ans;
}

// ===End the submisson HERE===

/*
 * bool move_to(char position,int x,int y);
 * position: 为WASD之一，分别表示试图向上，左，下，右
 * （分别为横坐标减一，纵坐标减一，横坐标加一，纵坐标加一）移动，
 * x,y: 为一开始所在位置。
 * 若这个函数返回 1，说明你成功向这个方向移动一格；
 * 否则说明这个方向上有障碍物，移动失败。
 * 假如position不合法，函数返回为0。
 */
