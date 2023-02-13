#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    string data;
    node* next;
    node* head;
    node* tail;
    node(){
        head = NULL;
        tail = NULL;
    }
    node(string data){
        this->data = data;
        this->next = NULL;
    }


    void push(string data){
        node* newnode = new node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }

    }

    void rotateList(int k){
        while (k--)
        {
            (this)->push(head->data);
            head = head->next;
        }
        
    }

    void print(){
        while (head!=NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        
    }
    




};

int main(){
    node ans;
    int n, k; cin >> n >> k;
    string s;
    for(int i = 0; i < n;i++){
        cin >> s;
        ans.push(s);

    }
    ans.rotateList(k);
    ans.print();

}