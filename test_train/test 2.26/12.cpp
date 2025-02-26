/*
【问题描述】
小蓝有一个 n 行 m 列的矩阵 a[i][j] ，他想着矩阵中找出一个“十”字形状的区域，使得区域内的值的和最大。

一个“十”字形状的区域可以由两个行号 r1 、 r2 和两个列号 c1 、 c2 表示。“十”字的区域内包括第 r1 行到 r2 行的所有元素，以及第 c1 列到 c2 列的所有元素，既不在这几行也不在这几列的元素不在区域内。

为了保证是一个“十”字的形状，必须满足 1 < r1 <= r2 < n，1 < c1 <= c2 < m。

【输入格式】
输入的第一行包含两个整数 n, m ，分别表示行数和列数。

接下来 n 行，每行包含 m 个整数，相邻数之间使用一个空格分隔，依次表示矩阵的每行每列的值，本部分的第 i 行第 j 列表示 a[i][j] 。

【输出格式】
输出一行包含一个整数，表示最大的和。

【样例输入】
5 6
1 -1 2 -2 3 -3
-1 2 -2 3 -3 4
2 -2 3 -3 4 -4
-2 3 -3 4 -4 5
3 -3 4 -4 5 -5
【样例输出】
14
【样例说明】
有两种方法可以得到最大的和。第一种是取 r1=2, r2=4, c1=3, c2=5，第二种是取 r1=2, r2=4, c1=5, c2=5 。

【评测用例规模与约定】
对于 30% 的评测用例，3 <= n, m <= 30 ，-1000 <= a[i][j] <= 1000 。

对于 60% 的评测用例，3 <= n, m <= 100 ，-1000 <= a[i][j] <= 1000 。

对于所有评测用例，3 <= n <= 100, 3 <= m <= 5000 ，-1000 <= a[i][j] <= 1000 。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = INT_MIN;
    for (int r1 = 1; r1 < n - 1; ++r1) {
        for (int r2 = r1; r2 < n - 1; ++r2) {
            for (int c1 = 1; c1 < m - 1; ++c1) {
                for (int c2 = c1; c2 < m - 1; ++c2) {
                    int sum = 0;
                    // Sum rows r1 to r2 (all columns)
                    for (int i = r1; i <= r2; ++i) {
                        for (int j = 0; j < m; ++j) {
                            sum += a[i][j];
                        }
                    }
                    // Sum columns c1 to c2 (all rows)
                    for (int j = c1; j <= c2; ++j) {
                        for (int i = 0; i < n; ++i) {
                            sum += a[i][j];
                        }
                    }
                    // Subtract the double-counted intersections
                    for (int i = r1; i <= r2; ++i) {
                        for (int j = c1; j <= c2; ++j) {
                            sum -= a[i][j];
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
