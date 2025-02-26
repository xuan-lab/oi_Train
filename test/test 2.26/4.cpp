/*
【问题描述】
请问，在不超过 2024 的数中，最大的质数是多少？*/
#include <iostream>
using namespace std;
int main() {
    int n = 2024;
    int maxPrime = 0;
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            maxPrime = i;
        }
    }
    cout << "最大的质数是: " << maxPrime << endl;
    return 0;
}