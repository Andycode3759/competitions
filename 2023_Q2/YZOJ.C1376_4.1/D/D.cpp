// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = (1 << 30) - 1;

int n;
struct Card
{
    Card(int _f, int _b)
    {
        front = max(_f, _b);
        back = min(_f, _b);
    }
    int front, back;
    
    int getSum()
    {
    	return front + back;
	}
};
struct CardCmp
{
	CardCmp(int _m)
	{
		mode = _m;
	}
	
	int mode = 1;
    bool operator()(Card a, Card b)
    {
    	switch (mode)
    	{
    		case 1: return a.front > b.front;
    		case 2: return a.getSum() < b.getSum();
		}
		return false;
    }
};
vector<Card> cards;

int states[MAXN];
bool visited[MAXN];
int ans = -INF;
int force(int step) // 20%
{
    if (step > n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int s = states[i];
            int num = s > 0 ? cards[s].front : cards[-s].back;
            if (i % 2 == 0)
                num = -num;
            sum += num;
        }
        ans = max(ans, sum);
        return ans;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        for (int f = 0; f <= 1; f++)
        {
            visited[i] = true;
            states[step] = (f == 0) ? i : -i;
            force(step + 1);
            visited[i] = false;
        }
    }
    return ans;
}

bool mark[MAXN];
int trueAns()
{
	int sum = 0;
    sort(cards.begin(), cards.end(), CardCmp(1));
    for (int i = 0; i < n; i++)
    {
    	sum += cards[i].front;
	}
	sort(cards.begin(), cards.end(), CardCmp(2));
	for (int i = 0; i < (n >> 1); i++)
	{
		sum -= cards[i].getSum();
	}
	return sum;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int f, b;
        scanf("%d%d", &f, &b);
        cards.push_back(Card(f, b));
    }

    // printf("%d\n", force(1));
    // printf("%d\n", getMaxProd(n, 0));
    printf("%d\n", trueAns());
    return 0;
}
