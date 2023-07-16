// AC
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 62505;

inline void memset(void *dest, int ch, unsigned int cnt)
{
    char *c = (char *)dest;
    while (cnt--)
        *(c++) = (char)ch;
}

int n, p, q;
int arrA[MAXN], arrB[MAXN];
int pos[MAXN], cnt = 0;
int mark[MAXN];
int tail[MAXN], len;

int main()
{
    int T;
    scanf("%d", &T);
    for (int Kase = 1; Kase <= T; Kase++)
    {
        scanf("%d%d%d", &n, &p, &q);
        len = 1, cnt = 0;
        memset(mark, 0, sizeof mark);
        memset(tail, 0, sizeof tail);
        for (int i = 1; i <= p + 1; i++)
            scanf("%d", arrA + i);
        for (int i = 1; i <= q + 1; i++)
            scanf("%d", arrB + i), mark[arrB[i]] = i;
        for (int i = 1; i <= p + 1; i++)
            if (mark[arrA[i]] != 0)
                pos[++cnt] = mark[arrA[i]];

        tail[1] = pos[1];
        for (int i = 2; i <= cnt; i++)
        {
            if (pos[i] >= tail[len])
                tail[++len] = pos[i];
            else
            {
                int idx = lower_bound(tail + 1, tail + len, pos[i]) - tail;
                tail[idx] = pos[i];
            }
        }
        printf("Case %d: %d\n", Kase, len);
    }
    return 0;
}
