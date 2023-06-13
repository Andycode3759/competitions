// AC
// Fixed: 2023.6.10
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 200005;

struct Card
{
    int c, v; // c花色,v点数

    const bool operator<(const Card &a) const
    {
        return (c == a.c) ? v < a.v : c < a.c;
    }
    const bool operator==(const Card &a) const
    {
        return c == a.c && v == a.v;
    }
};
Card cards[MAXN];

vector<int> uc;

int n;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &cards[i].c, &cards[i].v);
    }
    sort(cards + 1, cards + 1 + n);
    int cc = unique(cards + 1, cards + 1 + n) - cards - 1;
    int lc = -1;
    for (int i = 1; i <= cc; i++)
    {
        if (cards[i].c != lc)
        {
            uc.push_back(i);
            lc = cards[i].c;
        }
    }
    uc.push_back(cc + 1);
    int ans = 0;
    for (int c = 0; c < uc.size(); c++)
    {
        for (int l = uc[c]; l < uc[c + 1]; l++)
        {
            for (int r = l; r < uc[c + 1]; r++)
            {
                if (cards[r].v - cards[l].v <= n - 1)
                {
                    ans = max(ans, r - l + 1);
                }
            }
        }
    }
    printf("%d\n", n - ans);
}