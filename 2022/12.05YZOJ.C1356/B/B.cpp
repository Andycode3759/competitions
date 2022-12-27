//UNFINISHED
#include <bits/stdc++.h>
using namespace std;

struct BigNum
{
    vector<long long> digits;

    void Multiply(long long b)
    {
        int len = digits.size() + b.digits.size();
        vector<long long> newDigits;
        for (int i = 0; i < len; i++)
        {
            newDigits.push_back(0);
        }
        for (int pa = 0; pa < digits.size(); pa++)
        {
            for (int pb = 0; pb < b.digits.size(); pb++)
            {
                newDigits[pa + pb] += digits[pa] * digits[pb];
            }
        }
        for (int i = 0; i < len; i++)
        {
            if (newDigits[i] >= 10)
            {
                newDigits[i + 1] += newDigits[i] / 10;
                newDigits[i] %= 10;
            }
        }
        BigNum res;
        res.digits = newDigits;
        for (vector<long long>::iterator i = newDigits.end();; i--)
        {
            if (*i == 0)
            {
                newDigits.pop_back();
            }
            else
            {
                break;
            }
        }
        digits = newDigits;
    }
};

int main()
{
    int n;
    long long k;
    scanf("%d", &n);
    BigNum a, b;
    for (k = 1; b.digits.size() < n; k++)
    {
        b.digits.clear();
        b.digits.push_back(1);
        for (long long i = 0; i < k; i++)
        {
            a.digits.clear();
            a.digits.push_back(k);
            b = b * a;
        }
    }
    printf("%lld\n", k);
    return 0;
}
