// AC
#include <bits/stdc++.h>
using namespace std;
const int MAX_STEP = 15;
const int BLANK = 55;

const int DX[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int DY[] = {2, -2, 1, -1, 2, -2, 1, -1};
const char _goal[][5] = {{1, 1, 1, 1, 1}, {0, 1, 1, 1, 1}, {0, 0, BLANK, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}};

struct State
{
    State(const char _m[5][5] = NULL)
    {
        if (_m == NULL)
            return;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                board[i][j] = _m[i][j];
                if (_m[i][j] == BLANK)
                {
                    bx = i, by = j;
                }
            }
        }
    }

    char board[5][5];
    int bx, by;

    bool tryGetNext(int dir, State &next)
    {
        int nx = bx + DX[dir], ny = by + DY[dir];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
            return false;

        next = State(board);
        next.board[nx][ny] = board[bx][by];
        next.board[bx][by] = board[nx][ny];
        next.bx = nx, next.by = ny;
        return true;
    }
    int getWeight()
    {
        int res = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board[i][j] != _goal[i][j])
                    res++;
            }
        }
        return res;
    }
};

State goal(_goal);

bool dfs(int step, int maxStep, State s)
{
    int w = s.getWeight();
    if (w == 0 && step == maxStep)
        return true;
    if (step + w - 1 > maxStep)
        return false;

    for (int d = 0; d < 8; d++)
    {
        State next;
        if (!s.tryGetNext(d, next))
            continue;
        if (dfs(step + 1, maxStep, next))
            return true;
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        State init;
        for (int i = 0; i < 5; i++)
        {
            char input[8];
            scanf("%s", input);
            for (int j = 0; j < 5; j++)
            {
                switch (input[j])
                {
                case '0':
                    init.board[i][j] = 0;
                    break;
                case '1':
                    init.board[i][j] = 1;
                    break;
                case '*':
                    init.board[i][j] = BLANK;
                    init.bx = i;
                    init.by = j;
                    break;
                }
            }
        }

        int ans = -1;
        for (int step = 0; step <= MAX_STEP; step++)
        {
            if (dfs(0, step, init))
            {
                ans = step;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
