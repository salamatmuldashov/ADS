#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> g[N];
int visited[N], p[N], was[N], n,cnt, m,mx;

void boost(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
}

void addEdje(int x,int y){
	g[x].push_back(y);
}

void bfs(int v){
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	p[v] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : g[u]){
			if(!visited[i]){
				visited[i] = 1;
				q.push(i);
				p[i] = u;
				was[p[i]]++;
			}
		}
	}
	

}

int main(){
	boost();
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x,y;cin >> x >> y;
		addEdje(x,y);
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			bfs(i);
			cnt++;
		}
	}

	for(int i = 1; i <= n; i++){
		int to = p[i];
		// if(to == -1)cnt++;
		if(was[to] < was[i] and to != -1)cnt++;
	}

	
	
	cout << cnt;
	
}