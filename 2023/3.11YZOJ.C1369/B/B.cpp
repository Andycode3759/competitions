// Unfinished
// 交个代码证明试了这道题
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXCHUNK = 103;

int island[MAXN];
int pos = 0;
long long lastProfit = 0;

struct Chunk
{
    int data[MAXCHUNK];
    int size;
    long long sum = 0;
    int rleft, rright;

    Chunk(int _s = 0, int _l = 0, int _r = 0)
    {
        size = _s;
        rleft = _l;
        rright = _r;
    }
    int dumpDataFrom(int *start, int *end)
    {
        int idx = 0;
        for (int *i = start; i != end; i++)
        {
            data[idx++] = *i;
        }
    }
    void clear(int left, int right)
    {
        for (int i = left; i < size && i <= right; i++)
        {
            sum -= data[i];
            data[i] = 0;
        }
    }
    void clearAll()
    {
        sum = 0;
    }
    long long getValue()
    {
        return sum;
    }
    long long getRangeValue(int left, int right)
    {
        if (sum == 0)
            return 0;
        int res = 0;
        for (int i = left; i <= right; i++)
        {
            res += data[i];
        }
        return res;
    }
};

Chunk chunks[MAXCHUNK];

int main()
{
    int n;
    scanf("%d", &n);
    int chunkSize = sqrt(n);
    for (int i = 1; i <= chunkSize; i++)
    {
        chunks[i] = Chunk(chunkSize, 1 + (i - 1) * chunkSize, i * chunkSize);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", island + i);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1: {
            int dis, dir;
            scanf("%d%d", &dis, &dir);
            int newPos = (dir == 1) ? pos - dis : pos + dis;
            int l = min(newPos, pos), r = max(newPos, pos);
            pos = newPos;
            lastProfit = 0;
            for (int c = l / chunkSize + 1; c <= r / chunkSize + 1; c++)
            {
                Chunk &ck = chunks[c];
                int al = max(l, ck.rleft);
                int ar = min(r, ck.rright);
                if (l > ck.rleft || r < ck.rright)
                {
                    lastProfit += ck.getRangeValue(al - ck.rleft, ar - ck.rleft);
                    continue;
                }
            }
            break;
        }

        case 2: {
            printf("%lld\n", lastProfit);
            break;
        }

        case 3: {
            printf("%d\n", pos);
            break;
        }
        }
    }
    return 0;
}
