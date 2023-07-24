#include <cstdio>
using namespace std;
const int MAXN = 155;
const int MOD = 998244353;

int n, m, k;
int v[MAXN];

int a[MAXN];
long long ans = 0;
int cnt[MAXN];
void dfs(int step)
{
    if (step > n)
    {
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d ", a[i]);
        // }

        for (int i = 0; i < MAXN; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt[a[i]]++;
        }
        for (int i = 0; i < MAXN - 1; i++)
        {
            int x = cnt[i];
            cnt[i + 1] += x / 2;
            cnt[i] = x % 2;
        }
        int tot = 0;
        for (int i = 0; i < MAXN; i++)
        {
            tot += cnt[i];
        }
        if (tot <= k)
        {
            // printf("ok");
            long long res = 1;
            for (int i = 1; i <= n; i++)
            {
                res = (res * v[a[i]]) % MOD;
            }
            ans = (ans + res) % MOD;
        }
        // printf("\n");

        return;

        /*
        if(a is legit)
        {
            calculate weight;
            add to ans;
        }
        return;
        */
    }
    for (int i = 0; i <= m; i++)
    {
        a[step] = i;
        dfs(step + 1);
    }
}

int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= m; i++)
    {
        scanf("%d", v + i);
    }

    // do stuff
    dfs(1);
    printf("%lld\n", ans);

    return 0;
}
