// WA: 50%
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF = (1 << 31) - 1;
int arr[MAXN];
int sumLeft[MAXN];
int sumRight[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n > 0)
    {
        memset(arr, 0, sizeof(arr));
        memset(sumLeft, 0, sizeof(sumLeft));
        memset(sumRight, 0, sizeof(sumRight));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", arr + i);
            sumLeft[i] = sumLeft[i - 1] + arr[i];
        }
        for (int i = n; i >= 1; i--)
        {
            sumRight[i] = sumRight[i + 1] + arr[i];
        }

        int head = 0, tail = n + 1;
        int scoreA = 0, scoreB = 0;
        bool person = true; // true=>A, false=>B
        while (tail - head > 1)
        {
            int maxSumLeft = -INF, maxSumRight = -INF;
            int maxLeftIdx = 0, maxRightIdx = 0;
            if (person)
            {
                for (int i = head + 1; i < tail; i++)
                {
                    if (sumLeft[i] >= maxSumLeft)
                    {
                        maxSumLeft = sumLeft[i];
                        maxLeftIdx = i;
                    }
                }
                scoreA += sumLeft[maxLeftIdx] - sumLeft[head];
                head = maxLeftIdx;
            }
            else
            {
                for (int i = tail - 1; i > head; i--)
                {
                    if (sumRight[i] >= maxSumRight)
                    {
                        maxSumRight = sumRight[i];
                        maxRightIdx = i;
                    }
                }
                scoreB += sumRight[maxRightIdx] - sumRight[tail];
                tail = maxRightIdx;
            }
            person = !person;
        }
        printf("%d\n", abs(scoreA - scoreB));
    }
    return 0;
}
