// Score: 50/100
// TLE
#include <bits/stdc++.h>
using namespace std;
const int MAXT = 1e6 + 6;
const int MAXW = 1e4 + 4;
const int BASE = 31;
char word[MAXW], text[MAXT];
int lenw, lent;

unsigned long long doHash(char *str, int len)
{
    unsigned long long hash = 0;
    for (int i = 0; i < len; i++)
    {
        hash = hash * BASE + *(str + i) - 'A' + 1;
    }
    return hash;
}

bool myStrcmp(char *a, char *b, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(a + i) != *(b + i))
            return false;
    }
    return true;
}

void read(char *str)
{
    char *s = str;
    char c;
    do
        c = getchar();
    while (c < 'A' || c > 'Z');
    while (c >= 'A' && c <= 'Z')
    {
        *s = c;
        c = getchar();
        s++;
    }
    *s = '\0';
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int ans = 0;
        read(word), read(text);
        // printf("%s\n%s\n", word, text);
        lenw = strlen(word), lent = strlen(text);
        unsigned long long wordHash = doHash(word, lenw);
        int p = lent - lenw;
        for (int i = 0; i <= p; i++)
        {
            char *sub = text + i;
            unsigned long long h = doHash(sub, lenw);
            if (h != wordHash)
                continue;

            if (myStrcmp(sub, word, lenw))
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}