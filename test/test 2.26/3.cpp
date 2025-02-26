/*
如果一个数 p 是个质数，同时又是整数 a 的约数，则 p 称为 a 的一个质因数。
请问， 2024 的所有质因数的和是多少？
*/
#include <iostream>
using namespace std;
int main() {
    int n = 2024;
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                sum += i;
            }
        }
    }
    cout << "质因数的和是: " << sum << endl;
    return 0;
}