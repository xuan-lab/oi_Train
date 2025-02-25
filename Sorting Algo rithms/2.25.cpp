#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::swap

using namespace std;

// 辅助函数：打印数组内容
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

/*
 * 冒泡排序（Bubble Sort）
 * 时间复杂度：O(n^2)
 * 优化技巧：如果某一趟没有发生交换，则数组已排序，可提前退出循环
 */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // 标记这一趟是否进行了数据交换
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // 如果没有交换，提前退出
        if (!swapped) {
            break;
        }
    }
}

/*
 * 选择排序（Selection Sort）
 * 时间复杂度：O(n^2)
 * 思路：在未排序部分找到最小值，并与当前排序边界交换
 */
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // 假设当前位置最小
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 边界条件：当最小元素不在当前位置时才交换
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

/*
 * 插入排序（Insertion Sort）
 * 时间复杂度：O(n^2)
 * 思路：将当前元素插入到已排序部分的合适位置
 */
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // 移动大于 key 的元素，为 key 腾出位置
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // 原始测试数组，可以自行修改测试数据
    vector<int> arr = {64, 25, 12, 22, 11};

    // 分别复制数组用于不同排序算法
    vector<int> arrBubble = arr;
    vector<int> arrSelection = arr;
    vector<int> arrInsertion = arr;

    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arrBubble);
    cout << "Sorted using Bubble Sort (with optimization): ";
    printArray(arrBubble);

    selectionSort(arrSelection);
    cout << "Sorted using Selection Sort: ";
    printArray(arrSelection);

    insertionSort(arrInsertion);
    cout << "Sorted using Insertion Sort: ";
    printArray(arrInsertion);

    return 0;
}