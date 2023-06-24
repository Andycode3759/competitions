#include <cstdio>
using namespace std;
const int MAXN = 102;

int m[MAXN][MAXN][MAXN]; // f[i]*f[j]的系数, i<=j

int main()
{
    m[1][1][1] = 1, m[2][1][1] = 1, m[2][2][2] = 1;
    for (int i = 3; i < MAXN; i++)
    {
        m[i][i][i] = 1;
        for (int j = i; j > 2; j--)
        {
            for (int k = j; k > 2; k--)
            {
                m[i][k - 2][j - 2] += m[i][k][j];
            }
        }
    }

    return 0;
}
