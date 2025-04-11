#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;          // 定义字符串变量存储输入
    int cnt[26];       // 定义计数数组，用于记录每个字母出现的次数
    int ans;           // 定义答案变量，存储所有子串中不同字符数量的总和
    cin>>a;            // 输入字符串
    
    // 外层循环：枚举子串的起始位置l
    for(int l=0;l<a.length();l++)
    {
        for(int i=0;i<=25;i++)cnt[i]=0;  // 重置计数数组，准备统计新的子串
        int res = 0;                      // res记录当前子串中不同字符的数量
        
        // 内层循环：枚举以l为起始位置的所有子串（通过扩展右端点r）
        for(int r=l;r<a.length();r++){ 
           if(cnt[a[r]-'a']==0) res++;    // 如果当前字符是第一次出现，不同字符数量加1
           cnt[a[r]-'a']++;               // 将当前字符的出现次数加1
           ans+=res;                      // 将当前子串的不同字符数量加入总和
        }
    }
    cout<<ans<<'\n';   // 输出所有子串中不同字符数量的总和
    return 0;
}