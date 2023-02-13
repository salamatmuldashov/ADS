#include <bits/stdc++.h>
using namespace std;
struct node
{
    string data;
    node* next;
    node(){}

    node(string data){
        this->data = data;
    }
};
struct linkedlist
{
    node *head, *tail;
    map<string, int> mp;
    int size;
    linkedlist(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    void insert(string data){
        node* newnode = new node(data);
        if(size == 0){
            head = newnode;
            tail = newnode;
            mp[data]++;
            size++;
            return;
        }
        mp[data]++;
        tail->next = newnode;
        tail = tail->next;
        size++;
        
    } 
    void print(){

        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        
    }
    void answer(){
        node* cur = head;
        for(int i = 0; i < size; i++){
            if(mp[cur->data] == 1){
                cout << cur->data << " ";
                return;
            }
            cur = cur->next;
        }
        cout << "-1" << " ";
    }
    
};




int main(){
    int t;cin >> t;
    while (t--)
    {
        linkedlist ll;
        int n;cin >> n;
        for(int i = 0; i < n; i++){
            string data;cin >> data;
            ll.insert(data);
            ll.answer();
        }
        cout << '\n';

        
    }
    

}