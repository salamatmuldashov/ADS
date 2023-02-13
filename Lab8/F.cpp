#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
const long long mod = (long long)1e18 + 7;
const long long p = 31;

unordered_set<long long> st;
void answer(string s){
	vector<long long> p_pow(s.size());
	p_pow[0] = 1;
	for(size_t i = 1; i < s.size(); i++){
		p_pow[i] = (p_pow[i] * p_pow[i-1]) % mod;
	}
	vector<long long> h(s.size());
	for(size_t i = 0; i < s.size(); i++){
		h[i] = ((s[i]-'a' + 1) * p_pow[i]) % mod;
		if(i) h[i] = (h[i] + h[i-1]) % mod;
	}

	for(long long i = 0; i < s.size(); i++){
		long long d = 0;
		for(long long j = i; j < s.size(); j++){
			d = (d * p + s[j]) % mod;
			if(st.count(d) == 0) st.insert(d);
		}
	}
	cout << st.size();

}

int main(){
	string s; cin >> s;
	answer(s);
	

	return 0;
}
