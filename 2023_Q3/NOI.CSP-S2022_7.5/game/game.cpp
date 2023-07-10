#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 100005;
const int MAX_LG = 19;
const int INF = (1 << 30) - 1;
const long long INF_LL = (1LL << 62) - 1;

struct Round
{
    int l1, r1, l2, r2;
};
Round rounds[MAXN];

int arrA[MAXN], arrB[MAXN];
int stMaxA[MAX_LG][MAXN], stMinA[MAX_LG][MAXN];
int stMaxB[MAX_LG][MAXN], stMinB[MAX_LG][MAXN];
int stMinPosA[MAX_LG][MAXN], stMaxNegA[MAX_LG][MAXN];
int n, m, q;
int lg2[MAXN];

inline int getMinA(int l, int r)
{
    int lg = lg2[r - l + 1];
    return min(stMinA[lg][r], stMinA[lg][l + (1 << lg) - 1]);
}
inline int getMaxA(int l, int r)
{
    int lg = lg2[r - l + 1];
    return max(stMaxA[lg][r], stMaxA[lg][l + (1 << lg) - 1]);
}
inline int getMinPosA(int l, int r)
{
    int lg = lg2[r - l + 1];
    return min(stMinPosA[lg][r], stMinPosA[lg][l + (1 << lg) - 1]);
}
inline int getMaxNegA(int l, int r)
{
    int lg = lg2[r - l + 1];
    return max(stMaxNegA[lg][r], stMaxNegA[lg][l + (1 << lg) - 1]);
}
inline int getMinB(int l, int r)
{
    int lg = lg2[r - l + 1];
    return min(stMinB[lg][r], stMinB[lg][l + (1 << lg) - 1]);
}
inline int getMaxB(int l, int r)
{
    int lg = lg2[r - l + 1];
    return max(stMaxB[lg][r], stMaxB[lg][l + (1 << lg) - 1]);
}
inline void solveSP1And2()
{
    long long res = 0;
    for (int i = 1; i <= q; i++)
    {
        Round &r = rounds[i];
        if (r.l1 == r.r1)
            res = 1LL * getMinB(r.l2, r.r2) * arrA[r.r1];
        else // r.l2 == r.r2
            res = 1LL * getMaxA(r.l1, r.r1) * arrB[r.r2];

        printf("%lld\n", res);
    }
}
inline void solveSP1()
{
    long long res = 0;
    for (int i = 1; i <= q; i++)
    {
        Round &r = rounds[i];
        int maxA = getMaxA(r.l1, r.r1);
        int minB = getMinB(r.l2, r.r2);
        res = 1LL * maxA * minB;
        printf("%lld\n", res);
    }
}
inline void solveSP2()
{
    long long res = 0;
    for (int i = 1; i <= q; i++)
    {
        Round &r = rounds[i];
        if (r.l1 == r.r1)
        {
            if (arrA[r.l1] == 0)
                res = 0;
            else if (arrA[r.l1] > 0)
                res = 1LL * getMinB(r.l2, r.r2) * arrA[r.r1];
            else // arrA[r.l1] < 0
                res = 1LL * getMaxB(r.l2, r.r2) * arrA[r.r1];
        }
        else // r.l2 == r.r2
        {
            if (arrB[r.l2] == 0)
                res = 0;
            else if (arrB[r.l2] > 0)
                res = 1LL * getMaxA(r.l1, r.r1) * arrB[r.r2];
            else // arrA[r.l2] < 0
                res = 1LL * getMinA(r.l1, r.r1) * arrB[r.r2];
        }
        printf("%lld\n", res);
    }
}
inline void solveGeneral()
{
    for (int i = 1; i <= q; i++)
    {
        long long res = -INF_LL;
        Round &r = rounds[i];
        int minl = getMinA(r.l1, r.r1);
        int maxl = getMaxA(r.l1, r.r1);
        int minPosL = getMinPosA(r.l1, r.r1);
        int maxNegL = getMaxNegA(r.l1, r.r1);
        int minq = getMinB(r.l2, r.r2);
        int maxq = getMaxB(r.l2, r.r2);
        res = max(res, 1LL * maxl * (maxl >= 0 ? minq : maxq));
        res = max(res, 1LL * minl * (minl >= 0 ? minq : maxq));
        if (minPosL != INF)
            res = max(res, 1LL * minPosL * (minPosL >= 0 ? minq : maxq));
        if (maxNegL != -INF)
            res = max(res, 1LL * maxNegL * (maxNegL >= 0 ? minq : maxq));
        printf("%lld\n", res);
    }
}

int main()
{

    bool sp1 = true, sp2 = true;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 2; i <= max(n, m); i++)
    {
        lg2[i] = lg2[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arrA + i);
        stMaxA[0][i] = stMinA[0][i] = arrA[i];
        stMinPosA[0][i] = (arrA[i] >= 0) ? arrA[i] : INF;
        stMaxNegA[0][i] = (arrA[i] < 0) ? arrA[i] : -INF;
        if (arrA[i] <= 0)
            sp1 = false;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", arrB + i);
        stMaxB[0][i] = stMinB[0][i] = arrB[i];
        if (arrB[i] <= 0)
            sp1 = false;
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d%d", &rounds[i].l1, &rounds[i].r1, &rounds[i].l2, &rounds[i].r2);
        if (rounds[i].l1 != rounds[i].r1 && rounds[i].l2 != rounds[i].r2)
            sp2 = false;
    }

    // printf("%d %d\n", sp1, sp2);

    for (int lg = 1, len = (1 << lg); len <= n; lg++, len = (1 << lg))
    {
        for (int i = n; i > (1 << (lg - 1)); i--)
        {
            stMaxA[lg][i] = max(stMaxA[lg - 1][i], stMaxA[lg - 1][i - (1 << (lg - 1))]);
            stMinA[lg][i] = min(stMinA[lg - 1][i], stMinA[lg - 1][i - (1 << (lg - 1))]);
            stMinPosA[lg][i] = min(stMinPosA[lg - 1][i], stMinPosA[lg - 1][i - (1 << (lg - 1))]);
            stMaxNegA[lg][i] = max(stMaxNegA[lg - 1][i], stMaxNegA[lg - 1][i - (1 << (lg - 1))]);
        }
    }
    for (int lg = 1, len = (1 << lg); len <= m; lg++, len = (1 << lg))
    {
        for (int i = m; i > (1 << (lg - 1)); i--)
        {
            stMaxB[lg][i] = max(stMaxB[lg - 1][i], stMaxB[lg - 1][i - (1 << (lg - 1))]);
            stMinB[lg][i] = min(stMinB[lg - 1][i], stMinB[lg - 1][i - (1 << (lg - 1))]);
        }
    }

    if (sp1 && sp2)
        solveSP1And2();
    else if (sp1)
        solveSP1();
    else if (sp2)
        solveSP2();
    else
        solveGeneral();

    return 0;
}