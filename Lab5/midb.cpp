#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){
int n;cin >> n;
vector<int> v;   // vector of prime numbers
for(int i = 1; i <= n; i++){
    if(isPrime(i)){
        v.push_back(i);    
    }
}

for(int i =0; i < v.size();i++){
    for(int j = i + 1; j < v.size()-1; j++){
        if(v[i] + v[j] == n){
            cout << v[i] << " " << v[j];
            return 0;
        }
    }
}





}