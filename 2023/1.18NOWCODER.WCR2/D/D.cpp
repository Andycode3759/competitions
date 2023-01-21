// WA
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int energy[MAXN];
int layerOf[MAXN];
vector<int> childOf[MAXN];
 
void updateLayer(int node)
{
    vector<int> &children = childOf[node];
    for (int i = 0; i < children.size(); i++)
    {
        layerOf[children[i]] = layerOf[node] + 1;
        updateLayer(children[i]);
    }
}
 
int main()
{
    layerOf[1] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int input;
        scanf("%d", &input);
        childOf[input].push_back(i);
    }
    updateLayer(1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &energy[i]);
    }
    sort(energy + 1, energy + 1 + n);
    sort(layerOf + 1, layerOf + 1 + n);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += energy[i] * layerOf[i];
    }
    printf("%lld\n", ans);
    return 0;
}