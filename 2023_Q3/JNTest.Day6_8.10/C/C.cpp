#include <cstdio>
#include <cstring>
using namespace std;
constexpr int MOD = 114514;
constexpr int MAXN = 500005;

int len;
char str[MAXN];
int sel[8];
int ans = 0;
void dfs(int step, int lst)
{
    if (step > 6)
    {
        if (str[sel[1]] == str[sel[2]] && str[sel[2]] == str[sel[5]] && str[sel[3]] == str[sel[6]] &&
            str[sel[4]] != str[sel[5]] && str[sel[5]] != str[sel[6]] && str[sel[6]] != str[sel[4]])
            ans++;
        if (ans >= MOD)
            ans -= MOD;
        return;
    }
    for (int i = lst + 1; i <= len + step - 6; i++)
    {
        sel[step] = i;
        dfs(step + 1, i);
    }
}

int main()
{
    scanf("%s", str + 1);
    len = strlen(str + 1);
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}