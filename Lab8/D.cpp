#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9 + 7;
const int p = 31;
long long mx = 0;
vector<pair<string, vector<int> > > mp;
void rabinKarp(string s, string t){
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
	vector<int> v1;
	for(size_t i = 0; i+nT - 1 < nS; i++){
		long long cur = h[i + nT - 1];
		if(i) cur = (cur - h[i-1] + mod) % mod;
		if(cur == (h_t * p_pow[i]) % mod){
			v1.push_back(i);
		}
	}
	
	mp.push_back({t,v1});
}


int main(){
	while(true){
		long long n;cin >> n;
		if(n == 0)break;
		string arr[n];
		for(long long i = 0; i < n; i++){
			cin >> arr[i];
		}
		string text;cin >> text;
		for(long long i = 0; i < n; i++){
			rabinKarp(text, arr[i]);
		}
		for(auto x : mp){
			if(x.second.size() > mx){
				mx = x.second.size();
			}
		}
		cout << mx << '\n';
		for(auto x : mp){
			if(x.second.size() == mx) cout << x.first << '\n';
		}
		mp.clear();
		mx = 0;

	}

	return 0;

}