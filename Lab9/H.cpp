#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
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


int main(){
	boost();
	cin >> s;
	int cnt = 0;
	vector<int> ans = prefix_function(s);
	cout << endl;
	for(int i = 2; i < ans.size(); i+=2){
		int period = i - ans[i-1];
		if((i / period) % 2 == 0)cnt++;

	}
	cout << cnt;

	
}