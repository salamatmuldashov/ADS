#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> g[N];
int visited[N], n, m;
vector<int> naruto;
bool ok = false;

void boost(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
}

void addEdje(int x,int y){
	g[x].push_back(y);
}

void dfs(int v){

	visited[v] = 1;
	for(int i : g[v]){
		if(visited[i] == 1){
			ok = 1;
		}
		if(!visited[i]){
			dfs(i);
		}
	}
	visited[v] = 2;
	naruto.push_back(v);


}

int main(){
	boost();
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y;cin >> x >> y;
		addEdje(x,y);		
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}

	if(ok){
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for(int i = naruto.size()-1; i >= 0; i--){
		cout << naruto[i] << " ";
	}

	
}