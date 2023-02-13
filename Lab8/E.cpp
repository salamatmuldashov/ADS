#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e15 + 9;
const long long p = 2;
void rabinKarp(long long n, long long a[]){
	string s = "";
	vector<long long> p_pow(n);
	p_pow[0] = 1;
	for(size_t i = 1; i < n; i++){
		p_pow[i] = (p_pow[i-1] * p) % mod;
	}	
	vector<long long> h(n);
	for(size_t i = 0; i < n; i++){
		long long x = (a[i] / p_pow[i] + 97) % mod;
		if(i) x = ((a[i] - a[i-1]) / p_pow[i] + 97) % mod;
		s+=x;
	}
	
	cout << s;

	
}


int main(){
	long long n;cin >> n;
	long long a[n];
	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	rabinKarp(n, a);
	
	
	

	return 0;
}
