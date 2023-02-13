#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* head;
    node* tail;
    node(){
        head = NULL;
        tail = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }

    void push_back(int data){
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

    void insertAt(int data, int pos){
       node* newnode = new node(data);
       int cnt = 0;
       while (cnt!= pos)
       {
        head = head->next;
        cnt++;
       }
       newnode->next = head;
       head = newnode;
       
    }
    void answer(int data, int pos){
        node* newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        int cnt = 0;
        while (head != NULL)
        {
            if (cnt == pos)
            {
                cout << newnode->data << " ";
            }
            cout << head->data << " ";
            head = head->next;
            cnt++;
        }
        
    }
    
    void print(){
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
          
        
    }
};


int main(){
    node ans;
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        ans.push_back(x);
    }
    int k;cin >> k;
    int pos; cin >> pos;
    ans.answer(k,pos);
    

}