/*
对于字符串 S=ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN ，请找到 S 的一个长度不超过 10 的子串 A，使得（A的长度）乘以（A在S中出现的次数）最大。

请问这个子串是什么？（如果有多个满足条件的，请回答字典序最小的）。*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN";
    int maxProduct = 0;
    string result;

    unordered_map<string, int> freqMap;
    for (int len = 1; len <= 10; len++) {
        for (int i = 0; i <= s.length() - len; i++) {
            string subStr = s.substr(i, len);
            freqMap[subStr]++;
        }
    }

    for (const auto& entry : freqMap) {
        int product = entry.first.length() * entry.second;
        if (product > maxProduct || (product == maxProduct && entry.first < result)) {
            maxProduct = product;
            result = entry.first;
        }
    }

    cout << "满足条件的子串是: " << result << endl;
    return 0;
}