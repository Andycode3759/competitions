#include <cstdio>
using namespace std;

int panel[12][22];

int n;

int main()
{
    scanf("%d",&n);
    for(int m=1;m<=n;m++)
    {
        int h,l;
        scanf("%d%d",&h,&l);
        int t=1;
        for(;t<=20&&panel[h][t]==0;t++) ;
        panel[h][t-1]=l;
        bool flag=false;
        do
        {
            flag=false;
            for(int j=1;j<=10;j++)
            {
                for(int i=20;i>1;i--)
                {
                    if(panel[j][i]>0 && panel[j][i]==panel[j][i-1])
                    {
                        panel[j][i]++;
                        flag=true;
                        for(int k=i-1;k>=1;k--) panel[j][k]=panel[j][k-1];
                        break;
                    }
                }
                if(flag) break;
            }

            if(flag) continue;

            for(int j=1;j<=9;j++)
            {
                for(int i=20;i>=1;i--)
                {
                    if(panel[j][i]>0 && panel[j][i]==panel[j+1][i])
                    {
                        panel[j][i]++;
                        flag=true;
                        for(int k=i;k>=1;k--) panel[j+1][k]=panel[j+1][k-1];
                        break;
                    }
                }
                if(flag) break;
            }
        } while (flag);

        // printf("%d h=%d l=%d\n",m,h,l);
        // for(int j=1;j<=20;j++)
        // {
        //     for(int i=1;i<=10;i++)
        //     {
        //         printf("%d ",panel[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }

    for(int j=1;j<=20;j++)
    {
        for(int i=1;i<=10;i++)
        {
            printf("%d ",panel[i][j]);
        }
        printf("\n");
    }
    return 0;
}
