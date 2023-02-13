#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> g[N];
int visited[N], dist[N], p[N], n, q;


void boost(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
}

void addEdje(int x,int y){
	g[x].push_back(y);
	// g[y].push_back(x);
}

int bfs(int a,int b){
	queue<int> q;
	q.push(a);
	visited[a] = 1;
	dist[a] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i : g[u]){
			if(i == b) return 999;
		}
	}

	return 0;
}

int main(){
	boost();

	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;cin >> x;
			if(x)addEdje(i,j);
		}
	}

	while(q--){
		int a,b,c;cin >> a >> b >> c;
		if(bfs(a,b) and bfs(a,c) and bfs(b,c))cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}