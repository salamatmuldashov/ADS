#include <bits/stdc++.h>

using namespace std;
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
	string t;cin >> t;
	string s;cin >> s;
	vector<int> res = prefix_function(t);
	vector<int> ans;
	int i = 0, j = 0, pos = -1,cnt = 0;
	while(i < t.size()){
		if(t[i] == s[j]){
			j++;
			i++;
		}
		else{
			if(j != 0) j = res[j-1];
			else i++;
		}

		if(j == s.size()){
			cnt++;
			ans.push_back(i-s.size());
		}

	}
	cout << cnt << "\n";
	for(auto i : ans){
		cout << i+1 << " ";
	}
	

	
}