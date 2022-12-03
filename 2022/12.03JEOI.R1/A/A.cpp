/*
    Score: 72/100
    WA: 2/8 cases
*/
#include <bits/stdc++.h>
using namespace std;

struct Pos
{
    int x, y;

    bool getColor()
    {
        return (x + y) % 2 == 0; // true=>black, false=>white
    }
};

int m, n, c;
// vector<Pos> chess;
int bchess, wchess;
int btotal, wtotal;

int read()
{ // get a int
    int x(0);
    char c(getchar());
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}

int main()
{
    n = read();
    m = read();
    c = read();
    btotal = n * m / 2;
    wtotal = n * m / 2;
    if (n % 2 == 1 && m % 2 == 1)
    {
        btotal++;
    }
    for (int i = 0; i < c; i++)
    {
        Pos p;
        p.x = read();
        p.y = read();
        // chess.push_back(p);
        if (p.getColor())
            bchess++;
        else
            wchess++;
    }
    int q = read();
    for (int i = 0; i < q; i++)
    {
        Pos start, to;
        start.x = read();
        start.y = read();
        to.x = read();
        to.y = read();
        int count = read();
        // vector<Pos> target;
        int btarget = 0, wtarget = 0;
        int bcover = 0, wcover = 0;
        int height = to.x - start.x + 1;
        int width = to.y - start.y + 1;
        bool color = start.getColor();
        bcover = height * width / 2;
        wcover = height * width / 2;
        if (height % 2 == 1 && width % 2 == 1)
        {
            if (color)
                bcover++;
            else
                wcover++;
        }
        for (int k = 0; k < count; k++)
        {
            Pos p;
            p.x = read();
            p.y = read();
            // target.push_back(p);
            if (p.getColor())
                btarget++;
            else
                wtarget++;
        }

        // do the bussiness here
        int bmagic = bchess - btarget;
        int wmagic = wchess - wtarget;
        int bfree = btotal - bcover;
        int wfree = wtotal - wcover;
        if (0 <= bmagic && bmagic <= bfree && 0 <= wmagic && wmagic <= wfree)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        //如果总颜色棋子数<目标颜色棋子数 或者 总颜色棋子数-目标颜色棋子数>场外空余的颜色格子
        // NO
        //反过来 如果0<=总颜色棋子数-目标颜色棋子数<=场外颜色格子数
        // YES
        // end
    }

    return 0;
}
