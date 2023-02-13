#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int p = 31;
void rabinKarp(string s, string t, vector<long long> & mp){

	vector<long long> v;
	long long cnt = 1;
	long long nS = s.size();
	long long nT = t.size();
	vector<long long> p_pow(nS);
	p_pow[0] = 1;
	for(size_t i = 1; i < nS; i++){
		p_pow[i] = (p_pow[i-1] * p) % mod;
	}
	
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
			for(long long j = i; j < nT+i; j++){
				mp[j]++;
			}
		}
	}
}


int main(){
	string s;cin >> s;
	vector<long long> mp(s.size(), 0);
	long long n;cin >> n;
	for(int i = 0; i < n; i++){
		string t;cin >> t;
		rabinKarp(s,t, mp);
	}

	for(long long i = 0; i < mp.size(); i++){
		if(mp[i] == 0){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES" << '\n';

	return 0;
}
