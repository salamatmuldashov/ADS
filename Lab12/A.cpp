#include <bits/stdc++.h> 
using namespace std;
const long long N = 500+5 , inf = 2e9 + 7;
long long a[N][N], mn[N][N], x[N], u[N], n;
 

void solve(long long tc) {
  cin >> n;
  for(size_t i = 1; i <= n; i ++) {
    for(size_t j = 1; j <= n; j ++) {
      cin >> a[i][j];
      mn[i][j] = inf;
    }
  }
  for(size_t i = 1; i <= n; i ++) {
    cin >> x[i];
    long long ans = 0;
    for(size_t j = 1; j <= i; j ++) {
      mn[x[j]][x[i]] = a[x[j]][x[i]];
      mn[x[i]][x[j]] = a[x[i]][x[j]];
    }
    for(size_t k = 1; k <= i; k ++) {
      for(size_t t = 1; t <= i; t ++) {
        mn[x[t]][x[i]] = min(mn[x[t]][x[i]] , mn[x[t]][x[k]] + mn[x[k]][x[i]]);
      }
    }
    for(size_t k = 1; k <= i; k ++) {
      for(size_t t = 1; t <= i; t ++) {
        mn[x[i]][x[t]] = min(mn[x[i]][x[t]] , mn[x[i]][x[k]] + mn[x[k]][x[t]]);
      }
    }
    for(size_t k = 1; k <= i; k ++) {
      for(size_t t = 1; t <= i; t ++) {
        mn[x[k]][x[t]] = min(mn[x[k]][x[t]] , mn[x[k]][x[i]] + mn[x[i]][x[t]]);
        if(mn[x[k]][x[t]] < inf) {
          ans = max(ans, mn[x[k]][x[t]]);
        }
      }
    }
    cout << ans << '\n';
  }
}

int main() {
    solve(1);
}