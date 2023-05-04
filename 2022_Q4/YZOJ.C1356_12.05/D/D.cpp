//Score: 100/100
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    int mem;
    while (scanf("%d%d", &a, &b) == 2 && a != 0 && b != 0)
    {
        mem = 1;
        for (int i = 0; i < b; i++)
        {
            mem *= a;
            mem %= 1000;
        }
        printf("%d\n", mem);
    }
    return 0;
}
