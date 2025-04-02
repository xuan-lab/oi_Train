/**
 * C++栈(Stack)示例程序
 * 
 * 栈是一种遵循后进先出(LIFO: Last In First Out)原则的数据结构
 * 主要操作：
 * - push: 将元素添加到栈顶
 * - pop: 移除栈顶元素
 * - top: 获取栈顶元素但不移除
 * - empty: 检查栈是否为空
 * - size: 获取栈中元素个数
 */

#include <iostream>
#include <stack> // 包含C++标准库中的stack
#include <string>

// 演示STL stack的使用
void demonstrateSTLStack() {
    std::cout << "\n--- STL栈演示 ---\n";
    std::stack<int> s;
    
    // 压入元素
    std::cout << "压入元素: 10, 20, 30\n";
    s.push(10);
    s.push(20);
    s.push(30);
    
    // 获取栈大小
    std::cout << "栈大小: " << s.size() << std::endl;
    
    // 获取栈顶元素
    std::cout << "栈顶元素: " << s.top() << std::endl;
    
    // 弹出元素
    std::cout << "弹出元素: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    
    // 检查栈是否为空
    std::cout << "栈是否为空: " << (s.empty() ? "是" : "否") << std::endl;
}

// 自定义栈类实现
template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int topIndex;
    
public:
    // 构造函数
    Stack() : topIndex(-1) {}
    
    // 压入元素
    void push(const T& element) {
        if (topIndex >= MAX_SIZE - 1) {
            std::cout << "错误: 栈溢出\n";
            return;
        }
        data[++topIndex] = element;
    }
    
    // 弹出元素
    void pop() {
        if (isEmpty()) {
            std::cout << "错误: 栈为空\n";
            return;
        }
        --topIndex;
    }
    
    // 获取栈顶元素
    T top() const {
        if (isEmpty()) {
            std::cout << "错误: 栈为空\n";
            return T();
        }
        return data[topIndex];
    }
    
    // 检查栈是否为空
    bool isEmpty() const {
        return topIndex < 0;
    }
    
    // 获取栈大小
    int size() const {
        return topIndex + 1;
    }
};

// 演示自定义栈的使用
void demonstrateCustomStack() {
    std::cout << "\n--- 自定义栈演示 ---\n";
    Stack<std::string> s;
    
    // 压入元素
    std::cout << "压入元素: \"Hello\", \"World\", \"C++\"\n";
    s.push("Hello");
    s.push("World");
    s.push("C++");
    
    // 获取栈大小
    std::cout << "栈大小: " << s.size() << std::endl;
    
    // 获取栈顶元素
    std::cout << "栈顶元素: " << s.top() << std::endl;
    
    // 弹出元素
    std::cout << "弹出元素: ";
    while (!s.isEmpty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    
    // 检查栈是否为空
    std::cout << "栈是否为空: " << (s.isEmpty() ? "是" : "否") << std::endl;
}

// 演示栈的应用 - 括号匹配
bool areBracketsBalanced(const std::string& expr) {
    std::stack<char> s;
    
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            // 如果是开括号，入栈
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            // 如果是闭括号，检查栈顶元素是否匹配
            if (s.empty()) return false;
            
            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                s.pop(); // 匹配成功，弹出栈顶元素
            } else {
                return false; // 匹配失败
            }
        }
    }
    
    // 如果栈为空，则所有括号都匹配
    return s.empty();
}

// 演示栈的应用
void demonstrateStackApplications() {
    std::cout << "\n--- 栈应用示例: 括号匹配 ---\n";
    std::string expr1 = "{[()]}";
    std::string expr2 = "{[(])}";
    
    std::cout << "表达式 \"" << expr1 << "\" 括号是否平衡: " 
              << (areBracketsBalanced(expr1) ? "是" : "否") << std::endl;
    
    std::cout << "表达式 \"" << expr2 << "\" 括号是否平衡: " 
              << (areBracketsBalanced(expr2) ? "是" : "否") << std::endl;
}

int main() {
    std::cout << "==== C++栈演示程序 ====\n";
    
    // 演示STL栈
    demonstrateSTLStack();
    
    // 演示自定义栈
    demonstrateCustomStack();
    
    // 演示栈的应用
    demonstrateStackApplications();
    
    std::cout << "\n==== 栈是计算机科学中的基础数据结构 ====\n";
    std::cout << "应用场景：\n";
    std::cout << "1. 函数调用和递归\n";
    std::cout << "2. 表达式求值和转换(中缀、后缀、前缀)\n";
    std::cout << "3. 括号匹配检查\n";
    std::cout << "4. 撤销操作(Undo)的实现\n";
    std::cout << "5. 深度优先搜索(DFS)算法\n";
    
    return 0;
}