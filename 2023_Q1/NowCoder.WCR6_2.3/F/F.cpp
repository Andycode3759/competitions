// TLE
#include <bits/stdc++.h>
using namespace std;
priority_queue<int> arr;
const int MAXQ = 2e5 + 5;
int finalResult[MAXQ];

struct Query
{
    int content;
    int index;

    Query(int _c, int _i)
    {
        content = _c;
        index = _i;
    }
};
struct QueryCmp
{
    bool operator()(Query a, Query b)
    {
        return a.content > b.content;
    }
};

priority_queue<Query, vector<Query>, QueryCmp> queries;
const int cache[256] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
int getWeight(int num)
{
    int ans = 0;
    while (num > 0)
    {
        ans += cache[num & 255];
        num = num >> 8;
    }
    return ans;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        arr.push(input);
    }
    for (int i = 0; i < q; i++)
    {
        int input;
        scanf("%d", &input);
        queries.push(Query(input, i));
    }
    int nowOp = 0;
    while (!queries.empty())
    {
        Query query = queries.top();

        // printf("query: #%d, c=%d\n", query.index, query.content);

        queries.pop();
        while (nowOp < query.content)
        {
            int w = getWeight(arr.top());
            arr.pop();
            arr.push(w);
            nowOp++;
        }

        // printf("nowOp=%d\n", nowOp);

        finalResult[query.index] = arr.top();
    }
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", finalResult[i]);
    }
    return 0;
}
