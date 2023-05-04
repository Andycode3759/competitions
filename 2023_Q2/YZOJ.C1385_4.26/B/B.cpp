// AC
// Fixed: 2023/4/29
#include <cstdio>
#include <set>
using namespace std;

int n;

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y)
    {
    }
    const bool operator<(const Point &a) const
    {
        return x == a.x ? y < a.y : x < a.x;
    }
};

set<Point> points;
typedef set<Point>::iterator iter;

void add(Point a)
{
    points.insert(a);
}
void remove(Point a)
{
    points.erase(a);
}
Point find(Point a)
{
    iter i;
    a.x++;
    for (;;)
    {
        iter p = points.lower_bound(Point(a.x, a.y + 1));
        if (p == points.end())
            return Point(-1, -1);

        iter cur = p;
        i = points.lower_bound(Point(cur->x, a.y + 1));
        if (i == points.end())
            return Point(-1, -1);
        cur = i;
        if (cur->y >= a.y + 1)
            return *cur;
        a.x = cur->x;
    }
}

int main()
{
    scanf("%d", &n);
    char input[8];
    Point p(0, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d", input, &p.x, &p.y);
        switch (input[0])
        {
        case 'a': // add
            add(p);
            break;
        case 'r': // remove
            remove(p);
            break;
        case 'f': // find
            Point a = find(p);
            if (a.x <= -1)
                printf("-1\n");
            else
                printf("%d %d\n", a.x, a.y);
            break;
        }
    }

    return 0;
}
