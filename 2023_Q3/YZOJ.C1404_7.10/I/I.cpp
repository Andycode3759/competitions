// AC
#include <cstdio>
using namespace std;
const int MAXN = 202;

inline void memset(void *s, int c, unsigned int len)
{
    char *p = (char *)s;
    while (len--)
        *p++ = (char)c;
}
constexpr int max(const int &a, const int &b)
{
    return a < b ? b : a;
}
constexpr int square(const int &x)
{
    return x * x;
}

struct Block
{
    int color;
    int len;
};
Block blk[MAXN];
int bCnt = 0;

int ans[MAXN][MAXN][MAXN];
int box[MAXN];
int n;

int getAns(int i, int j, int exLen)
{
    int &res = ans[i][j][exLen];
    if (res >= 0)
        return res;
    res = square(blk[j].len + exLen);
    if (i == j)
        return res;

    // Option 1: 直接消j+exLen
    res += getAns(i, j - 1, 0);

    // Option 2: 等到j+exLen与前面的块k合并
    for (int k = j - 1; k >= i; k--)
    {
        if (blk[k].color != blk[j].color)
            continue;
        res = max(res, getAns(i, k, blk[j].len + exLen) + getAns(k + 1, j - 1, 0));
    }

    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int Kase = 1; Kase <= T; Kase++)
    {
        memset(ans, -1, sizeof(ans));
        bCnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", box + i);
        Block b;
        int len = 1, col = box[1];
        for (int i = 2; i <= n; i++)
        {
            if (box[i] == box[i - 1])
                len++;
            else
                b.len = len, b.color = col, blk[++bCnt] = b, len = 1, col = box[i];
        }
        b.len = len, b.color = col, blk[++bCnt] = b;
        printf("Case %d: %d\n", Kase, getAns(1, bCnt, 0));
    }
    return 0;
}
