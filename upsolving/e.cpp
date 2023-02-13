#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
class Stack{
    int size;
    int arr[N];
    public:
    Stack(){
        size = -1;
    }
    void add(int x){
        size++;
        arr[size] = x;
    }
    void sasuke(){
        if(size <= -1) cout << "error";
        else size--;   
    }
    void getcur(){
        if(size <= -1) cout << "error" << '\n'; 
        else cout << arr[size] << '\n';
    }

    void getmax(){
        if(size <= -1) cout << "error" << '\n'; 
        else {
        int mx = arr[0];
        for(int i = 1; i <= size; i++){
            mx = max(mx,arr[i]);
        }
        cout << mx << '\n';
        }
    }


};



int main(){
    Stack st;
    int n;cin >> n;
    string s; int x;
    while (n--)
    {
        cin >> s;
        if(s == "add"){
            cin >> x;
            st.add(x);
        }
        else if (s == "delete")
        {
            st.sasuke();
        }
        else if (s == "getmax")
        {
            st.getmax();
        }
        else{
            st.getcur();
        }
    }
    
}