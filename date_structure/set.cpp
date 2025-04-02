/*
 * C++ Set 容器示例程序
 * 
 * Set (集合) 是 C++ STL 提供的一个关联容器，有以下特点：
 * 1. 元素唯一：set 中不允许有重复元素
 * 2. 元素有序：set 中的元素按照一定的排序准则进行排序（默认是升序）
 * 3. 底层实现：通常基于红黑树，这使得查找、插入和删除操作的时间复杂度均为 O(log n)
 */

#include <iostream>
#include <set>
#include <string>
#include <algorithm> // 用于set_intersection等操作

int main() {
    // 1. 创建和初始化 set
    std::cout << "===== 创建和初始化 set =====" << std::endl;
    
    // 默认构造一个空set
    std::set<int> set1;
    
    // 使用初始化列表创建
    std::set<int> set2 = {5, 3, 1, 4, 2};
    
    // 使用迭代器范围创建
    std::set<int> set3(set2.begin(), set2.end());
    
    // 复制构造
    std::set<int> set4(set2);
    
    // 2. 基本操作：插入和删除
    std::cout << "\n===== 基本操作 =====" << std::endl;
    
    // 插入元素
    set1.insert(10);
    set1.insert(20);
    set1.insert(30);
    
    std::cout << "插入元素后 set1 包含: ";
    for (const auto& elem : set1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // 尝试插入重复元素
    auto result = set1.insert(10);
    if (!result.second) {
        std::cout << "插入失败：元素 " << *(result.first) << " 已存在" << std::endl;
    }
    
    // 删除元素
    size_t count = set1.erase(20); // 返回删除的元素数量
    std::cout << "删除了 " << count << " 个元素" << std::endl;
    
    // 3. 唯一性和自动排序
    std::cout << "\n===== 唯一性和自动排序 =====" << std::endl;
    std::cout << "set2 包含 (自动排序): ";
    for (const auto& elem : set2) {
        std::cout << elem << " "; // 注意输出是有序的
    }
    std::cout << std::endl;
    
    // 4. 查找和访问
    std::cout << "\n===== 查找和访问 =====" << std::endl;
    
    // 检查元素是否存在
    if (set2.find(3) != set2.end()) {
        std::cout << "元素 3 存在于 set2 中" << std::endl;
    }
    
    if (set2.count(100) == 0) {
        std::cout << "元素 100 不存在于 set2 中" << std::endl;
    }
    
    // 5. 集合操作
    std::cout << "\n===== 集合操作 =====" << std::endl;
    
    std::set<int> A = {1, 2, 3, 4, 5};
    std::set<int> B = {4, 5, 6, 7, 8};
    
    std::cout << "集合 A: ";
    for (const auto& elem : A) std::cout << elem << " ";
    std::cout << std::endl;
    
    std::cout << "集合 B: ";
    for (const auto& elem : B) std::cout << elem << " ";
    std::cout << std::endl;
    
    // 交集
    std::set<int> intersection;
    std::set_intersection(
        A.begin(), A.end(),
        B.begin(), B.end(),
        std::inserter(intersection, intersection.begin())
    );
    
    std::cout << "A ∩ B: ";
    for (const auto& elem : intersection) std::cout << elem << " ";
    std::cout << std::endl;
    
    // 并集
    std::set<int> union_set;
    std::set_union(
        A.begin(), A.end(),
        B.begin(), B.end(),
        std::inserter(union_set, union_set.begin())
    );
    
    std::cout << "A ∪ B: ";
    for (const auto& elem : union_set) std::cout << elem << " ";
    std::cout << std::endl;
    
    // 差集 (A - B)
    std::set<int> difference;
    std::set_difference(
        A.begin(), A.end(),
        B.begin(), B.end(),
        std::inserter(difference, difference.begin())
    );
    
    std::cout << "A - B: ";
    for (const auto& elem : difference) std::cout << elem << " ";
    std::cout << std::endl;
    
    // 6. 高级功能：自定义比较器
    std::cout << "\n===== 自定义比较器 =====" << std::endl;
    
    // 使用自定义比较器创建一个降序的set
    std::set<int, std::greater<int>> desc_set = {1, 5, 3, 2, 4};
    
    std::cout << "降序set: ";
    for (const auto& elem : desc_set) std::cout << elem << " ";
    std::cout << std::endl;
    
    // 使用自定义结构体作为set元素
    struct Person {
        std::string name;
        int age;
        
        // 必须定义小于运算符用于比较
        bool operator<(const Person& other) const {
            // 按照姓名字典序排序
            return name < other.name;
        }
    };
    
    std::set<Person> people = {
        {"Zhang", 25},
        {"Li", 30},
        {"Wang", 20}
    };
    
    std::cout << "人员集合（按姓名排序）: " << std::endl;
    for (const auto& person : people) {
        std::cout << "  " << person.name << ", " << person.age << "岁" << std::endl;
    }
    
    // 7. 性能和应用场景
    std::cout << "\n===== 性能和应用场景 =====" << std::endl;
    
    std::cout << "set的主要操作时间复杂度:" << std::endl;
    std::cout << "  插入: O(log n)" << std::endl;
    std::cout << "  删除: O(log n)" << std::endl;
    std::cout << "  查找: O(log n)" << std::endl;
    
    std::cout << "\n适用场景:" << std::endl;
    std::cout << "  1. 需要保持元素唯一性" << std::endl;
    std::cout << "  2. 需要元素始终有序" << std::endl;
    std::cout << "  3. 频繁进行查找操作" << std::endl;
    std::cout << "  4. 需要执行集合操作（交集、并集等）" << std::endl;
    
    return 0;
}