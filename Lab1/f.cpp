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
void PrintPrime(int x){
    vector<long long> v;
    int i = 1;
    while (v.size() != x)
    {
        if (isPrime(i))
        {
            v.push_back(i);
        }
        i++;
    }
    

    cout << v.back();
    

}
int main(){
    int n;cin >> n;
    PrintPrime(n);
    
}