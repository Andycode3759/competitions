#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

struct Record
{
    int num;
    char name[10];
    int score;
};
struct RecordCmp
{
    int mode = 0;

    RecordCmp(int _m)
    {
        mode = _m;
    }

    bool operator()(Record a, Record b)
    {
        switch (mode)
        {
        case 1:
            return a.num < b.num;
        case 2:
            int t = strcmp(a.name, b.name);
        case 3:
            return a.score < b.score;
            break;
        }
    }
};

Record r[MAXN];
int n, c;

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%d", &r[i].num, &r[i].name, &r[i].score);
    }
    return 0;
}
