#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int phi(int n)
{
    int result = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            result -= result/i;
        }
    }

    if(n>1)
    {
        result -= result/n;
    }
    return result;
    
}
int main()
{
    int n;
    cin>>n;
    cout<<gcd(10,15)<<endl;
    cout<<__gcd(10,15)<<endl;
    cout<<phi(n)<<endl;
    return 0;
}