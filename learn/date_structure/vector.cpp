#include <iostream>
#include <vector>
#include <algorithm>  // For sort, binary_search, nth_element, etc.
#include <string>
#include <numeric>    // For accumulate and partial_sum

using namespace std;

// Vector基本操作（OI竞赛常用）
// 演示vector的创建、访问和基础操作
void vectorBasics() {
    cout << "=== 1. Vector基础操作 ===" << endl;
    
    // 创建vector的几种常见方式
    vector<int> vec1;                   // 空vector，初始大小为0
    vector<int> vec2(5, 10);            // 5个元素，每个值为10
    vector<int> vec3 = {1, 2, 3, 4, 5}; // 使用初始化列表
    
    // 快速输出vector内容
    // 使用下标访问每个元素 (时间复杂度O(n))
    cout << "vec3内容: ";
    for (int i = 0; i < vec3.size(); ++i) {  // size()返回元素个数
        cout << vec3[i] << " ";
    }
    cout << endl;
    
    // 基本操作
    cout << "vec3大小: " << vec3.size() << endl;
    
    // 向vector末尾添加元素 (通常是O(1)复杂度，但可能触发扩容)
    vec1.push_back(10);  // 添加元素10到末尾
    vec1.push_back(20);  // 添加元素20到末尾
    vec1.push_back(30);  // 添加元素30到末尾
    
    // 随机访问 - 竞赛中常用，O(1)时间复杂度
    cout << "vec1[1] = " << vec1[1] << endl;
    
    // 清空vector，删除所有元素
    vec1.clear();  // 清空后size变为0
    cout << "清空后vec1是否为空: " << (vec1.empty() ? "是" : "否") << endl;  // empty()检查是否为空
}

// 竞赛中常用算法
// 展示与vector配合使用的常用STL算法
void competitionAlgorithms() {
    cout << "\n=== 2. 竞赛常用算法 ===" << endl;
    
    vector<int> vec = {35, 12, 7, 56, 23, 9, 15};
    
    // 使用范围for循环(C++11)遍历元素
    cout << "原始数组: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // 排序（升序）- O(nlogn)时间复杂度
    sort(vec.begin(), vec.end());  // begin()返回首元素迭代器，end()返回尾后迭代器
    cout << "升序排序: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // 排序（降序）- 使用greater<int>函数对象
    sort(vec.begin(), vec.end(), greater<int>());  // 自定义比较方式
    cout << "降序排序: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // 重置数组
    vec = {35, 12, 7, 56, 23, 9, 15};
    
    // 第k小元素（部分排序）- O(n)时间复杂度，比完全排序更快
    int k = 3;
    nth_element(vec.begin(), vec.begin() + k - 1, vec.end());  // 将第k小元素放在正确位置
    cout << "第" << k << "小的元素: " << vec[k-1] << endl;
    
    // 数组求和 - O(n)时间复杂度
    vec = {1, 2, 3, 4, 5};
    int sum = accumulate(vec.begin(), vec.end(), 0);  // 0是初始值
    cout << "数组元素和: " << sum << endl;
    
    // 前缀和计算（竞赛中非常常用，用于区间求和优化）
    vector<int> prefix(vec.size());  // 创建相同大小的数组存储前缀和
    partial_sum(vec.begin(), vec.end(), prefix.begin());  // 计算前缀和
    cout << "前缀和数组: ";
    for (int x : prefix) cout << x << " ";
    cout << endl;
    
    // 二分查找 - O(logn)时间复杂度，要求数组已排序
    vec = {1, 3, 5, 7, 9, 11, 13};  // 已排序数组
    bool found = binary_search(vec.begin(), vec.end(), 7);  // 检查元素是否存在
    cout << "二分查找7: " << (found ? "找到" : "未找到") << endl;
    
    // lower_bound和upper_bound - 二分查找的变种，O(logn)时间复杂度
    auto lower = lower_bound(vec.begin(), vec.end(), 7);  // 返回>=7的第一个元素位置
    auto upper = upper_bound(vec.begin(), vec.end(), 7);  // 返回>7的第一个元素位置
    cout << "lower_bound(7)位置: " << (lower - vec.begin()) << endl;  // 计算下标
    cout << "upper_bound(7)位置: " << (upper - vec.begin()) << endl;  // 计算下标
}

