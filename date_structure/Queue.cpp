/**
 * C++ 队列(Queue)和双端队列(Deque)的示例程序
 * 
 * 队列：先进先出(FIFO)的数据结构，只能在一端(尾部)添加元素，在另一端(头部)删除元素
 * 双端队列：可以在两端进行插入和删除操作的队列
 */

#include <iostream>
#include <queue>      // 包含队列
#include <deque>      // 包含双端队列
#include <string>

// 用于展示队列和双端队列中的元素
template <typename T>
void printContainer(const T& container, const std::string& name) {
    std::cout << name << " 内容 (从前到后): ";
    
    // 创建容器的副本以便遍历（因为queue没有迭代器）
    T temp = container;
    
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

// 特化版本用于deque，因为deque可以直接用迭代器访问
template <>
void printContainer(const std::deque<int>& deq, const std::string& name) {
    std::cout << name << " 内容 (从前到后): ";
    for (const auto& element : deq) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "========== 队列(Queue)演示 ==========" << std::endl;
    
    // 创建并初始化队列
    std::queue<int> myQueue;
    
    // 插入元素到队列尾部
    std::cout << "向队列添加元素: 10, 20, 30, 40" << std::endl;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    
    // 显示队列信息
    std::cout << "队列大小: " << myQueue.size() << std::endl;
    std::cout << "队首元素: " << myQueue.front() << std::endl;
    std::cout << "队尾元素: " << myQueue.back() << std::endl;
    
    // 遍历队列元素（注意：这会清空队列）
    printContainer(myQueue, "原始队列");
    
    // 移除队首元素
    std::cout << "\n弹出队首元素" << std::endl;
    myQueue.pop();
    printContainer(myQueue, "弹出后的队列");

    std::cout << "\n========== 双端队列(Deque)演示 ==========" << std::endl;
    
    // 创建并初始化双端队列
    std::deque<int> myDeque;
    
    // 在双端队列两端添加元素
    myDeque.push_back(100);  // 尾部添加
    myDeque.push_front(50);  // 头部添加
    myDeque.push_back(150);  // 尾部添加
    myDeque.push_front(25);  // 头部添加
    
    std::cout << "添加元素后:" << std::endl;
    printContainer(myDeque, "双端队列");
    
    // 访问双端队列的任意位置
    std::cout << "\n使用下标访问: myDeque[2] = " << myDeque[2] << std::endl;
    
    // 在双端队列两端移除元素
    std::cout << "\n移除头部元素" << std::endl;
    myDeque.pop_front();
    printContainer(myDeque, "双端队列");
    
    std::cout << "\n移除尾部元素" << std::endl;
    myDeque.pop_back();
    printContainer(myDeque, "双端队列");
    
    // 在中间插入元素
    std::cout << "\n在位置1插入元素75" << std::endl;
    myDeque.insert(myDeque.begin() + 1, 75);
    printContainer(myDeque, "双端队列");
    
    std::cout << "\n========== 队列与双端队列的区别 ==========" << std::endl;
    std::cout << "1. 队列(Queue)只允许在一端添加，另一端删除元素" << std::endl;
    std::cout << "2. 双端队列(Deque)允许在任意一端添加或删除元素" << std::endl;
    std::cout << "3. 双端队列允许随机访问元素(使用[]或at())，队列不允许" << std::endl;
    std::cout << "4. 双端队列是队列和栈的泛化，可以模拟两者的行为" << std::endl;

    return 0;
}