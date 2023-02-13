#include <bits/stdc++.h>
using namespace std;
const int N = 101;
bool visited[N];
vector <int> adj[N];
int dist[N];
int p[N];


void boost(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
}
void addEdje(int x, int y){
    adj[x].push_back(y);
    // adj[y].push_back(x);
}

void bfs(int u,int v){
    queue<int> q;
    visited[u] = 1;
    q.push(u);
    dist[u] = 0;
    p[u] = -1;

    while (!q.empty())
    {
       int x = q.front();
       q.pop();
       vector<int> :: iterator it;

       for ( it = adj[x].begin(); it != adj[x].end(); it++)
       {
           if (!visited[*it])
           {
               visited[*it] = 1;
               q.push(*it);
               dist[*it] =  dist[x] + 1;
               p[*it] = x; 
           }
           
       }
       
    }
    
   if (dist[v] == 0)
   {
       cout << -1;
       
   }
   else
   {
       cout << dist[v] << "\n";
   }
   

}

int main(){
    boost();
    int n;cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++){
            int x;cin >> x;
            if(x)addEdje(i,j);
        }
    }

    int a,b;cin >> a >> b;
    // bfs(a,b);
    cout << endl;

    for(int i = 1; i <= n;i++){
        cout << i << ": " << " ";
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }



    return 0;
}