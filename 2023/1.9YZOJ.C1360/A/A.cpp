// Score: 80/100
// TLE
#include <bits/stdc++.h>
using namespace std;
#include "moveTo.hpp"

// ===Start the submission from HERE===

const int MAXN = 501;
const int dirDelta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const char dirs[] = "WASD";
queue<int> quex, quey;
string knownMap;
bool book[MAXN][MAXN];
// x,y=当前坐标，n=地图大小
string find_out_map(int x, int y, int n)
{
    string(n * n, '1').swap(knownMap);
    // for(int i=0;i<n*n;i++) map.append("1");
    // map[(x-1)*n + y-1] => map[x][y]
    // memset(map,'1',sizeof(map));
    memset(book, false, sizeof(book));
    knownMap[(x - 1) * n + y - 1] = '0';
    queue<int>().swap(quex), queue<int>().swap(quey);

    quex.push(x), quey.push(y);
    while (!quex.empty())
    {
        int cx = quex.front(), cy = quey.front();
        quex.pop(), quey.pop();
        book[cx][cy] = true;
        for (int d = 0; d < 4; d++)
        {
            // printf("move %c from (%d,%d): ",dirs[d],cx,cy);
            if (move_to(dirs[d], cx, cy))
            {
                // printf("success\n");
                int nx = cx + dirDelta[d][0], ny = cy + dirDelta[d][1];
                knownMap[(nx - 1) * n + ny - 1] = '0';
                if (!book[nx][ny])
                {
                    quex.push(nx), quey.push(ny);
                }
            }
            // else printf("failed\n");
        }
    }
    return knownMap;
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
