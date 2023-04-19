#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1004;

bool board[MAXN];
int n;
int bs;
int l;

bool play()
{
    int t = 1;
    bool flag = false;
    for (; t <= bs; t++)
    {
        if (t > 1 && board[t] && !board[t - 1])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
        return false;
    board[t - 1] = true;
    board[t] = false;
    return true;
}

void printBoard()
{
    for (int i = 1; i <= bs; i++)
    {
        printf(board[i] ? "O" : ".");
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(board, false, sizeof(board));
        bs = -1;
        l = (1 << 30) - 1;

        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            board[x] = true;
            bs = max(bs, x);
        }

        int turn = 0;
        while (play())
        {
            turn++;
            // printBoard();
        }
        printf(turn % 2 == 1 ? "Peppa will win\n" : "George will win\n");
    }
    return 0;
}
