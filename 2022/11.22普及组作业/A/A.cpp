/*
    Score: 90/100
    WA:    1/10 Case(s)
*/
#include<bits/stdc++.h>
using namespace std;

vector<long long> knownPrime;

bool isPrime(long long n)
{
    if(n<=1) return false;  
    for(int i=0;i<knownPrime.size();i++)
    {
        if(n==knownPrime[i]) return true;
        if(n%knownPrime[i]==0) return false;
    }
    knownPrime.push_back(n);
    return true;
}

int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=2;i<=n;i++)
    {
        if(isPrime(i)&&isPrime(i+2))
        {
            //printf("%lld %lld\n",i,i+2);
            cout << i << " " <<i+2 << endl;
            //i+=1;
        }
    }

    return 0;
}