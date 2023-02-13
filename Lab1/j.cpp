#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> d;
    char x;
    int n;
    while (cin >> x)
    {
        if (x == '!')
        {
            return 0;
        }
        else if (x == '+')
        {
            cin >> n;
            d.push_front(n);
        }
        else if (x == '-')
        {
            cin >> n;
            d.push_back(n);
        }
        else if (x == '*')
        {
            if (d.empty())
            {
                cout << "error" << "\n";
            }
            else if (d.size() == 1)
            {
                cout << d.front() + d.front() << "\n";
                d.pop_front();
            }else
            {
                cout << d.front() + d.back() << "\n";
                d.pop_front();
                d.pop_back();
            }
            
            
        }
        
    }
    

    return 0;
}