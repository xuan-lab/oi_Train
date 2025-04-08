/*【问题描述】
学习了约数后，小明对于约数很好奇，他发现，给定一个正整数t，总是可以找到含
有t个约数的整数。小明对于含有t个约数的最小数非常感兴趣，并把它定义为St。
例如S1=1,S2=2,S3=4,S4=6,...。
现在小明想知道，当t=100时，St是多少?即S100是多少?
【答案提交】
这是一道结果填空题，你只需要算出结果后提交即可。本题的结果作为一个整数，在
提交答案时只填写这个整数，填写多余的内容将无法得分
*/
#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
    int cnt = 0;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i == 0)
        {
            if(x/i==i) cnt +=1;
            else cnt+=2;
        }
    }
    return (cnt == 100);
}

int  main()
{
    for(int i =1;;i++)
    {
        if(check(i))
        {
            cout<<i<<'\n';
            break;
        }
    }
return 0;
}
