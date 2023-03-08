// Fixed on 2023.1.2
// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
    {
        while (c > 1 && (c % a == 0 || c % b == 0))
        {
            if (c % a == 0)
                c /= a;
            if (c % b == 0)
                c /= b;
        }
        printf(c == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}
