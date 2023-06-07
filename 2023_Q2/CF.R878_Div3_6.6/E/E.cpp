#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
const int MAXN = 200005;
const int HP = 27;

char str1[MAXN],str2[MAXN];
int block[MAXN]; // time to start block char
int tt; // now time
int t,q;

unsigned long long getHash(char* str)
{
    unsigned long long res=0;
    for(int i=1;*str>='a'&&*str<='z';str++,i++)
    {
        if(block[i]==-1 || block[i]+t-1<tt)
        {
            res=res*HP+(*str)-'a'+1;
        }
        else
        {
            res*=HP;
//            printf("char %d is blocked\n",i);
        }
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(block,-1,sizeof(block));
        tt=0;
        scanf("%s",str1+1);
        scanf("%s",str2+1);
        scanf("%d%d",&t,&q);
        int op,s1,p1,s2,p2,p;
        char *st1,*st2;
        while(q--)
        {
            tt++;
            scanf("%d",&op);
            switch(op)
            {
                case 1:
                    scanf("%d",&p);
                    block[p]=tt;
//                    printf("blocked %d\n",p);
                    break;
                case 2:
                    scanf("%d%d%d%d",&s1,&p1,&s2,&p2);
                    st1=(s1==1)?str1:str2;
                    st2=(s2==1)?str1:str2;
                    swap(st1[p1],st2[p2]);
//                    printf("swapped\ns1=%s\ns2=%s\n",str1+1,str2+1);
                    break;
                case 3:
                    printf(getHash(str1+1)==getHash(str2+1)?"YES\n":"NO\n");
                    break;
            }
        }
    }
    return 0;
}
