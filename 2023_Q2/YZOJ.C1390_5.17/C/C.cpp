// AC
#include <cmath>
#include <cstdio>
using namespace std;
const double EPS = 1e-9;

double m, a, u;

int main()
{
    while (scanf("%lf%lf%lf", &m, &a, &u) == 3)
    {
        a = a * M_PI / 180.0;
        printf((u * sin(a) - cos(a)) >= EPS ? "Niubi!\n" : "What a pity!\n");
    }
    return 0;
}
