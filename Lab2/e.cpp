#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    string data;
    node* next;
    node* head;
    node* tail;
    vector<int> v;
    node(){
        head = NULL;
        tail = NULL;
    }
    node(string data){
        this->data = data;
        this->next = NULL;
    }

    void push_back(string data){
        node* newnode = new node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        
    }
    void push_front(string data){
        node* newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
        }else{
        newnode->next = head;
        head = newnode;
        }
    }
    void print(){
        while (head != NULL)
        {
            cout << head->data << "\n";
            head = head->next;
        }
          
        
    }
};

int main(){
    node ans;
    int cnt = 0;
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (i == 0)
        {
            ans.push_front(s);
            cnt++;
        }
        else if (s != ans.head->data)
        {
            cnt++;
            ans.push_front(s);
        }
    }
    
    cout << "All in all: " << cnt << "\n";
    cout << "Students:" << "\n";
    ans.print();
    
}