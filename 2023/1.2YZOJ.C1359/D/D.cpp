// ACCEPTED
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> piles;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        piles.push(input);
    }
    int ans = 0;
    while (piles.size() > 1)
    {
        int t1 = piles.top();
        piles.pop();
        int t2 = piles.top();
        piles.pop();
        ans += t1 + t2;
        piles.push(t1 + t2);
    }
    printf("%d\n", ans);
    return 0;
}
