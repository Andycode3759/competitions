// AC
#include <cstdio>
using namespace std;
const int MAXN = 2e8 + 8;
const int MOD = 1e9 + 7;

int f[MAXN];
int mxn = 1;
int n;

int main()
{
    f[0] = 1, f[1] = 1;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n > mxn)
        {
            for (int i = mxn + 1; i <= n << 1; i++)
            {
                f[i] = f[i - 1] + f[i - 2];
                if (f[i] >= MOD)
                    f[i] -= MOD;
            }
            mxn = n;
        }
        printf("%d\n", f[n]);
        printf("%d\n", f[(n << 1) - 1]);
    }
    return 0;
}
