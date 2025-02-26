/*
【问题描述】
如果两个整数 a, b 除了 1 以外，没有其它的公约数，则称整数 a 与 b 互质。

请问，与 2024 互质的数中（包括1），第 2024 小的数是多少？*/
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
int main() {
    int n = 2024;
    int count = 0;
    for (int i = 1; ; i++) {
        if (gcd(i, n) == 1) {
            count++;
            if (count == 2024) {
                cout << "与 " << n << " 互质的第 2024 小的数是: " << i << endl;
                break;
            }
        }
    }
    return 0;
}
