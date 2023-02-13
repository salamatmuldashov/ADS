#include <bits/stdc++.h>
using namespace std;
string s,t;
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

void kmp(string s,string t){
	vector<int> res = prefix_function(t);
		int i = 0, j = 0;
		while(i < s.size()){
		if(s[i] == t[j]){
			j++;
			i++;
		}
		else{
			if(j != 0) j = res[j-1];
			else i++;
		}

		if(j == t.size()){
			v.push_back((i-t.size()));
			}

		}
		
}



int main(){
	boost();
	cin >> s >> t;
	s+=s;
	kmp(s,t);
	if(!v.size()) cout << -1;
	else cout << t.size()-v[v.size()-1];


	

	

	
	
	
	

	
}