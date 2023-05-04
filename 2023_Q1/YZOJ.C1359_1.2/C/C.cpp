// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

struct Msg
{
    char content[15];
    int priority;

    bool operator<(const Msg &another) const
    {
        return priority > another.priority;
    }
};
priority_queue<Msg> msgQueue;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char op[4];
        scanf("%s", op);
        if (strcmp(op, "PUT") == 0)
        {
            Msg m;
            scanf("%s%d", m.content, &m.priority);
            msgQueue.push(m);
        }
        if (strcmp(op, "GET") == 0)
        {
            if (msgQueue.empty())
            {
                printf("EMPTY QUEUE!\n");
            }
            else
            {
                printf("%s\n", msgQueue.top().content);
                msgQueue.pop();
            }
        }
    }
    return 0;
}
