// AC
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

// 储存元素序列
char seq[MAXN];
// possible[i][j][x]表示：从i到j的区间能否形成元素x（x的值0为X,1为Y,2为Z），储存值为-1表示未知，0表示否，1表示是
int possible[MAXN][MAXN][3];

// 记忆化搜索+递归，求出possible[left][right][element]的值并返回
bool isPossibleToForm(int left, int right, char element)
{
    // 记忆化搜索模板
    if (possible[left][right][element - 'X'] >= 0)
        return possible[left][right][element - 'X'];
    int &ans = possible[left][right][element - 'X']; // 利用引用简化代码

    if (left == right) // 区间指向单个位置，那么唯一能“合成”的元素自然就是序列中此位置的元素本身
        return ans = (seq[left] == element);

    // 区间切分
    for (int k = left; k < right; k++)
    {
        switch (element)
        // 根据反应物的所有可能搭配查表，记得反应物表是左右对称的，因此左右区间的对应的反应物交换位置后依然可行
        {
        case 'X':
            if (isPossibleToForm(left, k, 'X') && isPossibleToForm(k + 1, right, 'Y') ||
                isPossibleToForm(left, k, 'Y') && isPossibleToForm(k + 1, right, 'X') ||
                isPossibleToForm(left, k, 'Z') && isPossibleToForm(k + 1, right, 'Z'))
                return ans = true;
            break;
        case 'Y':
            if (isPossibleToForm(left, k, 'X') && isPossibleToForm(k + 1, right, 'X') ||
                isPossibleToForm(left, k, 'Y') && isPossibleToForm(k + 1, right, 'Y') ||
                isPossibleToForm(left, k, 'Y') && isPossibleToForm(k + 1, right, 'Z') ||
                isPossibleToForm(left, k, 'Z') && isPossibleToForm(k + 1, right, 'Y'))
                return ans = true;
            break;
        case 'Z':
            if (isPossibleToForm(left, k, 'X') && isPossibleToForm(k + 1, right, 'Z') ||
                isPossibleToForm(left, k, 'Z') && isPossibleToForm(k + 1, right, 'X'))
                return ans = true;
            break;
        }
    }
    // 所有可能的区间切分都不可行（在查表过程中没有返回），返回false
    return ans = false;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        // 注意多组数据需重置数组
        memset(possible, -1, sizeof(possible));
        scanf("%s", seq + 1);
        int len = strlen(seq + 1); // 序列的长度是未知的，需要自己获取

        // 从重到轻依次枚举产物
        if (isPossibleToForm(1, len, 'Z'))
        {
            printf("Z\n");
        }
        else if (isPossibleToForm(1, len, 'Y'))
        {
            printf("Y\n");
        }
        else // Z和Y都不行那自然只剩X了，可以直接输出
        {
            printf("X\n");
        }
    }
    return 0;
}
