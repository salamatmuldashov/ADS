#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    vector<char> v,v1;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '#')
        {
            v.pop_back();
        }else v.push_back(s[i]);
        
    }
    for (int i = 0; i < t.size(); i++)
    {

        if (t[i] == '#')
        {
            v1.pop_back();
        }else v1.push_back(t[i]);
        
    }
    if (v.size() == v1.size())
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != v1[i])
            {
                cout << "No";
                return 0;
            }
            
        }
        cout << "Yes";
        
    }else cout << "No";
    
    
    
}