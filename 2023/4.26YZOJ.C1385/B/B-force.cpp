#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

int n;
bool mark[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    char input[8];
    int x, y;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d", input, &x, &y);
        if (x >= MAXN || y >= MAXN)
            continue;
        switch (input[0])
        {
        case 'a': // add
            mark[x][y] = true;
            break;
        case 'r': // remove
            mark[x][y] = false;
            break;
        case 'f': // find
            bool flag = false;
            for (int i = x + 1; i < MAXN; i++)
            {
                for (int j = y + 1; j < MAXN; j++)
                {
                    if (mark[i][j])
                    {
                        printf("%d %d\n", i, j);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
                printf("-1\n");
            break;
        }
    }
    return 0;
}
