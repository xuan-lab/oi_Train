#include<iostream>
using namespace std;
int main()
{
    int num[26] = {0};  
    string word;
    int max = 0;
    char result = 'a';
    cin >> word;
    for(int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        num[index]++;
        if(num[index] > max)
        {
            max = num[index];
            result = word[i];
        }
    }
    cout<<result<<" "<<max<<endl;
    return 0;
}
