// Score: 0/100
// MLE
// FXXK U C++ MEMORY MANAGEMENT
#include <bits/stdc++.h>
using namespace std;
const int BASE = 31;
const int MOD = 99991;

int doHash(string str)
{
    unsigned long long hash = 0;
    for (int i = 0; i < str.size(); i++)
    {
        hash = hash * BASE + str[i] - 'A' + 1;
    }
    return hash % MOD;
}

void solveCase(string word, string text)
{
    int ans = 0;
    vector<string> hashmap[MOD];
    int wordHash = doHash(word);
    int p = text.size() - word.size();
    for (int i = 0; i <= p; i++)
    {
        string sub = text.substr(i, word.size());
        int h = doHash(sub);

        // printf("%s ==hash=> %lld\n", sub.c_str(), h);

        hashmap[h].push_back(sub);
    }
    for (int i = 0; i < hashmap[wordHash].size(); i++)
    {
        if (word.compare(hashmap[wordHash][i]) == 0)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int kase;
    // ios::sync_with_stdio(false);
    scanf("%d", &kase);
    while (kase--)
    {
        string word, text;
        cin >> word >> text;
        solveCase(word, text);
    }
    return 0;
}