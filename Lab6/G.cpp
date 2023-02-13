#include <bits/stdc++.h>
using namespace std;
vector<pair<string,string> > v;
map<string,string> mp;
int main(){
    int n;cin >> n;
    bool ok;
    for(int i = 0; i < n; i++){
        ok = false;
        string s,t; cin >> s >> t;
        for(int j = i - 1; j>=0; j--){
            if(v[j].second == s){
                v[j].second = t;
                ok = true;
                break;
            }
        }
        if(!ok) v.push_back(make_pair(s,t));
        

    }

    for(int i = 0; i < v.size(); i++){
        mp.insert(make_pair(v[i].first, v[i].second));
    }
    cout << mp.size() << '\n';
    for(map<string,string> :: iterator it = mp.begin(); it!=mp.end(); it++){
        cout << it->first << " " << it->second << '\n';
    }
    

}