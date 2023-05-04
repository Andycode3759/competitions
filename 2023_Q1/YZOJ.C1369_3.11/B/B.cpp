// AC
// Fixed on 2023.3.13
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

long long latestProfit = 0;
int pos = 0;
int cut = 1; // 最靠左边的有宝藏的位置

int treasure[MAXN];
long long treasureSum[MAXN]; // 前缀和

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", treasure + i);
        treasureSum[i] = treasureSum[i - 1] + treasure[i];
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1: // move
            int dis, dir;
            scanf("%d%d", &dis, &dir);
            if (dir == 1) // left
            {
                latestProfit = 0;
                pos -= dis;
                pos = max(pos, 1);
            }
            if (dir == 2) // right
            {
                int oldPos = pos;
                pos += dis;
                pos = min(pos, n);
                if (pos < cut)
                {
                    latestProfit = 0;
                    break;
                }
                int l = max(oldPos, cut);
                int r = pos;
                latestProfit = treasureSum[r] - treasureSum[l - 1];
                cut = max(cut, pos + 1);
            }
            break;
        case 2: // query latestProfit
            printf("%lld\n", latestProfit);
            break;
        case 3: // query pos
            printf("%d\n", pos);
            break;
        }
    }
    return 0;
}