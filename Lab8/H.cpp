#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
const long long p = 31;
const int N = 5000;
string ans;
vector<long long> p_pow(N);
void run(){
	p_pow[0] = 1;
	for(size_t i = 1; i < N; i++){
		p_pow[i] = (p_pow[i-1] * p) % mod;
	}
}
bool rabinKarp(string s, string t){
	long long nS = s.size();
	long long nT = t.size();
	
	vector<long long> h(nS, 0);
	for(size_t i = 0; i < nS; i++){
		h[i] = ((s[i]-'a' + 1) * p_pow[i]) % mod;
		if(i) h[i] = (h[i] + h[i-1]) % mod;
	}
	
	long long h_t = 0;
	for(size_t i = 0; i < nT; i++){
		h_t = (h_t + ((t[i] - 'a' + 1) * p_pow[i]) % mod) % mod;
	}

	for(size_t i = 0; i+nT - 1 < nS; i++){
		long long cur = h[i + nT - 1];
		if(i) cur = (cur - h[i-1] + mod) % mod;
		if(cur == (h_t * p_pow[i]) % mod){
			return true;
		}
	}
	
	return false;
}


int main(){
	long long n;cin >> n;
	string arr[n];
	string s,s1;
	long long mn = INT_MAX;
	for(long long i = 0; i < n; i++){
		cin >> arr[i];
		if(mn > arr[i].size()){
			mn = arr[i].size();
			s = arr[i];
		}
		
	}
	run();
	long long mx = 0;
	for(int i = 0; i < s.size();i++){
		for(int j = i; j < s.size(); j++){
			bool ok = true;
			string patt = s.substr(i, s.size()-j);
			for(int k = 0; k < n; k++){
				if(arr[k] == s) continue;
				if(rabinKarp(arr[k], patt) == false){
					ok = false;
					break;
				}
			}
			if(ok){
				if(mx < patt.size()){
					mx = patt.size();
					ans = patt;
				}
			}
		}
	}
	cout << ans;


	return 0;

}