// WA
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
deque<int> order;

int main()
{
    auto print = [](const int &n) { printf("%d ", n); };
    int n;
    scanf("%d", &n);
    int trigger = 0;
    for (int i = n; i >= 1; i--)
    {
        if (i == 1 && n % 2 == 1)
            trigger = (trigger + 2) % 4;
        switch (trigger)
        {
        case 0:
            order.push_front(i);
            break;
        case 1:
            order.push_back(i);
            break;
        case 2:
            order.push_back(i);
            break;
        case 3:
            order.push_front(i);
            break;

        default:
            break;
        }
        trigger = (trigger + 1) % 4;
    }
    deque<int> orderCopy = order;
    while (orderCopy.size() > 1)
    {
        deque<int> t = orderCopy;
        orderCopy.clear();
        for (deque<int>::iterator i = t.begin() + 1; i != t.end(); i++)
        {
            orderCopy.push_back(((long long)(*i) + (long long)(*(i - 1))) % MOD);
        }
    }
    printf("%d\n", orderCopy.front());
    for_each(order.begin(), order.end(), print);
    printf("\n");
    return 0;
}
