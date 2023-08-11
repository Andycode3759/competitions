#include <cstdio>
#include <set>
using namespace std;
const int MAXM = 204;
using iter = set<int>::iterator;

int n, m;
int arr[MAXM];
int cnt[MAXM];
set<int> div;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", arr + i);
    }

    for (int i = 1; i <= m; i++)
    {
        for (int d = 1; d * d <= arr[i]; d++)
        {
            if (arr[i] % d == 0)
            {
                if (d <= n)
                    div.insert(d);
                if (arr[i] / d <= n)
                    div.insert(arr[i] / d);
            }
        }
    }
    int tot = 0;
    for (iter i = div.begin(); i != div.end(); i++)
    {
        // printf("div: %d\n", *i);
        int t = 0;
        for (int j = 1; j <= m; j++)
        {
            if (arr[j] % (*i) == 0)
                t++;
        }
        tot++;
        cnt[t]++;
    }
    cnt[0] = n - tot;

    for (int i = 0; i <= m; i++)
    {
        printf("%d\n", cnt[i]);
    }

    return 0;
}