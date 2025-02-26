#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int now_max,plus_num=0;
    int num[10000];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    
    now_max = num[0];
    for(int j = 1;j<n;j++)
    {
        if(num[j]>now_max)
        {
            plus_num++;
            now_max = num[j];
        }
    }
    cout<<plus_num+1;
}