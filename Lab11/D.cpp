#include <bits/stdc++.h>

using namespace std;
int p[501], a[501];
pair<long long, pair<long long, long long> > v[200002];
int getParent(int v){
	if(v == p[v]) return v;
	return p[v] = getParent(p[v]);
}
void merge(int u, int v){
	u = getParent(u);
	v = getParent(v);
	p[u] = v;
}

long long kruskal(int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		int a = v[i].second.first;
		int b = v[i].second.second;
		int weight = v[i].first;
		if(getParent(a) != getParent(b)){
			ans+=weight;
			merge(a,b);
		}
	}

	return ans;
}
int main(){
	int n;cin >> n;
	for(int i = 0; i < n; i++){
		p[i] = i;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;cin >> x; 
			v[cnt] = {x,{i,j}};
			cnt++;
		}
	}
	

	sort(v, v+cnt);

	cout << kruskal(cnt);
}