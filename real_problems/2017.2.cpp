#include<bits/stdc++.h>
using namespace std;

bool is_prime(int a)
{
    if(a <= 1)
        return false;
    if(a == 2 || a == 3)
        return true;
    if(a % 2 == 0)
        return false;
    
    int sqrt_a = sqrt(a);
    for(int i = 3; i <= sqrt_a; i += 2)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    const int LENGTH = 10;
    int max_check = 1000000; 
    
    for(int d = 1; ; d++)
    {
        for(int start = 2; start + (LENGTH-1)*d < max_check; start++)
        {
            if(!is_prime(start))
                continue;
            bool valid = true;
            // Check if all numbers in the sequence are prime
            for(int i = 1; i < LENGTH; i++)
            {
                int next = start + i*d;
                if (next >= max_check) {
                    valid = false;
                    break;
                }
                if(!is_prime(next))
                {
                    valid = false;
                    break;
                }
            }
            
            if(valid)
            {
                cout << "Minimum difference: " << d << endl;
                cout << "Sequence: ";
                for(int i = 0; i < LENGTH; i++)
                {
                    cout << start + i*d << " ";
                }
                cout << endl;
                return 0;
            }
        }
        
        if(d % 100 == 0)
            cout << "Checked difference up to: " << d << endl;
    }
    
    return 0;
}