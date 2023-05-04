// Score: 41/100
// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
// bool input[]

struct Node
{
    char input[MAXN];
    bool output;
} nodes[MAXN];

vector<int> digit1Idx[MAXN], digit0Idx[MAXN];
// digitIdx[i] => 第i位输入为1的node索引列表

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int t;
            scanf("%s%d", nodes[i].input, &t);
            nodes[i].output = t == 1;
            for (int j = 0; j < n; j++)
            {
                if (nodes[i].input[j] == '0')
                {
                    digit0Idx[j].push_back(i);
                }
                else
                {
                    digit1Idx[j].push_back(i);
                }
            }
        }

        bool isOK = false;
        for (int i = 0; i < n; i++)
        {

            // printf("now digit %d\n",i);

            // 第i位输入为0时所有的输出是否相同
            bool isFirst = true;
            bool mem = false;
            bool nowOK = false, success = true;

            // printf("checking input 0s\n");

            if (digit0Idx[i].empty())
                goto skipped_0;
            for (int j = 0; j < digit0Idx[i].size(); j++)
            {
                int idx = digit0Idx[i][j];

                // printf("selected node, input=%s, output=%d\n",nodes[idx].input,nodes[idx].output);

                if (isFirst || mem == nodes[idx].output)
                {
                    isFirst = false;
                    mem = nodes[idx].output;
                    continue;
                }
                else
                {
                    success = false;
                    break;
                }
            }
            nowOK = nowOK || success;

        skipped_0:
            // 第i位输入为1时所有的输出是否相同
            isFirst = true;
            mem = false;
            success = true;

            // printf("checking input 1s\n");

            if (digit1Idx[i].empty())
                goto skipped_1;
            for (int j = 0; j < digit1Idx[i].size(); j++)
            {
                int idx = digit1Idx[i][j];

                // printf("selected node, input=%s, output=%d\n",nodes[idx].input,nodes[idx].output);

                if (isFirst || mem == nodes[idx].output)
                {
                    isFirst = false;
                    mem = nodes[idx].output;
                    continue;
                }
                else
                {
                    success = false;
                    break;
                }
            }
            nowOK = nowOK || success;

        skipped_1:
            if (nowOK)
            {
                isOK = true;
                break;
            }
        }
        printf(isOK ? "OK\n" : "LIE\n");

        for (int i = 0; i < n; i++)
        {
            digit0Idx[i].clear();
            digit1Idx[i].clear();
        }
    }
    return 0;
}
/*
 * for(i=0;i<n;i++)
 * {
 * 		(第i位输入为0时所有的输出相同||第i位输入为1时所有的输出相同)
 * 		|| (input[i-1]为0时所有的输出相同||input[i-1]为1时所有的输出相同)
 * }
 */
