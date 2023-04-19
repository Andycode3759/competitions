// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

struct Record
{
    int num;
    char name[10];
    int score;

    void print()
    {
        printf("%.6d %s %d\n", num, name, score);
    }
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
        int t;
        switch (mode)
        {
        case 1: // 学号
            return a.num < b.num;
            break;
        case 2: // 姓名
            t = strcmp(a.name, b.name);
            if (t == 0)
                return a.num < b.num;
            else
                return t < 0;
            break;
        case 3: // 成绩
            if (a.score == b.score)
                return a.num < b.num;
            return a.score < b.score;
            break;
        }
        return true;
    }
};

Record records[MAXN];
int n, c;

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%d", &records[i].num, records[i].name, &records[i].score);
    }
    sort(records, records + n, RecordCmp(c));
    for (int i = 0; i < n; i++)
    {
        records[i].print();
    }
    return 0;
}
