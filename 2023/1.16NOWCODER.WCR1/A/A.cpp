// AC
#include <bits/stdc++.h>
using namespace std;
const int ROUNDS = 10;
char goals[13];

int main()
{
    int K;
    scanf("%d", &K);
    while (K--)
    {
        scanf("%s", goals);
        int scrA = 0, scrB = 0;
        bool finale = true;
        int rndRemainA = 5, rndRemainB = 5;
        for (int i = 0; i < ROUNDS; i++)
        {
            if (i % 2 == 0) // A
            {
                scrA += goals[i] - '0';
                rndRemainA--;
            }
            else // B
            {
                scrB += goals[i] - '0';
                rndRemainB--;
            }
            if (scrA - scrB > rndRemainB || scrB - scrA > rndRemainA)
            {
                printf("%d\n", i + 1);
                finale = false;
                break;
            }
        }
        if (finale)
        {
            if (scrA == scrB)
            {
                printf("-1\n");
            }
            else
            {
                printf("10\n");
            }
        }
    }
    return 0;
}