#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Vector with iterators
    cout << "--- Vector example ---" << endl;
    vector<int> vec = {1, 2, 3, 4, 5};
    
    cout << "Using iterator to print vector elements: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Using auto (C++11)
    cout << "Using auto iterator: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Range-based for loop (C++11)
    cout << "Using range-based for loop: ";
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // List with iterators
    cout << "\n--- List example ---" << endl;
    list<string> names = {"Alice", "Bob", "Charlie"};
    
    cout << "List elements: ";
    for (list<string>::iterator it = names.begin(); it != names.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Reverse iterators
    cout << "\n--- Reverse iterator example ---" << endl;
    cout << "Vector in reverse: ";
    for (vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    
    // Iterator with algorithms
    cout << "\n--- Algorithm with iterators example ---" << endl;
    auto min_it = std::min_element(vec.begin(), vec.end());
    auto max_it = std::max_element(vec.begin(), vec.end());
    
    cout << "Min element: " << *min_it << endl;
    cout << "Max element: " << *max_it << endl;
    
    // Find with iterators
    cout << "\n--- Find with iterators example ---" << endl;
    auto find_result = find(vec.begin(), vec.end(), 3);
    if (find_result != vec.end()) {
        cout << "Found element: " << *find_result << " at position: " 
             << distance(vec.begin(), find_result) << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}