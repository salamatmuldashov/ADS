#include <bits/stdc++.h> 

using namespace std;
const int N = 5001;

vector<int> g[N];
int visited[N], dist[N], n, m, q, color[N], p[N]; // 0 - black, 1 - red
int cnt = 0; bool ok = false;
bool ok1 = false;

void boost(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
}

void addEdje(int x,int y){
	g[x].push_back(y);
	g[y].push_back(x);
}

void bfs(int v){
	visited[v] = 1;
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	p[v] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : g[u]){
			if(!visited[i]){
				visited[i] = 1;
				q.push(i);
				dist[i] = dist[u] + 1;
				p[i] = u; 
			}
		}
	}

}

bool isRed(int n){
	for(int i = 1; i <= n; i++){
		if(color[i] == 1){
			return true;
		}
	}
	return false;
}

int main(){
	int ans = 9999999, ans1 = 9999999;
	boost();
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int x,y;cin >> x >> y;
		addEdje(x,y);
	}

	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			bfs(i);
		}
	}
	
	while(q--){
		int x,y;cin >> x >> y;
		if(x == 1){
			color[y] = 1;
			cnt++;
		}

		else if(x == 2){
			if(p[y] == -1 and color[y] == 0) {
				cout << -1 << '\n';
				continue;
		}
			else{
				for(int i = 1; i <= n; i++){
					if(color[i] == 1){
						// if(ok){
						// 	ans = dist[y] - dist[i];
						// 	ans1 = max(ans1,ans);
						// }else{
						// 	ans = dist[y] - dist[i];
						// 	ans1 = min(ans1, ans);
						// }
						
						// if(cnt > 1){
							ans1 = min(dist[y] - dist[i], ans1);
						// }
						  

						
						
							// ans = dist[y] - dist[i];
							// ans1 = min(ans1,ans);
							// ok1 = false;
						
						
					}

					
				}
				// if(ok1) continue;
				cout << ans1 << '\n';
				ans1 = ans;
			
			}
			
		}
	}

}