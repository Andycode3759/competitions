//ACCEPTED
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
priority_queue<int> refCount;

bool cmpGreater(int a, int b)
{
    return a >= b;
}

int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int main()
{
    int K = read();
    while (K--)
    {
        priority_queue<int>().swap(refCount);
        int n = read();
        for (int i = 0; i < n; i++)
        {
            refCount.push(read());
        }
        long long h = 0;
        int paper = 0;
        while (!refCount.empty())
        {
            int r = refCount.top();
            refCount.pop();
            if (r == 0)
                break;
            if (r >= paper + 1)
            {
                paper++;
            }
            else
            {
                // printf("get h %d\n", paper);

                h += paper;
                paper = 1;
            }
        }
        h += paper;
        printf("%lld\n", h);
    }
    return 0;
}