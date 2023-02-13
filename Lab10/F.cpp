#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = -1 * (int)1e9;
vector<int> g[N];
int visited[N], dist[N], p[N], n, m;


void boost(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
}

void addEdje(int x,int y){
	g[x].push_back(y);
	g[y].push_back(x);
}

void bfs(int a){
	queue<int> q;
	q.push(a);
	visited[a] = 1;
	dist[a] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int it : g[u]){
			if(!visited[it]){
				visited[it] = 1;
				q.push(it);
				dist[it] = dist[u] + 1; 
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
	cout << '\n';
	int s,f;cin >> s >> f;
	bfs(s);
	if(!dist[f])cout << "NO\n";
	else cout << "YES\n";

	return 0;
}