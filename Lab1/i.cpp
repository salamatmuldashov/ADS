#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    queue<int> q;
    queue<int> q1;
    string s;cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'K')
        {
            q.push(i+1);
        }
        else q1.push(i+1);
        
    }

    
    
    while (true)
    {
        if (q.empty())
        {
            cout << "SAKAYANAGI";
            break;
        }
        if (q1.empty())
        {
            cout << "KATSURAGI";
            break;
        }
        
        if (q.front() < q1.front())
        {
            q1.pop();
            q.push(q.front() + n);
            q.pop();
        }
        else if (q.front() > q1.front())
        {
            q.pop();
            q1.push(q1.front()+ n);
            q1.pop();
        }
        
        
    }
    

    
    
    
    



    
    

    
    
    return 0;

}