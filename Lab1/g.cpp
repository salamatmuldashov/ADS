#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        
    }
    return true;
    
}

int main(){
    int x;cin >> x;
    int i = 0;
    int cnt = 0;
    int num = 2;
    while (true)
    {
        if (isPrime(num))
        {
            i++;
            if (isPrime(i))
            {
                cnt++;
            }
            
        }

        if (cnt == x)
        {
            cout << num;
            break;
        }
        
        num++;
    }
    
    
    
}