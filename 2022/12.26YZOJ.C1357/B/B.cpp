// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
char sa[MAXN], sb[MAXN];
int numa[MAXN], numb[MAXN];

int main()
{
    scanf("%s %s", sa, sb);
    int la = strlen(sa), lb = strlen(sb);
    for (int i = la - 1; i >= 0; i--)
    {
        numa[la - i - 1] = sa[i] - '0';
    }
    for (int i = lb - 1; i >= 0; i--)
    {
        numb[lb - i - 1] = sb[i] - '0';
    }

    int *bigger = NULL, *smaller = NULL;
    if (la == lb)
    {
        for (int i = la - 1; i >= 0; i--)
        {
            if (numa[i] > numb[i])
            {
                bigger = numa, smaller = numb;
                break;
            }
            else if (numa[i] < numb[i])
            {
                bigger = numb, smaller = numa;
                break;
            }
        }
    }
    else
    {
        if (la > lb)
        {
            bigger = numa, smaller = numb;
        }
        else // la<lb
        {
            bigger = numb, smaller = numa;
        }
    }
    if (bigger == smaller)
    {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < MAXN - 1; i++)
    {
        *(bigger + i) -= *(smaller + i);
        if (*(bigger + i) < 0)
        {
            *(bigger + i + 1) = *(bigger + i + 1) - 1;
            *(bigger + i) += 10;
        }
    }

    if (bigger == numb)
        printf("-");
    bool flag = false;
    for (int i = MAXN - 1; i >= 0; i--)
    {
        if (*(bigger + i) > 0)
            flag = true;
        if (flag)
        {
            printf("%d", *(bigger + i));
        }
    }
    if (!flag)
        printf("0");
    printf("\n");

    return 0;
}
