#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5+5 , inf = 2e9 + 7;
vector<pair<long long,long long>> g[N];
long long n , m;

vector<long long> dij(long long v) {
  vector<long long> d(n+1, inf);
  d[v] = 0;
  set<pair<long long,long long>> st;
  st.insert({0, v});
  while(st.size()) {
    pair<long long,long long> cur = *st.begin();
    st.erase(cur);
    for(auto to: g[cur.second]) {
      if(d[cur.second]+to.second < d[to.first]) {
        st.erase({d[to.first], to.first});
        d[to.first] = d[cur.second]+to.second;
        st.insert({d[to.first], to.first});
      }
    }
  }
  return d;
}

void solve(long long tc) {
  cin >> n >> m;
  for(long long i = 1; i <= m; i ++) {
    long long a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
  }
  long long s,a,b,f;
  cin >> s>>a>>b>>f;
  vector<long long> d1 = dij(s);
  vector<long long> d2 = dij(a);
  vector<long long> d3 = dij(b);
  vector<long long> d4 = dij(f);
  long long ans = min(d1[a] + d2[b] + d3[f] , d1[b]+d3[a]+d2[f]);
  if(ans > inf) ans = -1;
  cout << ans;
}

int main() {
   solve(1);
}