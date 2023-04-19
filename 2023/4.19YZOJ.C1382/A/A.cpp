#include <bits/stdc++.h>
using namespace std;
const int MAXN = 27;

int n;
long long sticks[MAXN];

bool isTri(long long a, long long b, long long c)
{
    return a + b > c;
}

struct Triangle
{
    int a, b, c;

    Triangle(int _a, int _b, int _c)
    {
        int n[3] = {_a, _b, _c};
        sort(n, n + 3);
        a = n[0];
        b = n[1];
        c = n[2];
    }

    bool equals(Triangle t)
    {
        return a == t.a && b == t.b && c == t.c;
    }
};
vector<Triangle> known;

bool contains(Triangle &t)
{
    for (int i = 0; i < known.size(); i++)
    {
        if (known[i].equals(t))
            return true;
    }
    return false;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        vector<Triangle>().swap(known);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", sticks + i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    long long &a = sticks[i], &b = sticks[j], &c = sticks[k];
                    if (isTri(b, c, a) && isTri(a, c, b) && isTri(a, b, c))
                    {
                        Triangle t(a, b, c);
                        if (!contains(t))
                            known.push_back(t);
                    }
                }
            }
        }

        printf("%lu\n", known.size());
    }
    return 0;
}
