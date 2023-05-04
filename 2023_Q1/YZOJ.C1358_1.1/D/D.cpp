// Fixed on 2023.1.2
// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int countOf[MAXN];

int main()
{
    int n, input;
    while (scanf("%d", &n) == 1)
    {
        int maxnum = -1;
        memset(countOf, 0, sizeof(countOf));
        int magic1 = 0, magic3 = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &input);
            countOf[input]++;
            if (input > maxnum)
                maxnum = input;
        }
        for (int i = 1; i <= maxnum; i++)
        {
            if (countOf[i] == 0)
            {
                continue;
            }
            magic1 += countOf[i] == 1 ? 1 : 0;
            magic3 += countOf[i] >= 3 ? 1 : 0;
        }
        if (magic1 % 2 == 0 || magic3 > 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
