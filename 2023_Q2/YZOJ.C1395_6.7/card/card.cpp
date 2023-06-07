#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 200005;

struct Card
{
    int c, v; // c花色,v点数
};
Card cards[MAXN];

int n;
int cd[MAXN], cdSize = 1;
vector<int> seq[MAXN];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &cards[i].c, &cards[i].v);
        cd[cdSize++] = cards[i].c;
    }
    sort(cd + 1, cd + cdSize);
    cdSize = unique(cd + 1, cd + cdSize) - cd;
    for (int i = 1; i <= n; i++)
    {
        cards[i].c = lower_bound(cd + 1, cd + 1 + cdSize, cards[i].c) - cd;
        seq[cards[i].c].push_back(cards[i].v);
    }

    sort(cards + 1, cards + 1 + n);
}