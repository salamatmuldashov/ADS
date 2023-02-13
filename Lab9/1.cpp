#include <bits/stdc++.h> 
using namespace std;
const int N = 1e3 + 3;;
vector<int> adj[N];
int n,q;
bool used[N];
int dist[N];

// void addEdje(int i, int j){
// 	adj[i].push_back(j);
// 	// adj[j].push_back(i);
// }

// void bfs(int v){
// 	queue<int> q;
// 	q.push(v);
// 	used[v] = 1;
// 	dist[v] = 0;
// 	while(!q.empty()){
// 		int x = q.front();
// 		q.pop();

// 		for(int u : adj[v]){
// 			if(!used[u]){
// 				used[u] = true;
// 				q.push(u);
// 				dist[u]+=1;
// 			}
// 		}
// 	}
// }

int main(){
	// cin >> n >> q;
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		int x;cin >> x;
	// 		if(x) addEdje(i,j);
	// 	}
	// }
	// for(int i = 1; i <= n; i++){
	// 	bfs(i);
	// }

	// for(int i = 0; i <dist.size(); i++){
	// 	cout << dist[i] << " ";
	// }
	// while(q--) {
	//     int x,y,z; cin >> x >> y >> z;

	// }



}