#include <cstdio>
using namespace std;

int n;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int bs = 0;
        for (int i = n; i > 0; i = (i >> 1))
            bs++;

        printf("%d\n", bs);
    }
    return 0;
}
