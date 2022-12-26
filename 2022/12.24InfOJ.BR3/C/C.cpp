//Unfinished
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace Generator
{
    typedef unsigned long long ull;
    typedef __uint128_t L;
    ull seed;
    int p, q;
    struct FastMod
    {
        ull b, m;
        FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
        ull reduce(ull a)
        {
            ull q = (ull)((L(m) * a) >> 64);
            ull r = a - q * b; // can be proven that 0 <= r < 2*b
            return r >= b ? r - b : r;
        }
    } F(2);
    void init()
    {
        cin >> p >> q >> seed; // 读入 p,q,seed
        assert(p != q);
        F = FastMod(q - p + 1);
    }
    unsigned long long rd()
    {
        seed ^= (seed << 13);
        seed ^= (seed >> 7);
        seed ^= (seed << 17);
        return seed;
    }
    void getlr(int &l1, int &r1, int &l2, int &r2)
    {
        // 将 l1,r1,l2,r2 作为参数传入，即可得到一组询问
        l1 = F.reduce(rd()) + p;
        r1 = F.reduce(rd()) + p;
        l2 = F.reduce(rd()) + p;
        r2 = F.reduce(rd()) + p;
        if (l1 > r1)
            swap(l1, r1);
        if (l2 > r2)
            swap(l2, r2);
    }

}
int n, m, a[100005];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Generator::init();
    long long xorsum = 0;
    for (int i = 1, l1, r1, l2, r2; i <= m; i++)
    {
        Generator::getlr(l1, r1, l2, r2);
        long long ans = /*ans保存你的答案*/;
        xorsum ^= ans * i;
    }
    cout << xorsum;
}