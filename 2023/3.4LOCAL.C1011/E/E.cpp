// Unfinished
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
const int DIR[9][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
bool board[MAXN][MAXN];
bool safe[MAXN][MAXN];
int n, k;
int ans = 0;
int fractional[MAXN];

void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(board[i][j] ? "X" : ".");
        }
        printf("\n");
    }
    printf("\n");
}

bool isGoodPoint(int x, int y)
{
    int nx, ny;
    for (int i = 0; i < 9; i++)
    {
        nx = x + DIR[i][0], ny = y + DIR[i][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (board[nx][ny])
            return false;
    }
    return true;
}

void updateSafe(int cx, int cy)
{
    int nx, ny;
    for (int d = 0; d < 9; d++)
    {
        nx = cx + DIR[d][0], ny = cy + DIR[d][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        safe[nx][ny] = isGoodPoint(nx, ny);
    }
}

void dfs(int kingLeft)
{
    if (kingLeft == 0)
    {
        ans++;
        // printBoard();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (safe[i][j])
            {
                board[i][j] = true;
                updateSafe(i, j);
                dfs(kingLeft - 1);
                board[i][j] = false;
                updateSafe(i, j);
            }
        }
    }
    return;
}

int main()
{
    fractional[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fractional[i] = fractional[i - 1] * i;
    }
    memset(safe, true, sizeof(safe));
    scanf("%d%d", &n, &k);
    dfs(k);
    printf("%d\n", ans / fractional[k]);
    return 0;
}
