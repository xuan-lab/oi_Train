/*
题目描述
小蓝有一个超大的仓库，可以摆放很多货物。
现在，小蓝有n 箱货物要摆放在仓库，每箱货物都是规则的正方体。
小蓝规定了长、宽、高三个互相垂直的方向，每箱货物的边都必须严格平行于长、宽、高。
小蓝希望所有的货物最终摆成一个大的立方体。即在长、宽、高的方向上分别堆L、W、H 的货物，满足n = L × W × H。
给定n，请问有多少种堆放货物的方案满足要求。
例如，当n = 4 时，有以下6 种方案：1×1×4、1×2×2、1×4×1、2×1×2、2×2×1、4×1×1。
请问，当n = 2021041820210418 （注意有16 位数字）时，总共有多少种
方案？
提示：建议使用计算机编程解决问题。
接下来，我们将实现一个函数来计算满足条件的方案数量*/ 
#include <iostream>
using namespace std;
int countWays(long long n) {
    int count = 0;
    for (long long L = 1; L * L * L <= n; ++L) {
        if (n % L == 0) {
            long long remaining = n / L;
            for (long long W = L; W * W <= remaining; ++W) { // Start from L
                if (remaining % W == 0) {
                    long long H = remaining / W;
                    if (H >= W) { 
                        if (H == W && W == L) {
                            count++; 
                        } else if (H == W || W == L) {
                            count += 3; 
                        } else {
                            count += 6; 
                        }
                    }
                }
            }
        }
    }
    return count;
}
int main() {
    long long n = 4; // 输入的货物数量
    int result = countWays(n);
    cout << "Number of ways to arrange the boxes: " << result << endl;
    return 0;
}

