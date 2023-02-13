#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<int> v;
int main(){
    int k;cin >> k;
    int n;cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;cin >> x;
        v.push_back(x);
    }
    unordered_map<int,int> m;

    for(int i = 0; i < v.size(); i++){
        int x = k - v[i];
            if(m.find(x) != m.end()){
                cout << x << " " << v[i] << '\n';
                // return 0;
            }
            m[i] = x; 
    }
    for(int i = 0; i < m.size();i++){
        cout << m[i] << " ";
    }
}