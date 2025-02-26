/*
【问题描述】
给定四个字符串 a, b, c, d，请将这四个字符串按照任意顺序依次连接拼成一个字符串。

请问拼成的字符串字典序最小是多少？

【输入格式】
输入四行，每行包含一个字符串。

【输出格式】
输出一行包含一个字符串，表示答案。

【样例输入】
LAN
LAN
QIAO
BEI
【样例输出】
BEILANLANQIAO*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<string> strings(4);
    for (int i = 0; i < 4; i++) {
        cin >> strings[i];
    }
    sort(strings.begin(), strings.end());
    do {
        string result;
        for (const string& str : strings) {
            result += str;
        }
        cout << result << endl;
    } while (next_permutation(strings.begin(), strings.end()));
    return 0;
}
