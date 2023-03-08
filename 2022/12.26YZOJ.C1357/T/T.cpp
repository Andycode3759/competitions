// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
struct Activity
{
    int start, end;
};
Activity activities[MAXN];

bool cmp(Activity a, Activity b)
{
    return a.end < b.end;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &activities[i].start, &activities[i].end);
    }
    sort(activities, activities + n, cmp);

    //   for(int i=0;i<n;i++)
    //   {
    //     printf("%d %d\n",activities[i].start,activities[i].end);
    //   }

    int ans = 0, nowLast = -1;
    for (int i = 0; i < n; i++)
    {
        if (activities[i].start >= nowLast)
        {
            ans++;
            nowLast = activities[i].end;
        }
    }
    printf("%d\n", ans);
    return 0;
}
