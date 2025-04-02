#include<iostream>
using namespace std;
int num[110];
long long ans=1;
int main()
{
    for(int i=1;i<=100;i++)
    {
        int x = i;
        for(int j=2;j*j<=x;j++)
        {
            if(x%j==0)
            {
                while (x%j==0)
                {
                    x/=j;
                    num[j]++;
                }
            }
        }
        if(x>1)
        {
            num[x]++;
        }
    }
    for(int i =1;i<=100;i++)
    {
        if(num[i]!=0)
        {
            ans = ans*(num[i]+1);
        }
    }
    cout<<ans<<'\n';
    return 0;
}