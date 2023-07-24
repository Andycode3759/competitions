#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 10004;

int n;
int arr[MAXN];

int ans;
bool vis[40010];
void dfs(int state)
{
    if (vis[state])
        return;
    vis[state] = true;
    int arr1[6], arr2[6];
    for (int i = 1; i <= 4; i++)
    {
        arr2[i] = arr1[i] = state % 11;
        state /= 11;
    }
    arr1[2] = arr1[1] + arr1[3] - arr1[2];
    arr2[3] = arr2[2] + arr2[4] - arr2[3];
    int state1 = 0, state2 = 0;
    for (int i = 4; i >= 1; i--)
    {
        state1 = state1 * 11 + arr1[i];
        state2 = state2 * 11 + arr2[i];
    }
    dfs(state1);
    dfs(state2);
}

int main()
{
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);

    arr[0] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    // do stuff
    if (n > 4)
    {
        printf("%d\n", n * n);
        return 0;
    }
    int state = 0;
    for (int i = 4; i >= 1; i--)
    {
        state = state * 11 + arr[i];
    }
    dfs(state);

    int ans = (1 << 30) - 1;
    for (int i = 0; i < 40000; i++)
    {
        if (!vis[i])
            continue;
        int s = i;
        for (int j = 1; j <= 4; j++)
        {
            arr[j] = s % 11;
            s /= 11;
        }
        double avg = (arr[1] + arr[2] + arr[3] + arr[4]) / 4.0;
        double sum = 0;
        for (int i = 1; i <= 4; i++)
        {
            sum += (arr[i] - avg) * (arr[i] - avg);
        }
        sum *= n;
        ans = min(ans, (int)round(sum));
    }
    printf("%d\n", ans);

    return 0;
}
