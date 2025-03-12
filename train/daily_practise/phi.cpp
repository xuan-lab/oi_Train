#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// 函数原型声明，用于Miller-Rabin素性测试
bool millerRabinTest(long long a, long long d, long long n);

// 模乘运算，避免大整数溢出
long long mulmod(long long a, long long b, long long mod) {
    long long res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod; // 如果b的当前位为1，将a加入结果
        a = (a + a) % mod; // 相当于a左移一位
        b >>= 1; // b右移一位
    }
    return res;
}

// 快速幂取模运算
long long powmod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = mulmod(res, base, mod); // 如果指数当前位为1，将base乘入结果
        base = mulmod(base, base, mod); // base平方
        exp >>= 1; // 指数右移一位
    }
    return res;
}

// Miller-Rabin素性测试
bool isPrime(long long n) {
    if (n <= 1) return false; // 1不是素数
    if (n <= 3) return true; // 2和3是素数
    if (n % 2 == 0) return false; // 偶数不是素数（除了2）

    // 将n-1表示为d*2^r的形式
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;

    // 证人测试循环
    const int witnesses[] = {2, 3, 5, 7, 11, 13, 17, 19, 23}; // 固定证人集合
    for (int a : witnesses) {
        if (n == a) return true; // 如果n就是证人，那么n是素数
        if (n > a && !millerRabinTest(a, d, n)) return false; // 如果测试失败，则n一定是合数
    }
    return true; // 通过所有测试，很可能是素数
}

// Miller-Rabin素性测试的辅助函数
bool millerRabinTest(long long a, long long d, long long n) {
    long long x = powmod(a, d, n);
    if (x == 1 || x == n - 1) return true;
    
    while (d != n - 1) {
        x = mulmod(x, x, n);
        d *= 2;
        if (x == 1) return false; // 发现非平凡平方根，所以n是合数
        if (x == n - 1) return true; // Miller-Rabin测试通过
    }
    return false; // 所有测试都失败，n是合数
}

// Pollard's rho算法用于大数分解
long long pollardRho(long long n) {
    if (n % 2 == 0) return 2; // 如果是偶数，直接返回因子2
    
    // 随机初始化x，y和增量c
    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long c = rand() % (n - 1) + 1;
    long long d = 1;
    
    // 使用Floyd循环查找算法寻找因子
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n; // 一次迭代
        y = (mulmod(y, y, n) + c) % n; // 两次迭代
        y = (mulmod(y, y, n) + c) % n;
        d = std::__gcd(std::abs(x - y), n); // 计算最大公约数
        if (d == n) return pollardRho(n); // 如果失败，重新尝试
    }
    
    return d; // 返回找到的因子
}

// 快速质因数分解
std::vector<long long> primeFactors(long long n) {
    std::vector<long long> factors;
    
    // 处理小因子2
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    
    // 试除法处理小质数因子
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    
    // 处理大质因数
    if (n > 1) {
        if (isPrime(n)) {
            factors.push_back(n); // 如果n是素数，直接添加
        } else {
            // 使用Pollard's rho算法分解大合数
            long long factor = pollardRho(n);
            std::vector<long long> subfactors1 = primeFactors(factor);
            std::vector<long long> subfactors2 = primeFactors(n / factor);
            factors.insert(factors.end(), subfactors1.begin(), subfactors1.end());
            factors.insert(factors.end(), subfactors2.begin(), subfactors2.end());
        }
    }
    
    return factors;
}

// 优化的欧拉函数计算
long long phi(long long n) {
    if (n == 1) return 1;
    
    // 获取所有质因数
    std::vector<long long> factors = primeFactors(n);
    
    // 使用公式φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
    // 其中p1, p2, ..., pk是n的不同质因数
    std::vector<long long> unique;
    for (size_t i = 0; i < factors.size(); i++) {
        if (i == 0 || factors[i] != factors[i-1]) {
            unique.push_back(factors[i]);
        }
    }
    
    long long result = n;
    for (long long p : unique) {
        result = result / p * (p - 1); // 等价于result *= (1 - 1/p)
    }
    
    return result;
}

int main() {
    long long n;
    std::cout << "Enter a number to compute its Euler's totient: "; // 输入一个数以计算其欧拉函数值
    std::cin >> n;
    std::cout << "φ(" << n << ") = " << phi(n) << std::endl; // 输出欧拉函数值
    return 0;
}