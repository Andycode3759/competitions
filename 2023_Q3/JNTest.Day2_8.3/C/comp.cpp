#include <cstdio>
#include <cstdlib>
using namespace std;

int randInt(int l,int r)
{
    return rand()%(r-l+1)+l;
}

int main()
{
    unsigned int seed;
    printf("Input seed: ");
    scanf("%u",&seed);
    srand(seed);

    int n,q;
    printf("Input n,q: ");
    scanf("%d %d",&n,&q);
    FILE *inFile = fopen("input.txt","w");
    fprintf(inFile,"%d %d\n",n,q);
    for(int i=1;i<=n;i++)
    {
        fprintf(inFile,"%d ",randInt(1,n));
    }
    fprintf(inFile,"\n");
    for(int i=2;i<=n;i++)
    {
        int t=randInt(1,n);
        while(t==i) t=randInt(1,n);
        fprintf(inFile,"%d ",t);
    }
    fprintf(inFile,"\n");
    for(int i=1;i<=q;i++)
    {
        fprintf(inFile,"%d %d\n",randInt(1,n),randInt(1,n));
    }

    printf("Run std...\n");
    system("g++ -O2 C.cpp -o std.bin");
    system("./std.bin <input.txt >output-std.txt");
    printf("Run force...\n");
    system("g++ -O2 C-force.cpp -o force.bin");
    system("./force.bin <input.txt >output-force.txt");
    printf("Compare...\n");
    int res=system("diff output-std.txt output-force.txt");
    if(res==0) printf("OK\n");
    else printf("Wrong Answer!\n");

    return 0;
}
