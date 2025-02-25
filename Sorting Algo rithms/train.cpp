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
void selection_sort(int arr[],int len){
    for(int i=0;i<len-1;i++){
        int min_index=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

void insertion_sort(int arr[],int len){
    for(int i=1;i<len;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={1,7,5,3,9,4};
    budding_sort(arr,6);
    //selection_sort(arr,6);
    //insertion_sort(arr,6);
    for(int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}