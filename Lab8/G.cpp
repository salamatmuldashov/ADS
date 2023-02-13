#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int p = 31;

long long rabinKarp(string s, string t){
	long long cnt = 0;
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
		if(cur == (h_t * p_pow[i]) % mod and t == s.substr(i, nT)){
			cnt++;
		
		}
	}
	return cnt;
}


int main(){
	string s; cin >> s;
	int q;
	cin >> q;
	vector<long long> ans;
	while(q--){
		string t = "";
		int l,r;cin>>l>>r;
		for(int i = l-1; i < r; i++){
			t+=s[i];
		}

		ans.push_back(rabinKarp(s, t));
	}

	for(size_t i = 0; i < ans.size(); i++){
		cout << ans[i] << '\n';
	}
	
	
	

	return 0;
}
