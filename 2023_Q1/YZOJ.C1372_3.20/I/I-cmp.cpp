#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int force()
{
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % c == 0)
            ans++;
    }
    return ans;
}

int trueAns()
{
    int ac = ceil(a * 1.0 / c) * c, bc = floor(b * 1.0 / c) * c;
    return (bc - ac) / c + 1;
}

int randBtw(int a, int b)
{
    int range = b - a + 1;
    return rand() % range + a;
}

int main()
{
    srand(time(0));
    // scanf("%d%d%d", &a, &b, &c);
    //  int ans = force();
    // int ans = trueAns();
    // printf("%d\n", ans);

    int stgA, stgC;
    // printf("Input data strength: ");
    scanf("%d%d", &stgA, &stgC);

    int rnd;
    // printf("Input rounds: ");
    scanf("%d", &rnd);
    printf("\n");

    vector<int> issues;

    printf("# Compare\n");
    for (int r = 1; r <= rnd; r++)
    {
        printf("----\n## Round #%d\n", r);
        a = randBtw(-stgA, stgA);
        do
            b = randBtw(-stgA, stgA);
        while (b <= a);
        c = randBtw(1, stgC);
        int f = force(), t = trueAns();
        printf("Input:\n\n```\n%d %d\n%d\n```\n\n", a, b, c);
        printf("- trueAns: `%d`\n", t);
        printf("- force: `%d`\n\n", f);
        printf(t == f ? "Correct\n\n" : "***!! Issue***\n\n");
        if (t != f)
            issues.push_back(r);
    }

    printf("----\n\n# Summary\n\nIssues Found: %ld/%d\n", issues.size(), rnd);
    printf("\nIssues List:\n");
    for (int i = 0; i < issues.size(); i++)
    {
        printf("- [#%d](#round-#%d)\n", issues[i], issues[i]);
    }

    return 0;
}
