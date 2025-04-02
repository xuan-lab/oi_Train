/**
 * 哈希表（Hash Table）详解与实现
 * 
 * 哈希表是一种基于哈希函数实现的数据结构，可以实现常数级别O(1)的查找、插入和删除操作。
 * 其核心思想是通过哈希函数将键映射到数组的索引，从而实现直接访问。
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>

// 使用链地址法解决冲突的哈希表实现
template <typename K, typename V>
class HashMap {
private:
    // 哈希表的每个节点包含一个键值对
    struct HashNode {
        K key;
        V value;
        HashNode(const K& k, const V& v) : key(k), value(v) {}
    };

    // 哈希表的桶数组，每个桶是一个链表
    std::vector<std::list<HashNode>> buckets;
    size_t size;
    
    // 哈希函数，将键转换为桶索引
    size_t hashFunction(const K& key) const {
        // 使用标准库的哈希函数
        return std::hash<K>{}(key) % buckets.size();
    }

public:
    // 构造函数，指定初始桶数量
    HashMap(size_t bucketCount = 10) : buckets(bucketCount), size(0) {}
    
    // 插入键值对
    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key);
        
        // 检查是否已存在该键，如果存在则更新值
        for (auto& node : buckets[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        
        // 键不存在，添加新节点
        buckets[index].push_back(HashNode(key, value));
        size++;
        
        // 检查负载因子，如果过高则扩容
        if ((float)size / buckets.size() > 0.7) {
            rehash();
        }
    }
    
    // 查找键对应的值
    bool get(const K& key, V& value) const {
        size_t index = hashFunction(key);
        
        for (const auto& node : buckets[index]) {
            if (node.key == key) {
                value = node.value;
                return true;
            }
        }
        
        return false; // 键不存在
    }
    
    // 删除键值对
    bool remove(const K& key) {
        size_t index = hashFunction(key);
        
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                size--;
                return true;
            }
        }
        
        return false; // 键不存在
    }
    
    // 检查键是否存在
    bool contains(const K& key) const {
        size_t index = hashFunction(key);
        
        for (const auto& node : buckets[index]) {
            if (node.key == key) {
                return true;
            }
        }
        
        return false;
    }
    
    // 返回哈希表中元素的数量
    size_t getSize() const {
        return size;
    }
    
    // 哈希表是否为空
    bool isEmpty() const {
        return size == 0;
    }
    
    // 重新哈希，扩容哈希表
    void rehash() {
        std::vector<std::list<HashNode>> oldBuckets = buckets;
        buckets.clear();
        buckets.resize(oldBuckets.size() * 2);
        size = 0;
        
        // 重新插入所有元素
        for (const auto& bucket : oldBuckets) {
            for (const auto& node : bucket) {
                insert(node.key, node.value);
            }
        }
    }
    
    // 打印哈希表的结构（用于调试）
    void print() const {
        for (size_t i = 0; i < buckets.size(); i++) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& node : buckets[i]) {
                std::cout << "[" << node.key << ":" << node.value << "] ";
            }
            std::cout << std::endl;
        }
    }
};

// 测试哈希表的使用
int main() {
    std::cout << "哈希表示例程序" << std::endl;
    std::cout << "=====================================\n" << std::endl;
    
    // 创建一个字符串->整数的哈希表
    HashMap<std::string, int> scores;
    
    // 插入一些键值对
    scores.insert("Alice", 95);
    scores.insert("Bob", 89);
    scores.insert("Charlie", 78);
    scores.insert("David", 92);
    scores.insert("Eva", 88);
    
    std::cout << "初始哈希表结构：" << std::endl;
    scores.print();
    std::cout << "\n哈希表大小: " << scores.getSize() << std::endl;
    
    // 查找值
    int score;
    if (scores.get("Alice", score)) {
        std::cout << "Alice的分数是: " << score << std::endl;
    } else {
        std::cout << "找不到Alice的分数" << std::endl;
    }
    
    // 更新值
    scores.insert("Alice", 97);  // 更新Alice的分数
    scores.get("Alice", score);
    std::cout << "Alice更新后的分数是: " << score << std::endl;
    
    // 删除键值对
    std::cout << "\n删除Charlie后：" << std::endl;
    scores.remove("Charlie");
    scores.print();
    
    // 检查键是否存在
    std::cout << "\nDavid是否存在? " << (scores.contains("David") ? "是" : "否") << std::endl;
    std::cout << "Charlie是否存在? " << (scores.contains("Charlie") ? "是" : "否") << std::endl;
    
    std::cout << "\n=====================================\n" << std::endl;
    std::cout << "哈希表的主要特点：" << std::endl;
    std::cout << "1. 平均时间复杂度：查找、插入和删除都是O(1)" << std::endl;
    std::cout << "2. 最坏时间复杂度：如果发生严重冲突，可能退化为O(n)" << std::endl;
    std::cout << "3. 空间复杂度：O(n)" << std::endl;
    std::cout << "4. 主要应用：实现字典、缓存、符号表等" << std::endl;
    
    return 0;
}