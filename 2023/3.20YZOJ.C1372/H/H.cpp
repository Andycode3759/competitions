// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 26;
int arr[MAXN];
int n;

long long suma, sumb;

bool force(int step)
{
    if (step == n)
    {
        return suma == sumb;
    }
    bool res = false;

    suma += arr[step];
    res = res || force(step + 1);
    suma -= arr[step];

    sumb += arr[step];
    res = res || force(step + 1);
    sumb -= arr[step];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    printf(force(0) ? "Matched\n" : "No\n");
    return 0;
}