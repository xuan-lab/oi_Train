#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int cnt[26];
    int ans;
    cin>>a;
    for(int l=0;l<a.length();l++)
    {
        for(int r=l;r<a.length();r++){
            for(int i=0;i<=25;i++)cnt[i]=0;
            for(int i=l;i<=r;i++) cnt[a[i]-'a']++;
            int res = 0;
            for(int i=0;i<=25;i++) if(cnt[i]>0) res++;
            ans+=res;
        }
    }
    cout<<ans<<'\n';
    return 0;
}