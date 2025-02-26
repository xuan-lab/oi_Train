#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <chrono>
#include <iomanip>

int main() {
    std::cout << "============= C++ Map 详解 =============\n\n";
    
    // 1. 创建和基本操作
    std::cout << "1. 基本操作\n";
    // map是关联容器，按照键的顺序自动排序(红黑树实现)
    std::map<std::string, int> studentScores;
    
    // 插入元素的多种方式
    studentScores["Alice"] = 95;  // 使用[]运算符
    studentScores["Bob"] = 89;
    
    studentScores.insert({"Charlie", 92});  // 使用insert方法
    studentScores.insert(std::make_pair("David", 78));  // 使用make_pair
    
    // 使用emplace直接构造(C++11起)，效率更高
    studentScores.emplace("Eve", 88);
    
    // 查找和访问元素
    std::cout << "Bob的分数: " << studentScores["Bob"] << "\n";
    
    // 检查键是否存在
    if (studentScores.count("Alice") > 0) {
        std::cout << "Alice在映射中\n";
    }
    
    auto search = studentScores.find("David");
    if (search != studentScores.end()) {
        std::cout << "找到" << search->first << "，分数为" << search->second << "\n";
    } else {
        std::cout << "未找到该学生\n";
    }
    
    std::cout << "\n2. 安全访问方式\n";
    // 使用at()安全访问(键不存在会抛出异常)
    try {
        std::cout << "Charlie的分数: " << studentScores.at("Charlie") << "\n";
        std::cout << "Unknown的分数: " << studentScores.at("Unknown") << "\n"; // 会抛出异常
    } catch (const std::out_of_range& e) {
        std::cout << "异常: " << e.what() << "\n";
    }
    
    std::cout << "\n3. 迭代和遍历\n";
    // 遍历映射(自动按键排序)
    std::cout << "所有学生分数:\n";
    for (const auto& [name, score] : studentScores) {  // C++17结构化绑定
        std::cout << name << ": " << score << "\n";
    }
    
    std::cout << "\n4. 删除元素\n";
    // 删除元素
    studentScores.erase("David");
    std::cout << "删除David后，映射大小: " << studentScores.size() << "\n";
    
    std::cout << "\n5. map vs unordered_map 性能对比\n";
    // map(红黑树): 查找、插入、删除 O(log n)，有序
    // unordered_map(哈希表): 平均 O(1)，无序
    
    std::map<int, int> orderedMap;
    std::unordered_map<int, int> unorderedMap;
    
    const int TEST_SIZE = 100000;
    
    // 测试插入性能
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < TEST_SIZE; i++) {
        orderedMap[i] = i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto mapTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < TEST_SIZE; i++) {
        unorderedMap[i] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    auto unorderedMapTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "插入" << TEST_SIZE << "个元素时间对比:\n";
    std::cout << "map: " << mapTime << " ms\n";
    std::cout << "unordered_map: " << unorderedMapTime << " ms\n";
    
    std::cout << "\n6. 实用示例：单词频率统计\n";
    // 使用map统计单词频率
    std::map<std::string, int> wordFreq;
    std::string text = "the quick brown fox jumps over the lazy dog";
    std::string word;
    std::istringstream iss(text);
    while (iss >> word) {
        wordFreq[word]++;
    }
    
    std::cout << "单词频率统计:\n";
    for (const auto& pair : wordFreq) {
        std::cout << std::setw(8) << std::left << pair.first << ": " << pair.second << "\n";
    }
    
    return 0;
}