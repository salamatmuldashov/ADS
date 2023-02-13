#include <bits/stdc++.h>
using namespace std;
string isPrime(int n){
    if (n == 1)
    {
        return "NO";
    }
    
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            return "NO";
        }
        
    }
    
    return "YES";
}

int main(){
    int n;cin >> n;
    cout << isPrime(n);
}