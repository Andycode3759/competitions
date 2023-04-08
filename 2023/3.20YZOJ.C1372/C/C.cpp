// Unfinished
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 103;

vector<int> childOf[MAXN];

string input;

void dfs(int u)
{
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            vector<int>().swap(childOf[i]);
        }
        getline(cin, input);
        int i, father;
        bool first = true;
        while (sscanf(input.c_str(), "%d", &i) == 1)
        {
            if (first)
            {
                father = i;
                first = false;
            }
            else
            {
                childOf[father].push_back(i);
                childOf[i].push_back(father);
            }
        }

        dfs(1);
    }
    return 0;
}
