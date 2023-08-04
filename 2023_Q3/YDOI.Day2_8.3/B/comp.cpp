#include <ctime>
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

    int n;
    printf("Input n: ");
    scanf("%d",&n);
    FILE *inFile = fopen("input.txt","w");
    fprintf(inFile,"%d\n",n);
    for(int i=1;i<=n;i++)
    {
        fprintf(inFile,"%d ",randInt(1,n));
    }

    printf("Run std...\n");
    system("g++ -O2 B.cpp -o std.bin");
    long startTime=clock();
    system("./std.bin <input.txt >output-std.txt");
    printf("Time: %.3fs\n",(1.0*clock()-startTime)/CLOCKS_PER_SEC);
    printf("Run force...\n");
    system("g++ -O2 B-force.cpp -o force.bin");
    startTime=clock();
    system("./force.bin <input.txt >output-force.txt");
    printf("Time: %.3fs\n",(1.0*clock()-startTime)/CLOCKS_PER_SEC);
    printf("Compare...\n");
    int res=system("diff output-std.txt output-force.txt");
    if(res==0) printf("OK\n");
    else printf("Wrong Answer!\n");

    return 0;
}
