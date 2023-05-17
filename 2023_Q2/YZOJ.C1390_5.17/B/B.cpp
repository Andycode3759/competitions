// RE
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 103;
const double EPS = 1e-9;

bool dbEqual(double a, double b)
{
    return abs(a - b) <= EPS;
}

struct Rectangle
{
    double lx, ly, rx, ry;

    const bool operator<(const Rectangle &a) const
    {
        return dbEqual(lx, a.lx) ? rx < a.rx : lx < a.lx;
    }
};
Rectangle rect[MAXN];

int n;
vector<double> x;
vector<int> recx[MAXN]; // 在x属于i到i+1这一区间内的所有矩形

bool cmpRecx(int a, int b)
{
    Rectangle &ra = rect[a], &rb = rect[b];
    return dbEqual(ra.ry, rb.ry) ? ra.ly < rb.ly : ra.ry < rb.ry;
}

double getHeight(int idx)
{
    double fl = -1, cl = -1;
    double res = 0;
    vector<int> &rx = recx[idx];
    sort(rx.begin(), rx.end(), cmpRecx);
    for (int i = 0; i < rx.size(); i++)
    {
        Rectangle &r = rect[rx[i]];
        if (r.ly >= fl && r.ry <= cl) // 全包含
        {
            continue;
        }
        else if (r.ly > fl && r.ly < cl) // 部分包含
        {
            res += r.ry - cl;
            cl = r.ry;
        }
        else // 不包含
        {
            res += r.ry - r.ly;
            fl = r.ly, cl = r.ry;
        }
    }
    return res;
}

int main()
{
    int T = 1;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int>().swap(recx[i]);
        }
        vector<double>().swap(x);

        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &rect[i].lx, &rect[i].ly, &rect[i].rx, &rect[i].ry);
            x.push_back(rect[i].lx), x.push_back(rect[i].rx);
        }
        sort(rect, rect + n);
        sort(x.begin(), x.end());
        unique(x.begin(), x.end(), dbEqual);
        for (int i = 0; i < x.size() - 1; i++)
        {
            double fl = x[i], cl = x[i + 1];
            for (int j = 0; j < n; j++)
            {
                Rectangle &r = rect[j];
                if (r.lx <= fl && r.rx >= cl)
                {
                    recx[i].push_back(j);
                }
            }
        }
        // for (int i = 0; i < x.size() - 1; i++)
        // {
        //     printf("%lf ~ %lf: ", x[i], x[i + 1]);
        //     for (int j = 0; j < recx[i].size(); j++)
        //     {
        //         printf("(%lf,%lf,%lf,%lf) ", rect[recx[i][j]].lx, rect[recx[i][j]].ly, rect[recx[i][j]].rx,
        //                rect[recx[i][j]].ry);
        //     }
        //     printf("\n");
        // }
        double ans = 0;
        for (int i = 0; i < x.size() - 1; i++)
        {
            ans += getHeight(i) * (x[i + 1] - x[i]);
        }
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2lf\n", ans);
    }
    return 0;
}
