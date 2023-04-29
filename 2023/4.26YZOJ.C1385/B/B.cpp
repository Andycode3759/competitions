#include <bits/stdc++.h>
using namespace std;

int n;

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y)
    {
    }
    const bool operator==(const Point &a) const
    {
        return x == a.x && y == a.y;
    }
};
struct PointYCmp
{
    bool operator()(const Point &a, const Point &b)
    {
        return a.y < b.y;
    }
};

vector<Point> canvas;

int findCut(int start, int end, const Point &base)
{
    int j = end - 1;
    int i = start;
    while (i != j)
    {
        while (base.x < canvas[j].x && i != j)
            j--;
        while (canvas[i].x <= base.x && i != j)
            i++;
        swap(canvas[i], canvas[j]);
    }
    return i;
}

void add(Point a)
{
    canvas.push_back(a);
}
void remove(Point a)
{
    for (int i = 0; i < canvas.size(); i++)
    {
        if (canvas[i] == a)
        {
            canvas.erase(canvas.begin() + i);
            return;
        }
    }
}
Point find(Point a)
{
    int i = findCut(0, canvas.size(), Point(a.x, a.y));
    if (i == 0)
    {
        if (canvas[0].x > a.x)
            i--;
    }
    if (i == canvas.size() - 1)
        return Point(-1, -1);
    sort(canvas.begin() + i + 1, canvas.end(), PointYCmp());

    // printf("--i=%d--\n", i);
    // for (int i = 0; i < canvas.size(); i++)
    // {
    //     printf("%d %d\n", canvas[i].x, canvas[i].y);
    // }
    // printf("----\n");

    auto u = lower_bound(canvas.begin() + i + 1, canvas.end(), Point(0, a.y + 1), PointYCmp());
    if (u == canvas.end())
        return Point(-1, -1);
    else
        return *u;

    // return Point(i, 0);
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
