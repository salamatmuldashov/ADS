#include <bits/stdc++.h> 
using namespace std;
const int N = 101, M = 101;
vector<vector<char> > v(N, vector<char>(M));
vector<vector<int> > visited(N, vector<int>(M));
int n,m,cnt = 0;

void boost(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
}

void dfs(int i, int j){
	int n = v.size();
	int m = v[0].size();
	visited[i][j] = 1;
	if(i+1 >= 0 and i+1 < n and j >= 0 and j < m and v[i+1][j] == '1' and !visited[i+1][j]){
		dfs(i+1,j);
	}
	if(i>=0 and i < n and j+1>= 0 and j+1 < m and v[i][j+1] == '1' and !visited[i][j+1]){
		dfs(i,j+1);
	}
	if(i-1 >= 0 and i-1 < n and j >= 0 and j < m and v[i-1][j] == '1' and !visited[i-1][j]){
		dfs(i-1,j);
	}
	if(i>=0 and i < n and j-1>= 0 and j-1 < m and v[i][j-1] == '1' and !visited[i][j-1]){
		dfs(i,j-1);
	}


}



int main(){
	boost();
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> v[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(v[i][j] == '1' and !visited[i][j]){
				dfs(i,j);
				cnt++;
			}
		}
	}



	cout << cnt;
	

}