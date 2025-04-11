/*
小明对数位中含有2、0、1、9 的数字很感兴趣（不包括前导0）
在1到40中这样的数包括1、2、9、10 至32、39 和40，共28 个，他们的和是574。
请问，在1到n 中，所有这样的数的和是多少？*/
#include<iostream>
using namespace std;
int check(int n)
{
    if(n==2||n==0||n==1||n==9)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;cin>>n;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        int k = i;
        while(k/10)
        {
            int l=k%10;
            if(check(l))
            {
                num+=i;
                break;
            }
            k=k/10;
        }

        if (check(k)) {
            num += i;
        }
        }
    cout<<num;
}
