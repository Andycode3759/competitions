// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;

bool binArr[MAXN];
int n, k;

int preSum[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    char c = getchar();
    while (c != '0' && c != '1')
        c = getchar();
    int idx = 1;
    while (c == '0' || c == '1')
    {
        binArr[idx++] = c - '0';
        c = getchar();
    }

    for (int i = 1; i <= n; i++)
    {
        preSum[i] = preSum[i - 1] + (!binArr[i]);
    }
    int maxCnt = -1;
    for (int i = k; i <= n; i++)
    {
        int cnt = preSum[i] - preSum[i - k];
        maxCnt = max(maxCnt, cnt);
    }
    printf("%d\n", k - maxCnt);

    return 0;
}
