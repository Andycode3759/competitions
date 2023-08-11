#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
constexpr int MAXN = 55;

char strA[MAXN], strB[MAXN];
char strC[MAXN * 2];
int lenA, lenB;

int getRevLen(char *str, int len)
{
    int res = 0;
    for (int mid = 1; mid <= len; mid++)
    {
        for (int i = 1; mid - i + 1 >= 1 && mid + i - 1 <= len; i++)
        {
            int l = mid - i + 1, r = mid + i - 1;
            if (str[l] == str[r])
                res = max(res, i * 2 - 1);
            else
                break;
        }
        for (int i = 1; mid - i + 1 >= 1 && mid + i <= len; i++)
        {
            int l = mid - i + 1, r = mid + i;
            if (str[l] == str[r])
                res = max(res, i * 2);
            else
                break;
        }
    }
    return res;
}
int ans = 0;
void dfs(int step, int al, int bl)
{
    if (step > lenA + lenB)
    {
        // printf("%s\n", strC + 1);
        ans = max(ans, getRevLen(strC, lenA + lenB));
        return;
    }
    if (al <= lenA)
    {
        strC[step] = strA[al];
        dfs(step + 1, al + 1, bl);
    }
    if (bl <= lenB)
    {
        strC[step] = strB[bl];
        dfs(step + 1, al, bl + 1);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%s %s", strA + 1, strB + 1);
        lenA = strlen(strA + 1), lenB = strlen(strB + 1);
        strC[lenA + lenB + 1] = '\0';
        dfs(1, 1, 1);
        printf("%d\n", ans);
    }

    return 0;
}