#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin >> n;
    deque<int> d;
    for (int i = n; i > 0; i--)
    {
        d.push_back(i);
        for (int j = 0; j <= i; j++)
        {
            d.push_front(d.back());
            d.pop_back();
        }
        
    }
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    

    
    
}
int main(){
    int n;cin >> n;
    while (n--)
    {
       solve();
    }
    
    return 0;
}