#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;


ll getHash(string s){
	long long v[s.size()];
	v[0] = 1;
	for(int i = 1; i < s.size(); i++){
		v[i] = (v[i-1] * 11) % mod;
	}

	ll h_s = 0;
	for(int i = 0; i < s.size(); i++){
		h_s += (s[i] - 47) * v[i] % mod;
	}

	return h_s % mod;

}


int main(){
	map<string,int> mp;
	vector<string> strings;
	ll n;cin >> n;
	n*=2;
	for(ll i = 0; i < n; i++){
		string s;cin >> s;
		mp[s] = 1;
		strings.push_back(s);
	}
	n/=2;
	int cnt = 0;

	for(auto x : strings){
		if(cnt == n){
			break;
		}
		string hash = to_string(getHash(x));
		if(mp[hash] == 1){
			cout<<"Hash of string "<<'"'<<x<<'"'<<" is "<<hash<< '\n';
			cnt++;
		}		
	}

	

	
}