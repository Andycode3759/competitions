// AC
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

struct State
{
    State()
    {
        for (int i = 0; i < 9; i++)
        {
            board[i] = 0;
        }
    }
    State(const int *arr)
    {
        for (int i = 0; i < 9; i++)
        {
            board[i] = arr[i];
        }
    }

    bool tryGetNext(int d, State &st)
    {
        // d=1,2,3,4 left,up,right,down
        int zPos;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == 0)
            {
                zPos = i;
                break;
            }
        }
        int r = zPos / 3, c = zPos % 3;

        if ((r == 0 && d == 2) || (r == 2 && d == 4) || (c == 0 && d == 1) || (c == 2 && d == 3))
            return false;

        for (int i = 0; i < 9; i++) // copy
        {
            st.board[i] = board[i];
        }

        switch (d)
        {
        case 1:
            swap(st.board[zPos], st.board[zPos - 1]);
            break;
        case 2:
            swap(st.board[zPos], st.board[zPos - 3]);
            break;
        case 3:
            swap(st.board[zPos], st.board[zPos + 1]);
            break;
        case 4:
            swap(st.board[zPos], st.board[zPos + 3]);
            break;
        default:
            return false;
        }

        return true;
    }

    bool equals(State a)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i] != a.board[i])
                return false;
        }
        return true;
    }

    const bool operator<(const State &a) const
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i] != a.board[i])
            {
                return board[i] < a.board[i];
            }
        }
        return false;
    }

    char board[11];
};

struct Node
{
    Node(State _s, int _t) : st(_s), step(_t)
    {
    }
    State st;
    int step;
};

set<State> mark;

int main()
{
    int s[11];
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", s + i);
    }
    State start(s);
    const int G[] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
    State goal(G);

    queue<Node> Q;
    Q.push(Node(start, 0));
    int ans = -1;
    while (!Q.empty())
    {
        Node cur = Q.front();
        Q.pop();

        if (mark.count(cur.st) > 0)
            continue;
        if (cur.step > 5000)
            break;
        if (cur.st.equals(goal))
        {
            ans = cur.step;
            break;
        }
        mark.insert(cur.st);

        for (int i = 1; i <= 4; i++)
        {
            State t;
            if (cur.st.tryGetNext(i, t) && mark.count(t) == 0)
                Q.push(Node(t, cur.step + 1));
        }
    }

    printf("%d\n", ans);
    return 0;
}
