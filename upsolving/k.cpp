#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;cin >> q;
    deque<int> dq;
    int cnt = 0;
    bool ok = false;
    while (q--)
    {
        int x,y;
        cin >> x;
        if(x == 1){
            cin >> y;
            if(!ok) dq.push_back(y);
            else dq.push_front(y);
        }

        else if (x == 2)
        {
            cnt++;
            if(!ok) ok = true;
            else ok = false;   
        }
        
    }
    if(cnt % 2 == 1 ){
        while (!dq.empty())
        {
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    else{
        while (!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        
    }
}

