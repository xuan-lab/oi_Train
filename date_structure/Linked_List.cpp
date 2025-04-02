#include <iostream>
using namespace std;

// 定义链表节点结构
template <typename T>
struct Node {
    T data;           // 节点存储的数据
    Node<T>* next;    // 指向下一个节点的指针
    
    // 构造函数
    Node(T value) : data(value), next(nullptr) {}
};

// 链表类定义
template <typename T>
class LinkedList {
private:
    Node<T>* head;    // 头节点指针
    int size;         // 链表大小
    
public:
    // 构造函数
    LinkedList() : head(nullptr), size(0) {}
    
    // 析构函数 - 释放所有节点内存
    ~LinkedList() {
        clear();
    }
    
    // 在链表头部插入节点
    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    // 在链表尾部插入节点
    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        
        // 如果链表为空，则插入的节点成为头节点
        if (head == nullptr) {
            head = newNode;
        } else {
            // 找到尾节点，然后添加新节点
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    
    // 在指定位置插入节点
    bool insertAt(int position, T value) {
        // 检查位置是否有效
        if (position < 0 || position > size) {
            return false;
        }
        
        // 如果在头部插入
        if (position == 0) {
            insertAtHead(value);
            return true;
        }
        
        // 找到要插入位置的前一个节点
        Node<T>* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        
        // 创建新节点并插入到正确的位置
        Node<T>* newNode = new Node<T>(value);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        
        return true;
    }
    
    // 删除第一个值为指定值的节点
    bool remove(T value) {
        if (head == nullptr) return false;
        
        // 如果要删除的是头节点
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        
        // 寻找要删除的节点
        Node<T>* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }
        
        // 如果找到了匹配的节点，删除它
        if (current->next) {
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        
        return false;
    }
    
    // 删除指定位置的节点
    bool removeAt(int position) {
        // 检查位置是否有效
        if (position < 0 || position >= size || head == nullptr) {
            return false;
        }
        
        // 如果删除的是头节点
        if (position == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        
        // 找到要删除位置的前一个节点
        Node<T>* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        // 删除节点
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
        
        return true;
    }
    
    // 获取指定位置的元素
    bool get(int position, T& outValue) {
        if (position < 0 || position >= size || head == nullptr) {
            return false;
        }
        
        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        
        outValue = current->data;
        return true;
    }
    
    // 修改指定位置的元素
    bool set(int position, T value) {
        if (position < 0 || position >= size || head == nullptr) {
            return false;
        }
        
        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        
        current->data = value;
        return true;
    }
    
    // 查找元素，返回其位置，如果未找到则返回-1
    int find(T value) {
        Node<T>* current = head;
        int position = 0;
        
        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        
        return -1;  // 未找到
    }
    
    // 反转链表
    void reverse() {
        if (head == nullptr || head->next == nullptr) return;
        
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  // 保存下一个节点
            current->next = prev;  // 反转当前节点的指针
            prev = current;        // 更新前一个节点
            current = next;        // 移动到下一个节点
        }
        
        head = prev;  // 更新头指针为原链表的最后一个节点
    }
    
    // 打印链表
    void print() {
        Node<T>* temp = head;
        cout << "链表内容: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    
    // 获取链表大小
    int getSize() {
        return size;
    }
    
    // 检查链表是否为空
    bool isEmpty() {
        return head == nullptr;
    }
    
    // 清空链表
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};

// 主函数 - 演示链表的使用
int main() {
    // 创建一个整数链表
    LinkedList<int> list;
    
    // 测试插入操作
    cout << "===== 测试插入操作 =====" << endl;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAt(2, 15);
    list.print();  // 应输出: 5 -> 10 -> 15 -> 20
    
    // 测试查找操作
    cout << "\n===== 测试查找操作 =====" << endl;
    int position = list.find(15);
    cout << "15的位置是: " << position << endl;  // 应输出: 2
    
    // 测试获取和修改操作
    cout << "\n===== 测试获取和修改操作 =====" << endl;
    int value;
    if (list.get(1, value)) {
        cout << "位置1的元素是: " << value << endl;  // 应输出: 10
    }
    
    list.set(1, 12);
    list.print();  // 应输出: 5 -> 12 -> 15 -> 20
    
    // 测试删除操作
    cout << "\n===== 测试删除操作 =====" << endl;
    list.remove(15);
    list.print();  // 应输出: 5 -> 12 -> 20
    
    list.removeAt(0);
    list.print();  // 应输出: 12 -> 20
    
    // 测试链表反转
    cout << "\n===== 测试链表反转 =====" << endl;
    list.insertAtHead(8);
    list.insertAtTail(30);
    list.print();  // 应输出: 8 -> 12 -> 20 -> 30
    
    list.reverse();
    list.print();  // 应输出: 30 -> 20 -> 12 -> 8
    
    // 测试清空操作
    cout << "\n===== 测试清空操作 =====" << endl;
    cout << "链表大小: " << list.getSize() << endl;
    list.clear();
    cout << "清空后链表大小: " << list.getSize() << endl;
    cout << "链表是否为空: " << (list.isEmpty() ? "是" : "否") << endl;
    
    return 0;
}