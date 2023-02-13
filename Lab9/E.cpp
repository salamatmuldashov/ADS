#include <bits/stdc++.h>

using namespace std;


void boost(){
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);

}
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


void solve(){
	string s;cin >> s;
	int n;cin >> n;
	if(n == 1){
		cout << s.size()<< '\n';
		return;
	}
	vector<int> ans = prefix_function(s);
	cout << (s.size() - ans[ans.size()-1]) * n + ans[ans.size()-1] << '\n';

}



int main(){
	boost();
	int t = 1;cin >> t;
	while(t--)solve();

}