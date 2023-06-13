// AC
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> Q;
int n;

int main()
{
    scanf("%d", &n);
    int input;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        Q.push(input);
    }
    long long res = 0;
    for (int i = 1; i < n; i++)
    {
        int sum = Q.top();
        Q.pop();
        sum += Q.top();
        Q.pop();
        res += sum;
        Q.push(sum);
    }
    printf("%lld\n", res);

    return 0;
}
