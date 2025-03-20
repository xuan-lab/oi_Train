/*
# P1307 [NOIP 2011 普及组] 数字反转
## 题目描述
给定一个整数 $N$，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例 2）。
## 输入格式
一个整数 $N$。
## 输出格式
一个整数，表示反转后的新数。
## 输入输出样例 #1
### 输入 #1
```
123
```
### 输出 #1
```
321
```
## 输入输出样例 #2
### 输入 #2
```
-380
```
### 输出 #2
```
-83
```
## 说明/提示
**【数据范围】**

$-1,000,000,000\leq N\leq 1,000,000,000 $。
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string n;
    cin >> n;
    bool isNegative = false;
    if (n[0] == '-') {
        isNegative = true;
        n = n.substr(1); 
    }
    reverse(n.begin(), n.end());
    while (n.size() > 1 && n[0] == '0') {
        n.erase(0, 1);
    }
    if (isNegative) {
        cout << "-" << n << endl;
    } else {
        cout << n << endl;
    }
    return 0;
}
