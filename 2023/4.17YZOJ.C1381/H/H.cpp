#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 10;

bool markRow[MAXN][MAXN];
bool markCol[MAXN][MAXN];
bool markBlock[MAXN][MAXN];
int board[MAXN][MAXN];

struct Point
{
    int row, column;

    Point(int _r = 0, int _c = 0) : row(_r), column(_c)
    {
    }
};
int getBlock(const Point &p)
{
    return (p.row / 3) * 3 + p.column / 3;
}
void setMark(const Point &p, int num, bool val)
{
    markRow[p.row][num] = val;
    markCol[p.column][num] = val;
    markBlock[getBlock(p)][num] = val;
}

Point blanks[MAXN * MAXN];
int blanksCnt = 0;

bool dfs(int curBlank)
{
    if (curBlank >= blanksCnt)
        return true;

    Point &bl = blanks[curBlank];
    for (int num = 1; num <= 9; num++)
    {
        if (markRow[bl.row][num] || markCol[bl.column][num] || markBlock[getBlock(bl)][num])
            continue;
        board[bl.row][bl.column] = num;
        setMark(bl, num, true);
        if (dfs(curBlank + 1))
            return true;
        board[bl.row][bl.column] = 0;
        setMark(bl, num, false);
    }

    return false;
}

void printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%1d", &board[i][j]);
            if (board[i][j] == 0) // is blank
            {
                blanks[blanksCnt++] = Point(i, j);
            }
            else
            {
                setMark(Point(i, j), board[i][j], true);
            }
        }
    }

    if (dfs(0))
        printBoard();

    return 0;
}
