#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        } 
    }

    return true;
}
int main(){
    int n;cin >> n;
    for(int i = 2; i < n-1; i++){
        if(isPrime(i) and isPrime(n-i)){
            cout << i << " " << n-i << '\n';
            return 0;
        }
    }
    

    


}