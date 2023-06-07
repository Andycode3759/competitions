// AC
#include <cstdio>
using namespace std;
const int MAXN = 105;

int n;
char str[MAXN],res[MAXN];
int rc;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",str);

        rc=0;
        char cur=1;
        for(int i=0;i<n;i++)
        {
            if(cur==1)
                cur=str[i];
            else
            {
                if(cur==str[i])
                {
                    res[rc++]=str[i];
                    cur=1;
                }
            }
        }
        res[rc]='\0';
        printf("%s\n",res);
    }
}
