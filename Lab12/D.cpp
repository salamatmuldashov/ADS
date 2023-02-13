#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int> > g[MAXN];
set<pair<int, int> > st;
int n;
int d[MAXN];
void dijkstra(int s){
    for(int i = 1; i <= n; i++){
        if(i == s)d[i] = 0;
        else d[i] = INF;
        st.insert(make_pair(d[i], i));
    }

    for(int i = 0 ; i < n; i++){
        pair<int, int> p = *(st.begin());
        st.erase(p);
        int du = p.first;
        int u = p.second;
        

        if(du == INF) break;

        for(int j = 0; j< g[u].size(); j++){
            p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > w && d[v] > d[u]){
                st.erase(make_pair(d[v], v));
                d[v] = max(d[u], w);
                st.insert(make_pair(d[v], v));
            }
        }
    }
}

int main(){
    cin >> n;
    pair<int, int> v[n];
    for(int i = 0; i < n ; i++){
        int x, y; cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = abs(v[i].first - v[j].first) + abs(v[i].second-v[j].second);
            g[j+1].push_back(make_pair(i+1, w));
            g[i+1].push_back(make_pair(j+1, w));
        }
    }
    dijkstra(1);
    cout << d[n];

}