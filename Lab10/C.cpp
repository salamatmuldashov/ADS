// #include <bits/stdc++.h>
// using namespace std;
// vector<int> path;
// void dfs(int x,int y){

// path.push_back(y);
// if(y<x){
// 	dfs(x,y+1);
// }
// else if(y==x){
// 	path.pop_back();
// 	return;
// }
// else if(y%2!=0){
// 	dfs(x,y+1);
// }
// else{
// 	dfs(x,y/2);
// }

// }
// int main(){
// int a,b;
// cin>>a>>b;
// dfs(a,b);
// cout<<path.size()<<endl;
// for(int i=path.size()-1;i>=0;i--){
// cout<<path[i]<<" ";
// }





// return 0;	
// }
#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b;cin >> a >> b;
	vector<int> v;
	while(a != b){
		v.push_back(b);
		if(a > b){
			b++;
		}
		else if(b & 1){
			b++;
		}
		else{
			b/=2;
		}
	}
	cout << v.size() << '\n';
	for(int i = v.size()-1; i >= 0; i--){
		cout << v[i] << " ";
	}

}