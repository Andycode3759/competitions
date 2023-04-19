#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;

int main()
{
    scanf("%d%d", &n, &m);
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        nums.push_back(x);
    }
    // partial_sort(nums.begin(), nums.begin() + m, nums.end(), greater<int>());
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < m; i++)
    {
        printf("%lld ", nums[i]);
    }
    printf("\n");
    return 0;
}
