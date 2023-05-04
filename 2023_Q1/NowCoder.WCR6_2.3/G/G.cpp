// AC
#include <bits/stdc++.h>
using namespace std;
deque<int> positive;
deque<int> negative;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        if (input < 0)
            negative.push_back(input);
        else
            positive.push_back(input);
    }
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (positive.size() == 1 && negative.size() == 1)
        {
            ans += positive.front() * negative.front();
        }
        int expectPst, expectNgt;
        expectPst = positive.size() == 0 ? 0 : *positive.begin() * (*(positive.begin() + 1));
        expectNgt = negative.size() == 0 ? 0 : *negative.begin() * (*(negative.begin() + 1));
        if (expectPst > expectNgt)
        {
            ans += expectPst;
            positive.pop_front();
            positive.pop_front();
        }
        else
        {
            ans += expectNgt;
            negative.pop_front();
            negative.pop_front();
        }
    }
    printf("%lld\n", ans);
    return 0;
}
