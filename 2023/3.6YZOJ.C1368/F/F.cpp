// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
const int MAXC = 55;
const char *MSG_NS = "some beads may be lost\n\n";

struct Bead
{
    int from, to;
    Bead(int _f = 0, int _t = 0)
    {
        from = _f, to = _t;
    }
};

vector<Bead> outFromColor[MAXC];
int degreeOfColor[MAXC];
bool vis[MAXC];
vector<Bead> seq;

void dfs(Bead b)
{
    printf("dfs(%d,%d)\n", b.from, b.to);

    for (int i = 0; i < outFromColor[b.to].size(); i++)
    {
        Bead &dest = outFromColor[b.to][i];

        printf("checking(%d,%d)...\n", dest.from, dest.to);

        if (!vis[dest.to])
        {
            vis[dest.to] = true;
            dfs(dest);
        }
    }
    seq.push_back(b);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        memset(vis, false, sizeof(vis));
        memset(degreeOfColor, 0, sizeof(degreeOfColor));
        vector<Bead>().swap(seq);
        for (int i = 0; i < MAXC; i++)
        {
            vector<Bead>().swap(outFromColor[i]);
        }

        int beadCount;
        scanf("%d", &beadCount);
        Bead b;
        for (int i = 0; i < beadCount; i++)
        {
            scanf("%d%d", &b.from, &b.to);
            outFromColor[b.from].push_back(b);
            degreeOfColor[b.from]++;
            degreeOfColor[b.to]++;
        }

        bool bad = false;
        for (int c = 1; c <= MAXC; c++)
        {
            if (degreeOfColor[c] % 2 == 1)
            {
                bad = true;
                break;
            }
        }
        if (bad)
        {
            printf(MSG_NS);
            continue;
        }

        dfs(b);
        for (int i = 0; i < seq.size(); i++)
        {
            printf("%d %d\n", seq[i].from, seq[i].to);
        }
        printf("\n");
    }
    return 0;
}
