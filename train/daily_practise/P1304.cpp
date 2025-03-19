#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    for (int i = 4; i <= n; i += 2) {
        for (int j = 0; j < primes.size(); j++) {
            if (primes[j] > i / 2) break;
            if (isPrime(i - primes[j])) {
                cout << i << "=" << primes[j] << "+" << i - primes[j] << endl;
                break;
            }
        }
    }
    return 0;
}

