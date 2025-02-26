#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    for(int j:arr)
    {
        cout<<j<<" ";
    }
    arr.push_back(52);
    cout<<"what more?\n";
    int k;
    cin>>k;
    arr.push_back(k);
    for(int i :arr)
    {
        cout<<i<<" ";
    }
    cout<<"i will erase\n";
    arr.erase(arr.begin(),arr.end()-2);

    for(int i :arr)
    {
        cout<<i<<" ";
    }
    arr.clear();
    cout<<"clear"<<endl;
    return 0;
}