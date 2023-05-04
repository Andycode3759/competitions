#include <bits/stdc++.h>
using namespace std;
const int MOD = 13;

int n;
deque<int> hand;

int force()
{
    for (int i = 1; i <= n; i++)
    {
        hand.push_back(i % MOD == 0 ? 13 : i % MOD);
    }
    for (int i = 1; i < n; i++)
    {
        int v = hand.front();
        hand.pop_front();
        hand.pop_front();
        hand.push_back(v);
    }
    return hand.front();
}

int main()
{
    scanf("%d", &n);
    int ans = force();
    printf("%d\n", ans);
    return 0;
}
