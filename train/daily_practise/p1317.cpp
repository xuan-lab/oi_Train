#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    
    vector<int> v;
    v.push_back(heights[0]);
    for (int i = 1; i < n; i++){
        if(heights[i] != heights[i-1]){
            v.push_back(heights[i]);
        }
    }
    
    int count = 0;
    for (int i = 1; i < v.size() - 1; i++){
        if(v[i] < v[i-1] && v[i] < v[i+1]){
            count++;
        }
    }
    
    cout << count;
    return 0;
}
