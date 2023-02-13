#include <bits/stdc++.h>
using namespace std;

long long p[200002], ans,w;
pair<long long, pair<long long, long long> > v[200002];

long long getParent(long long v){
	if(v == p[v]){
		return v;
	}
	return p[v] = getParent(p[v]);
}

long long merge(long long u, long long v, long long r){
	u = getParent(u);
	v = getParent(v);
	if(u == v)return v;
	p[u] = v;
	ans+=w;
	return v;
}
	
int main(){
	long long n,m;cin >> n >> m;
	for(long long i = 0; i < m; i++){
		vector<long long> cr;
		long long l,r,w;cin >> l >> r >> w;
		l--;r--;
		v[i] = {w,{l,r}};
	}

	for(long long i = 0; i < n; i++){
		p[i] = i;
	}
	sort(v,v+m);
	for(long long i = 0; i < m; i++){
		w = v[i].first;
		for(long long j = v[i].second.first; j<= v[i].second.second; j++){
			j = merge(v[i].second.first, j, v[i].second.second);   
			if(j > v[i].second.second) break;
		}
	}

	cout << ans;

}