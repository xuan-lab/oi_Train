#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// 1. 函数模板 (Function Templates)
// 泛型函数，可以处理不同类型的数据
// T是类型参数，编译器会根据传入的参数自动推导T的类型
template <typename T>
T max_value(T a, T b) {
    return (a > b) ? a : b;
}

// 带有多个类型参数的函数模板
// 使用auto和decltype自动推导返回类型，支持不同类型的参数相加
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// 2. 类模板 (Class Templates)
// 泛型类，可以存储任意类型的数据
// 类型T在实例化时才确定，实现了代码复用
template <typename T>
class Container {
private:
    T element;  // 存储T类型的元素
public:
    Container(T arg) : element(arg) {}  // 构造函数
    T getValue() const { return element; }  // 获取存储的值
};

// 3. 模板特化 (Template Specialization)
// 为特定类型提供特殊实现，当类型不同时可以有不同的行为
template <typename T>
class DataProcessor {
public:
    void process(T data) {
        std::cout << "处理通用数据: " << data << std::endl;
    }
};

// 针对std::string类型的特化
// 当T是string时，使用这个特化版本而不是通用版本
template <>
class DataProcessor<std::string> {
public:
    void process(std::string data) {
        std::cout << "处理字符串数据: " << data << std::endl;
    }
};

// 4. 可变参数模板 (Variadic Templates)
// 递归终止条件 - 当没有参数时调用这个版本，结束递归
void print() {
    std::cout << std::endl;
}

// 可变参数模板函数
// T表示第一个参数的类型，Args...表示剩余参数的类型包
template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...);  // 递归调用，每次减少一个参数
}

// 5. 模板元编程 (Template Metaprogramming)
// 编译时计算阶乘 - 利用模板递归和特化在编译期计算结果
template <int N>
struct Factorial {
    enum { value = N * Factorial<N - 1>::value };  // 递归计算
};

// 特化终止递归条件
template <>
struct Factorial<0> {
    enum { value = 1 };  // 0的阶乘为1
};

// 6. 非类型模板参数 (Non-type Template Parameters)
// 使用整数作为模板参数，在编译期确定数组大小
template <typename T, int Size>
class Array {
private:
    T data[Size];  // 固定大小的数组
public:
    T& operator[](int index) {
        return data[index];
    }
    
    int size() const {
        return Size;
    }
};

// 7. 模板模板参数 (Template Template Parameters)
// 参数Container本身就是一个模板，接受其他模板作为参数
template <template <typename> class Container, typename T>
class GenericContainer {
private:
    Container<T> container;  // 使用传入的模板类型实例化
public:
    void add(const T& item) {
        container.push_back(item);
    }
    
    void display() {
        for (const auto& item : container) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

// 8. SFINAE (Substitution Failure Is Not An Error)
// 使用enable_if实现类型约束，只有当T是整数类型时函数才可用
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_even(T t) {
    return t % 2 == 0;  // 只对整数类型有意义的操作
}

int main() {
    std::cout << "===== C++模板学习程序 =====" << std::endl;
    
    // 1. 函数模板示例
    std::cout << "\n1. 函数模板:" << std::endl;
    std::cout << "max_value(10, 20) = " << max_value(10, 20) << std::endl;  // T推导为int
    std::cout << "max_value(3.14, 2.72) = " << max_value(3.14, 2.72) << std::endl;  // T推导为double
    std::cout << "add(5, 3.5) = " << add(5, 3.5) << std::endl;  // T为int，U为double，返回double
    
    // 2. 类模板示例
    std::cout << "\n2. 类模板:" << std::endl;
    Container<int> intContainer(42);  // 显式指定T为int
    Container<std::string> strContainer("Hello Templates");  // 显式指定T为string
    std::cout << "intContainer: " << intContainer.getValue() << std::endl;
    std::cout << "strContainer: " << strContainer.getValue() << std::endl;
    
    // 3. 模板特化示例
    std::cout << "\n3. 模板特化:" << std::endl;
    DataProcessor<int> intProcessor;  // 使用通用版本
    DataProcessor<std::string> strProcessor;  // 使用特化版本
    intProcessor.process(100);
    strProcessor.process("模板特化示例");
    
    // 4. 可变参数模板示例
    std::cout << "\n4. 可变参数模板:" << std::endl;
    print("Hello", 42, 3.14, "Templates", 'A');  // 传递不同类型的多个参数
    
    // 5. 模板元编程示例
    std::cout << "\n5. 模板元编程:" << std::endl;
    std::cout << "5! = " << Factorial<5>::value << std::endl;  // 编译期计算5!
    std::cout << "10! = " << Factorial<10>::value << std::endl;  // 编译期计算10!
    
    // 6. 非类型模板参数示例
    std::cout << "\n6. 非类型模板参数:" << std::endl;
    Array<int, 5> arr;  // 编译期确定数组大小为5
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i * i;
    }
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    
    // 7. 模板模板参数示例（此处简化，实际使用需要更完整的实现）
    std::cout << "\n7. 模板模板参数:" << std::endl;
    std::cout << "(需要完整的容器实现，此处略过实际演示)" << std::endl;
    
    // 8. SFINAE示例
    std::cout << "\n8. SFINAE:" << std::endl;
    std::cout << "is_even(42) = " << is_even(42) << std::endl;  // 整数类型，编译成功
    // 下面这行会导致编译错误，因为is_even只接受整数类型
    // std::cout << "is_even(3.14) = " << is_even(3.14) << std::endl;  // 浮点类型，编译失败
    
    std::cout << "\n===== 模板学习完毕 =====" << std::endl;
    return 0;
}