/*
如果一个数 p 是个质数，同时又是整数 a 的约数，则 p 称为 a 的一个质因数。

请问， 2024 的最大的质因数是多少？*/
#include <iostream>
using namespace std;
int main() {
    int n = 2024;
    int max_prime_factor = -1;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            max_prime_factor = i;
            n /= i;
        }
    }
    if (n > 1) {
        max_prime_factor = n;
    }
    cout << max_prime_factor << endl;
    return 0;
}