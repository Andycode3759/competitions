// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXK = 753;
int sum[MAXK];
int sum2[MAXK * MAXK];

int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int main()
{
    int k;
    while (scanf("%d", &k) == 1)
    {
        // memset(sum, 0, sizeof(sum));
        // vector<int>().swap(sum2);
        for (int i = 0; i < k; i++)
        {
            sum[i] = read();
            // scanf("%d", &sum[i]);
        }
        for (int i = 1; i < k; i++)
        {
            memset(sum2, 0, sizeof(sum2));
            // vector<int>().swap(sum2);
            int index = 0;
            for (int j = 0; j < k; j++)
            {
                int input = read();
                // scanf("%d", &input);
                for (int d = 0; d < k; d++)
                {
                    // sum2.push_back(sum[d] + input);
                    sum2[index++] = sum[d] + input;
                }
            }
            partial_sort(sum2, sum2 + k, sum2 + index);
            for (int j = 0; j < k; j++)
            {
                sum[j] = sum2[j];
            }
        }
        for (int i = 0; i < k; i++)
        {
            printf("%d ", sum[i]);
        }
        printf("\n");
    }
    return 0;
}
