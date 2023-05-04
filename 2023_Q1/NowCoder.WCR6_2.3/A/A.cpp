// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    if (x > 1919810)
    {
        printf("can not imagine\n");
        return 0;
    }
    if (x > 114514)
    {
        printf("very hard\n");
        return 0;
    }
    if (x > 10032)
    {
        printf("hard\n");
        return 0;
    }
    if (x > 233)
    {
        printf("medium\n");
        return 0;
    }
    if (x > 7)
    {
        printf("easy\n");
        return 0;
    }
    printf("very easy\n");
    return 0;
}
