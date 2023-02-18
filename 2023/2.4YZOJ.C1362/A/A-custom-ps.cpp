// Unfinished
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

void customPartialSort(int *first, int *middle, int *last)
{
    size_t heapSize = middle - first;
    
}

int main()
{
    int k;
    while (scanf("%d", &k) == 1)
    {
        for (int i = 0; i < k; i++)
        {
            sum[i] = read();
        }
        for (int i = 1; i < k; i++)
        {
            memset(sum2, 0, sizeof(sum2));
            int index = 0;
            for (int j = 0; j < k; j++)
            {
                int input = read();
                for (int d = 0; d < k; d++)
                {
                    sum2[index++] = sum[d] + input;
                }
            }
            customPartialSort(sum2, sum2 + k, sum2 + index);
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
