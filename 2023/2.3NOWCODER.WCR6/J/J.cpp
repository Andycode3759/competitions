// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 4;
map<string, long long> sitePro;
map<string, long long> siteRank;

long long result[MAXN];

struct Event
{
    int index;
    int type;
    int time;
    string name;
    int w;
};
struct Task
{
    int time;
    bool isEveryone;
    string name;

    Task(int _t, bool everyone, string _n)
    {
        time = _t;
        isEveryone = everyone;
        name = _n;
    }
};

struct EventCmp
{
    bool operator()(Event a, Event b)
    {
        return a.time > b.time;
    }
};
struct TaskCmp
{
    bool operator()(Task a, Task b)
    {
        return a.time > b.time;
    }
};

priority_queue<Event, vector<Event>, EventCmp> events;
priority_queue<Task, vector<Task>, TaskCmp> tasks;

int main()
{
    int n, T, R;
    scanf("%d%d%d", &n, &T, &R);
    int nowInd = 0;
    for (int i = 0; i < n; i++)
    {
        Event e;
        e.w = -1;
        scanf("%d%d", &e.type, &e.time);
        cin >> e.name;
        if (e.type == 2)
        {
            scanf("%d", &e.w);
        }
        else
        {
            e.index = nowInd++;
        }
        events.push(e);
    }
    tasks.push(Task(T, true, ""));
    for (int nowTime = 0; !events.empty(); nowTime++)
    {
        // task handle

        while (tasks.top().time == nowTime)
        {
            Task t = tasks.top();

            // printf("[%d] task: %d %s\n", t.time, t.isEveryone, t.name.c_str());

            tasks.pop();
            if (t.isEveryone)
            {
                for (map<string, long long>::iterator i = sitePro.begin(); i != sitePro.end(); i++)
                {
                    siteRank[i->first] = sitePro.count(i->first) == 1 ? sitePro[i->first] : 0;
                }
                tasks.push(Task(nowTime + T, true, ""));
            }
            else
            {
                siteRank[t.name] = sitePro.count(t.name) == 1 ? sitePro[t.name] : 0;
            }
        }

        // event handle
        if (events.top().time == nowTime)
        {
            Event e = events.top();

            // printf("[%d] event #%d: %d %s %d\n", e.time, e.type == 1 ? e.index : -1, e.type, e.name.c_str(), e.w);

            events.pop();
            if (e.type == 1)
            {
                long long res = siteRank.count(e.name) == 1 ? siteRank[e.name] : 0;
                tasks.push(Task(nowTime + R, false, e.name));
                result[e.index] = res;
            }
            else
            {
                sitePro[e.name] = sitePro.count(e.name) == 1 ? sitePro[e.name] + e.w : e.w;
            }
        }
    }
    for (int i = 0; i < nowInd; i++)
    {
        printf("%lld\n", result[i]);
    }

    return 0;
}
