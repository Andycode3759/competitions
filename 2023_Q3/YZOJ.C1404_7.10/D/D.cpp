#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 103;

inline void printInt128(__int128 x)
{
    vector<char> S;
    if (x == 0)
        printf("0\n");
    while (x > 0)
    {
        S.push_back((int)(x % 10) + '0');
        x /= 10;
    }
    for (int i = S.size() - 1; i >= 0; i--)
        printf("%c", S[i]);
    printf("\n");
}

__int128 ans[2][MAXN][MAXN][2][2];

int n;
__int128 res;

// a行b列
/*
       1   2   3 ... b-1   b
   1   x   x   x ...   x   x
   2   x                   x
   3   x                   x
   ... ...                 ...
   a-1 x                   x
   a   x   x   x ...   x   x
*/
__int128 solve(int a, int b)
{
    memset(ans, 0, sizeof ans);
    int cur = 0;
    __int128 res = 0;
    for (int up = 1; up <= a; up++)
    {
        for (int down = up; down <= a; down++)
        {
            for (int p = 0; p <= 1; p++)
            {
                for (int q = 0; q <= 1; q++)
                {
                    ans[cur][up][down][p][q] = 1;
                }
            }
        }
    }
    cur ^= 1;
    for (int k = 2; k <= b; k++)
    {
        for (int up = 1; up <= a; up++)
        {
            for (int down = up; down <= a; down++)
            {
                // 上界上升，下界下降
                for (int i = 1; i <= up; i++)
                {
                    for (int j = down; j <= a; j++)
                    {
                        ans[cur ^ 1][up][down][1][0] += ans[cur][i][j][1][0];
                        if (j == a)
                            ans[cur ^ 1][up][down][1][0] = ans[cur ^ 1][up][down][1][1];
                    }
                    if (i == 1)
                        ans[cur ^ 1][up][down][0][0] = ans[cur ^ 1][up][down][1][0];
                }
                // 上界上升，下界上升
                for (int i = 1; i <= up; i++)
                {
                    for (int j = up; j <= down; j++)
                    {
                        ans[cur ^ 1][up][down][1][1] += ans[cur][i][j][1][1];
                    }
                    if (i == 1)
                        ans[cur ^ 1][up][down][0][1] = ans[cur ^ 1][up][down][1][1];
                }
                // 上界下降，下界上升
                for (int i = up; i <= a; i++)
                {
                    for (int j = i; j <= down; j++)
                    {
                        ans[cur ^ 1][up][down][0][1] += ans[cur][i][j][0][1];
                    }
                }
                // 上界下降，下界下降
                for (int i = up; i <= a; i++)
                {
                    for (int j = down; j <= a; j++)
                    {
                        ans[cur ^ 1][up][down][0][0] += ans[cur][i][j][0][0];
                        if (j == a)
                            ans[cur ^ 1][up][down][0][0] = ans[cur ^ 1][up][down][0][1];
                    }
                }
            }
        }
        cur ^= 1;
    }
    for (int up = 1; up <= a; up++)
    {
        for (int down = up; down <= a; down++)
        {
            for (int p = 0; p <= 1; p++)
            {
                for (int q = 0; q <= 1; q++)
                {
                    res += ans[cur][up][down][p][q];
                }
            }
        }
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int Kase = 1; Kase <= T; Kase++)
    {
        scanf("%d", &n);
        if (n % 2 == 1)
        {
            printf("Case #%d: 0\n", Kase);
            continue;
        }
        n /= 2;
        res = 0;

        for (int a = 1; a <= n - 1; a++)
            res += solve(a, n - a);

        printf("Case #%d: ", Kase);
        printInt128(res);
    }
    return 0;
}
