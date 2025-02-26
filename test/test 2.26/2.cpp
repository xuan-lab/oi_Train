/*
【问题描述】
对于两个整数 a, b，既是 a 的整数倍又是 b 的整数倍的数称为 a 和 b 的公倍数。公倍数中最小的正整数称为 a 和 b 的最小公倍数。

请问， 2024 和 1024 的最小公倍数是多少？*/
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int main() {
    int a = 2024, b = 1024;
    cout << lcm(a, b) << endl;
    return 0;
}