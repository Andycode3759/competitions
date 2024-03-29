# 1.1 考试总结

## A - Cow College ([P8897@Luogu](https://www.luogu.com.cn/problem/P8897))

第一道题比较简单，但是一开始拿到题目时总想着用二分做，后面才意识到思路不对改用前缀和，过程中浪费了十多分钟。

## B - nana 吃蛋糕 ([H@牛客 2022 跨年场](https://ac.nowcoder.com/acm/contest/49343/H))

看道题第一反应是广搜，但是写出大概框架后才发现关于判重的部分实现非常复杂，于是开始纸笔模拟寻找另外的思路。大概画几幅图后发现了几点规律：

1. 首先能走的格子数量自然越多越好，就有机会吃到越多的蛋糕；
2. 如果 n 为奇数，则一定可以走过所有的格子，答案就是所有格子的蛋糕数量之和；
3. 如果 n 为偶数，则在某些走法中一定会少走一个格子。

没得满分的问题所在就在第三点，没有推导出哪些格子是走不到的。于是只好假设$(n, n-1), (n-1, n), (1, n), (n, 1)$四个点走不到（因为纸笔模拟的时候只推出来这四个点），提交代码后骗了 33 分。经过[@ASteepMountain](https://www.luogu.com.cn/user/766639)讲解后发现其实对于除终点和起点外的任意一点$P \in \{(x, y) | x \in [1, n], y \in [1, n]\} - \{(1, 1), (n, n)\}$，都存在一种走法，可以走过除了格子$P$外的其他所有格子，因此正确答案为 `cakeSum-min(cakes[x][y])` ，即所有格子蛋糕数量和减去蛋糕数量最少的格子的蛋糕数。

> 2023.1.2 20:01 订正：放弃的格子必须满足横纵坐标奇偶性不同。设一个点的性质$P$为其横纵坐标奇偶性是否相同（ `bool p(int x,int y){return x%2 == y%2}` ）；那么每走一步，当前点的性质$P$一定会变为$! P$。起点和终点的$P$一定都为$true$，这也就意味着从起点走到终点必须要走偶数次。如果 n 为偶数，除去起点以外一共要走奇数次，因此必定要放弃一个点。
>
> 将走的过程中当前点的$P$的变化列举出来：$(起)true \rightarrow false \rightarrow true \rightarrow false \rightarrow \cdots \rightarrow true(终) \rightarrow false(如果一定要走偶数次，则会多出一个点)$，从而可知多出来的那个点一定有$P=false$，即横纵坐标奇偶性不同。

## C - ygg 的分数运算 ([D@牛客 2022 跨年场](https://ac.nowcoder.com/acm/contest/49343/D))

这道题属于彻底不会做，关于乘法逆元和数论的知识全都没听懂（

其实只要对$c$进行质因数分解就可以了，因为$a, b$均为质数，那么$1 \over a$和$1 \over b$无论如何进行加法和乘法运算，得到的分母的质因数一定只有$a$和$b$。因此不断地从$c$中除以$a$或$b$，除出 1 说明可以，无法整除说明不行。

```cpp
int a, b, c;
while (c > 1 && (c % a == 0 || c % b == 0))
{
    if (c % a == 0)
        c /= a;
    if (c % b == 0)
        c /= b;
}
printf(c == 1 ? "YES\n" : "NO\n");
```

## D - 分赃 ([B@牛客 2022 跨年场](https://ac.nowcoder.com/acm/contest/49343/B))

首先数出所有数字出现的个数，然后根据个数分类讨论（下面用$(a, b)$的形式表示小沙快乐值$+a$，兰子快乐值$+b$）：

-   出现 1 次的数字：可能$(1, 0)$或$(0, 1)$；
-   出现 2 次的数字：可能$(1, 1)$或$(0, 0)$；
-   出现 3 次及以上的数字：可能$(1, 0)$，$(0, 1)$或$(0, 0)$。

第一思路是打暴力，用递归累加两人的快乐值，然后遍历每个出现的数字：

```cpp
const int MAXN = 1e5 + 5;
int maxNum;      // 出现过的最大数字
int count[MAXN]; // 数字出现的个数
bool dfs(int num, int xs, int lz)
{
    if (num > maxNum) // 所有数字枚举完毕
    {
        return xs == lz;
    }
    switch (count[num])
    {
    case 0:
        return dfs(num + 1, xs, lz); // 没出现的数，跳到下一个
    case 1:
        return dfs(num + 1, xs + 1, lz) || dfs(num + 1, xs, lz + 1); // 往下枚举两种分法的分支，有一条可行那么当前的分法就可行
    case 2:
        return dfs(num + 1, xs, lz) || dfs(num + 1, xs + 1, lz + 1);
    default:
        return dfs(num + 1, xs + 1, lz) || dfs(num + 1, xs, lz + 1) || dfs(num + 1, xs, lz);
    }
}
```

显然时间复杂度为指数函数，不出意外地超时 0 分。没有更多思路后选择先做[E](#E)题，做完 E 题看完 F 题后只剩半小时了，此时回头来看 D 题，尝试着画解答图然后用动态规划，纸笔模拟时又发现答案和解答图的层数有关... 最后还是没能推出正解。

考完后回头来钻研，其实只要数出出现 1 次的数字个数（记为 `magic1` ）和出现 3 次及以上的数字个数（记为 `magic3` ）就能秒出答案：

-   出现 1 次的数字：可能$(1, 0)$或$(0, 1)$，即对两人总共快乐值的贡献一定为 1；
-   出现 2 次的数字：可能$(1, 1)$或$(0, 0)$，对结果不产生影响；
-   出现 3 次及以上的数字：可能$(1, 0)$，$(0, 1)$或$(0, 0)$，即对两人总共快乐值的贡献可能为 0 或 1。

因此，如果 `magic1` 为偶数那么一定可以满足条件（所有出现 3 次及以上的数字贡献都为 0）；如果 `magic1` 为奇数，那么只要 `magic3` 不为 0 就能满足条件（从出现 3 次及以上的数字里随便挑一个，使其贡献为 1）。

```cpp
printf((magic1 % 2 == 0 || magic3 > 0) ? "YES\n" : "NO\n");
```

## E - 翻卡牌 ([C@牛客 2022 跨年场](https://ac.nowcoder.com/acm/contest/49343/C))

虽然 AC 但没有用到最优解，老老实实按照题目意思模拟，用 `next_permutation()` 枚举全排列（顺便一提，考试时因为忘了这个函数的名字而翻系统头文件浪费了十分钟），相加除以排列数得出答案。但是看到答案全是 0 心里自然没底，于是用 gdb 调了一个小时，愣是没发现问题出在哪，最后抱着随便试一试的态度提交，没想到 AC 了。

> 高情商：代码能力很强
>
> 低情商：没推出最优解

其实把牌的排列复制一份前后拼接的操作，等价于把一个整数乘上$10^9+1$，然而$10^9+1$这个数是**7 的倍数**，因此无论输入如何答案永远是 0。考试时连计算器都开了，纸笔也算了很久，居然没有发现这一点，导致浪费了大量时间，最后 F 题看了一眼觉得肯定做不出，便掉头去从前面的题目里试图捡回部分分数。

## F - Feeding the Cows ([P8898@Luogu](https://www.luogu.com.cn/problem/P8898))

~~因为没看题所以直接抄题解罢（~~

一块草可以覆盖距离为$K$的若干头奶牛，从左往右依次处理每一头牛，如果位于位置$i$的牛没有被覆盖，那么就在$i+k$的位置种上它所对应的草。这样既能保证第$i$头牛有草吃，又能尽可能多地覆盖后面的奶牛。

如果$i+k$超出$n$的范围，那么就种在$i$的位置就行，因为这样一定能保证覆盖到剩下的所有牛。如果尝试种草的位置已经有另外一丛草，那就试着往后种。无需担心这丛草不会覆盖到前面的牛，因为尝试重复种草的前提条件就是$i+k$越界，即种在$i$到$n-1$的任意位置都可以覆盖到剩余的牛。

## 小结

第一次参加线下测验，做题经验和考试技巧等都很欠缺，而且有部分分数是依赖 ACM 赛制反馈才得到的（如果是 NOIP 赛制的话估计分更少）。数学理论基础还要加强，并且做题的经验还需要长期的积累。希望 9 号的考试可以有所进步。
