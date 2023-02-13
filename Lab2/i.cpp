#include <bits/stdc++.h>
using namespace std;
struct node{
    string data;
    node* next;
    node* prev;
};
node* head;
void add_front(string data){
    node* newnode = new node;
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    if(head != NULL){
        head->prev = newnode;
    }
    head = newnode;
}
void add_back(string data){
    node* newnode = new node;
    node* tmp = head;
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    while(tmp->next != NULL) tmp = tmp->next;

    tmp->next = newnode;
    newnode->prev = tmp;
    
}
void erase_front(){
    if(head != NULL){
        node* tmp = head;
        head = head->next;
        free(tmp);
        if (head != NULL)
        {
            head->prev = NULL;
        }
        
    }
}
void erase_back(){
    if(head != NULL){
        if(head->next == NULL){
            head = NULL;
        }
        else
        {
            node* tmp = head;
            while (tmp->next->next != NULL)
            {
                tmp = tmp->next;
            }
            node* last = tmp->next;
            tmp->next = NULL;
            free(last);
            
        }
        
    }
}
void front(){
    if (head != NULL)
    {
        cout << head->data << "\n";
        return;
    }
    cout << "error" << "\n";
}
void back(){
    node* tmp = head;
    if (head != NULL)
    {
        while (tmp!= NULL)
        {
            if(tmp->next == NULL) break;
            else tmp = tmp->next;
        }
        cout << tmp->data << "\n";
        return;
    }
    cout << "error" << "\n";
    
}
void clear(){
    node* tmp;
    while (head!=NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    
}
void print(){
    node* tmp;
    while (head != NULL)
    {
        cout << head->data << " ";
        tmp = head;
        head = head->next;
    }
    

}

int main(){
    string s,l;
    while (true)
    {
        cin >> s;
        if (s == "add_front")
        {
            cin >> l;
            cout << "ok" << "\n";
            add_front(l);
        }
        else if (s == "add_back")
        {
            cin >> l;
            cout << "ok" << "\n";
            add_back(l);
        }
        else if (s == "erase_front")
        {
            front();
            erase_front();
        }
        else if (s == "erase_back")
        {
            back();
            erase_back();
        }
        else if (s == "front")
        {
            front();
        }
        else if (s == "back")
        {
            back();
        }
        else if (s == "clear")
        {
            clear();
            cout << "ok" << "\n";
        }
        else if (s == "exit")
        {
            cout << "goodbye" << "\n";
            break;
        }
        
        
        
        
        
        
        
        
    }
    

}