// 一维二维数组操作（竞赛常用）
// 演示vector作为动态数组的使用方法
void vectorArrays() {
    cout << "\n=== 3. 一维二维数组操作 ===" << endl;
    
    int n = 5, m = 4;
    
    // 一维数组初始化
    vector<int> arr(n);  // 初始化为n个默认值(0)的数组
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;  // 设置每个元素值
    }
    
    cout << "一维数组: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // 二维数组初始化（竞赛常用方式）
    // 创建n行m列的矩阵，所有元素初始化为0
    vector<vector<int>> grid(n, vector<int>(m, 0));
    
    // 填充二维数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = i + j;  // 每个元素等于行号+列号
        }
    }
    
    // 打印二维数组
    cout << "二维数组:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    // 动态调整大小（竞赛中处理不定长输入）
    vector<int> dynamic;  // 空vector
    cout << "动态添加元素: ";
    for (int i = 0; i < 5; i++) {
        dynamic.push_back(i * 10);  // 添加元素
        cout << dynamic.back() << " ";  // back()返回最后一个元素
    }
    cout << endl;
}

// 常见竞赛技巧
// 展示一些在竞赛中提高效率的技巧
void competitionTricks() {
    cout << "\n=== 4. 竞赛技巧 ===" << endl;
    
    // 快速排序+去重 - 常用于集合操作
    vector<int> vec = {4, 2, 5, 3, 3, 1, 2, 4, 5};
    sort(vec.begin(), vec.end());  // 先排序，O(nlogn)
    // unique将重复元素移到末尾并返回新的逻辑末尾
    auto it = unique(vec.begin(), vec.end());  // O(n)
    vec.erase(it, vec.end());  // 删除重复元素
    
    cout << "排序并去重后: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // 离散化（常用于坐标压缩）
    // 将大范围的值映射到小范围，保持相对大小关系
    vector<int> nums = {1005, 1003, 1002, 1004, 1001};
    vector<int> original = nums;  // 保存原始数据
    
    // 离散化的三个步骤
    sort(nums.begin(), nums.end());  // 1. 排序
    // 2. 去重
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    cout << "离散化映射: " << endl;
    for (int x : original) {
        // 3. 二分查找获取原值的映射位置
        int idx = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        cout << x << " -> " << idx << endl;
    }
    
    // 使用vector存储邻接表（图论常用）
    int vertices = 5;  // 顶点数
    vector<vector<int>> graph(vertices);  // 邻接表
    
    // 添加边（无权图）
    graph[0].push_back(1);  // 顶点0连接到顶点1
    graph[0].push_back(4);  // 顶点0连接到顶点4
    graph[1].push_back(2);  // 顶点1连接到顶点2
    graph[1].push_back(3);  // 顶点1连接到顶点3
    graph[2].push_back(3);  // 顶点2连接到顶点3
    graph[3].push_back(4);  // 顶点3连接到顶点4
    
    // 打印邻接表
    cout << "邻接表表示的图:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "顶点 " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";  // 打印所有邻居节点
        }
        cout << endl;
    }
}

int main() {
    cout << "C++ Vector在OI竞赛中的应用\n" << endl;
    
    // 依次执行各个示例函数
    vectorBasics();         // 演示vector基础操作
    competitionAlgorithms();// 演示算法操作
    vectorArrays();         // 演示一维二维数组操作
    competitionTricks();    // 演示竞赛技巧
    
    cout << "\n学习完成！" << endl;
    return 0;
}
