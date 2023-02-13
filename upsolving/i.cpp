#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;cin >> t;
    while(t--){
        ll n; cin >> n;
        stack<char> st;
        string s;
        while (n!=0)
        {
            s.push_back((n%2) + '0');
            n/=2;
        }
        cout << s << '\n';
        for(int i = 0; i < s.size(); i++){
            if(!st.empty()){
                if(s[i] == '1' and st.top() == '0'){
                    st.pop();
                }else st.push(s[i]);
            }
            else st.push(s[i]);
            
        }
        if(st.empty()) cout << "YES\n";
        else cout << "NO\n"; 
        
    }
}