#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void push(node* &head, int data){
    node* newnode = new node(data);
    if(head == NULL){
        head = newnode;
        return;
    }
    node* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = newnode;
    
}

void Answer(node* head){
    node* cur = head;
    int cnt = 1;
    while (cur != NULL)
    {
        if (cnt % 2 != 0)
        {
            cout << cur->data << " ";
        }
        cur = cur->next;
        cnt++;
    }
    cout << "\n";
    
}

void display(node* head){
    node* cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    
}




int main(){
node* head = NULL;
int n;cin >> n;
for(int i = 0; i < n; i++){
    int data;cin >> data;
    push(head,data);
}
Answer(head);



}