#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        q.push(x);
        while (q.front() < x - 3000)
        {
            q.pop();
        }
        cout << q.size() << " ";
    }
  

    

    return 0;
}