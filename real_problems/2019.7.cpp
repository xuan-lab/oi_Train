#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> values(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> values[i];
    }
    
    // Calculate sum for each depth
    vector<long long> depthSum;
    int depth = 1;
    int nodesAtDepth = 1;
    int currentNode = 1;
    
    while (currentNode <= N) {
        long long sum = 0;
        int count = 0;
        
        // Sum all nodes at current depth
        while (count < nodesAtDepth && currentNode <= N) {
            sum += values[currentNode];
            currentNode++;
            count++;
        }
        
        depthSum.push_back(sum);
        nodesAtDepth *= 2;  // Number of nodes at next depth
        depth++;
    }
    
    // Find the depth with maximum sum
    long long maxSum = LLONG_MIN;
    int maxSumDepth = 0;
    
    for (int i = 0; i < depthSum.size(); i++) {
        if (depthSum[i] > maxSum) {
            maxSum = depthSum[i];
            maxSumDepth = i + 1;  // +1 because depths are 1-indexed
        }
    }
    
    cout << maxSumDepth << endl;
    
    return 0;
}
