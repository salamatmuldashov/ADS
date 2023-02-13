#include <bits/stdc++.h>
using namespace std;
vector<pair<string,int> > ans;
int mx = 0,cnt = 0;
vector<int> prefix_function(string s){
	int n = s.size();
	vector<int> pi(n,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 and s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}

	return pi;

}

int main(){
	string s;cin >> s;
	s[0]+=32;
	int t;cin >> t;
	while(t--){
		string t;cin >> t;
		string l = t;
		t[0]+=32;
		t+=s;
		vector<int> pi = prefix_function(t);
		ans.push_back({l, pi[pi.size()-1]});
		mx = max(mx, pi[pi.size()-1]);

	}

	for(auto i : ans){
		if(i.second != 0){
			if(i.second == mx)cnt++;
		}
		
	}
	if(!cnt){ cout << 0 << '\n'; return 0;}
	cout << cnt << '\n';
	for(auto i : ans){
		if(i.second == mx)cout << i.first << "\n";
	}

	

}