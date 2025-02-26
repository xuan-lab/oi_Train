#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"请输入n：";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}