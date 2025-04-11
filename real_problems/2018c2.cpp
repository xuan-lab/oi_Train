/*5只猴子是好朋友，在海边的椰子树上睡着了。这期间，有商船把一大堆香蕉忘记在沙滩上离去。
第1只猴子醒来，把香蕉均分成5堆，还剩下1个，就吃掉并把自己的一份藏起来继续睡觉。
第2只猴子醒来，重新把香蕉均分成5堆，还剩下2个，就吃掉并把自己的一份藏起来继续睡觉。
第3只猴子醒来，重新把香蕉均分成5堆，还剩下3个，就吃掉并把自己的一份藏起来继续睡觉。
第4只猴子醒来，重新把香蕉均分成5堆，还剩下4个，就吃掉并把自己的一份藏起来继续睡觉。
第5只猴子醒来，重新把香蕉均分成5堆，哈哈，正好不剩！
请计算一开始最少有多少个香蕉。*/

#include <iostream>
using namespace std;
int main() {
    int n = 1; // Start with 1 banana
    while (true) {
        int bananas = n;
        bool valid = true;
        for (int i = 0; i < 5; i++) {
            if (bananas % 5 != i) { // Check the remainder condition
                valid = false;
                break;
            }
            bananas -= bananas / 5 + 1; // Remove the eaten bananas
        }
        if (valid && bananas == 0) { // Check if all bananas are eaten
            cout << n << endl; // Output the result
            break;
        }
        n++; // Increment the number of bananas
    }
    return 0;
}