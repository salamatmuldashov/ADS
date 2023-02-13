#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    stack<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;cin >> x;
        v.push_back(x);
    }
    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }
    stack<int> t;
    cout << -1 << " ";
    while (s.size() != 1)
    {
       int x = s.top();
       s.pop();

       if (s.top() < x)
       {
        if (t.empty())
        {
            cout << -1 << " ";
        }else
        {
            while (!t.empty() && t.top() > s.top()) t.pop();
            if (t.empty())
            {
                cout << -1 << " ";
            }
            else cout << t.top() << " ";
        }
       }else{
        cout << x << " ";
        t.push(x);
       }
       

       
    }
    
   
    
    
    
    
    
    
}