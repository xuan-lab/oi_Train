#include<iostream>
using namespace std;
void budding_sort(int arr[],int len){
    for(int i=0;i<len-1;i++){
        bool swapped=false;
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main()
{
    int arr[]={1,7,5,3,9,4};
    budding_sort(arr,6);
    for(int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Time Complexity: O(n^2)
// Space Complexity: O(1)  