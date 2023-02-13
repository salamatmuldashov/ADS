#include <bits/stdc++.h>
using namespace std;
int p[200002], cnt;
vector<int> g[200002];

int getParent(int v){
	if(v == p[v])
		return v;

	return p[v] = getParent(p[v]);
}

bool merge(int u, int v){
	u = getParent(u);
	v = getParent(v);
	if(u == v) return false;
	p[u] = v;
	return true;
}

int main(){
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		p[i] = i;
	}
	for(int i = 0; i < m; i++){
		int a,b;cin >> a >> b;
		a--;b--;
		if(a < b) g[a].push_back(b);
		else g[b].push_back(a);
	}

	int cnt = 0;
	int ans[n];
	for(int i = n-1; i >= 0; i--){
		ans[i] = cnt;
		cnt++;
		for(int j = 0; j < g[i].size(); j++){
			if(merge(i,g[i][j]))cnt--;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << '\n';
	}
}