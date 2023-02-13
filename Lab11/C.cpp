#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
int p[1001];
pair<long long, pair<long long, long long> > v[1001];

int getParent(int v){
	if(v == p[v]) return v;
	return p[v] = getParent(p[v]);
}

void merge(int u, int v){
	u = getParent(u);
	v = getParent(v);
	p[u] = p[v];
}
long long kruskal(){
	long long ans = 0;
	for(int i = 0; i < m; i++){
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
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		p[i] = i;
	}
	cin >> x >> y;

	for(int i = 0; i < m; i++){
		string s;cin >> s; 
		int l,r,w; cin >> l >> r >> w; 
		if(s == "both"){
			if(y < x){
				v[i] = {y*w, {l,r}};
			}else{
				v[i] = {x*w,{l,r}};
			}
		}
		else if(s == "small"){
			v[i] = {y*w, {l,r}};
		}else{
			v[i] = {x*w,{l,r}};
		}
	}

	sort(v, v+m);
	cout << kruskal();
}