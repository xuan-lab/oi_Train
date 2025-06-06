/*
【问题描述】
蓝桥村正在给村民们发放礼物。礼物通过一个礼物发放机完成。

村民们在机器前排着队领取礼物。

每个礼物有一个价值 v[i] ，有的高，有的低。每位村民有自己对于礼物的期望值 e[i] 。

礼物发放机每次会显示一个礼物，如果礼物的价值大于等于村民的期望值，村民就会高兴地把礼物拿走，并离开礼物发放机。如果礼物的价值比村民的期望值低，村民会让这个礼物取消，并让礼物发放机显示下一个礼物，并重新检查是否满足期望。村民会重复让礼物发放机显示下⼀个礼物，直到礼物发放机没有更多可以显示的礼物或礼物的价值大于等于自己的期望值。

如果礼物发放机中的所有礼物都显示完了，那么还没领到礼物的村民就无法领取礼物了。

如果所有的村民都领到了礼物，而礼物发放机还有礼物显示，村民们也不会再领取礼物。

现在，小蓝知道了每位村民的期望值，也知道了礼物发放机上礼物的显示顺序，请问总共有多少村民拿到了礼物？

【输入格式】
输入的第一行包含一个整数 n ，表示村民的个数。

第二行包含 n 个整数，相邻数之间使用一个空格分隔，依次表示排队的每位村民的期望值 e[i] 。

第三行包含一个整数 m ，表示礼物发放机会显示的礼物个数。

第四行包含 m 个整数，相邻数之间使用一个空格分隔，依次表示礼物发放机显示的礼物的价值 v[i] 。

【输出格式】
输出一行，包含一个整数，表示答案。

【样例输入】
6
6 5 5 3 6 0
9
9 9 8 2 4 4 3 5 3
【样例输出】
4
【样例说明】
前 4 位村民依次取到了第 1, 2, 3, 5 件礼物。后面的礼物未能满足第 5 位村民。

【评测用例规模与约定】
对于 30% 的评测用例，1 <= n, m <= 20 ， 0 <= e[i], v[i] <= 100 。

对于 60% 的评测用例，1 <= n, m <= 300 ， 0 <= e[i], v[i] <= 10000 。

对于所有评测用例，1 <= n, m <= 10000 ， 0 <= e[i], v[i] <= 1000000 。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }

    int villagers_satisfied = 0;
    int gift_index = 0;
    
    for (int i = 0; i < n && gift_index < m; ++i) {
        // Skip gifts that don't meet expectation
        while (gift_index < m && v[gift_index] < e[i]) {
            ++gift_index;
        }
        
        // If a suitable gift was found, give it to the villager
        if (gift_index < m) {
            ++villagers_satisfied;
            ++gift_index;
        }
    }

    cout << villagers_satisfied << endl;

    return 0;
}