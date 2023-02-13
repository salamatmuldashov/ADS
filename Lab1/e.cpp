#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    deque<int> boris;
    deque<int> nursik;
    for (int i = 0; i < 5; i++)
    {
        int x;cin >> x;
        boris.push_back(x);
    }
    for (int i = 0; i < 5; i++)
    {
        int x;cin >> x;
        nursik.push_back(x);
    }  
    while (!boris.empty() || !nursik.empty())
    {
        if (boris.empty())
        {
            cout << "Nursik" << " " << cnt;
            break;
        }else if (nursik.empty())
        {
            cout << "Boris" << " " << cnt;
            break;
        }
        else if (boris.front() == 0 && nursik.front() == 9)
        {
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }
        else if (boris.front() == 9 && nursik.front() == 0)
        {
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }
            
        else if (boris.front() > nursik.front())
        {
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }
        else if (nursik.front() > boris.front())
        {
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }

        
        
        
        
        cnt++;
    }
    
    
    
    
}