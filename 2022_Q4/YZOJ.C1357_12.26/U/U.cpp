//ACCEPETED
#include <bits/stdc++.h>
using namespace std;
const int PRICE = 200;
const int MAXN = 2023;
int win = 0;
int tianji[MAXN], qiwang[MAXN];

void compete(int t, int q)
{
    if (t > q)
    {
        win++;
    }
    else if (t < q)
    {
        win--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tianji[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &qiwang[i]);
    }
    sort(tianji, tianji + n);
    sort(qiwang, qiwang + n);
    int tl = 0, tb = n, ql = 0,
        qb = n; // tianji_last,tianji_best,qiwang_last,qiwang_best
    while (tl < tb && ql < qb)
    {
        if (tianji[tb - 1] > qiwang[qb - 1])
        {
            compete(tianji[tb - 1], qiwang[qb - 1]);
            tb--;
            qb--;
        }
        else if (tianji[tb - 1] < qiwang[qb - 1])
        {
            compete(tianji[tl], qiwang[qb - 1]);
            tl++;
            qb--;
        }
        else // tianji[tb-1]==qiwang[qb-1]
        {
            if (tianji[tl] > qiwang[ql])
            {
                compete(tianji[tl], qiwang[ql]);
                tl++;
                ql++;
            }
            else
            {
                compete(tianji[tl], qiwang[qb - 1]);
                tl++;
                qb--;
            }
        }
    }
    printf("%d\n", win * PRICE);
    return 0;
}
