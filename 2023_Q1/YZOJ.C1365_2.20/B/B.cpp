// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXT = 10086;
const int MAXN = 52;
const int JGJQ = 678;
int maxCount[MAXT];
int songs[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        memset(maxCount, -1, sizeof(maxCount));
        memset(songs, 0, sizeof(songs));
        maxCount[0] = 0;

        int n, t;
        scanf("%d%d", &n, &t);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", songs + i);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = t - 1; j >= songs[i]; j--)
            {
                maxCount[j] = max(maxCount[j], maxCount[j - songs[i]] + 1);
            }
        }

        int ansLength = t - 1;
        for (int j = t - 1; j >= 0; j--)
        {
            if (maxCount[j] > maxCount[ansLength])
                ansLength = j;
        }

        printf("Case %d: %d %d\n", kase, maxCount[ansLength] + 1, ansLength + JGJQ);
    }

    return 0;
}
