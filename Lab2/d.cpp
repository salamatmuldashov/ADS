#include <bits/stdc++.h>
using namespace std;

bool csgo(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.second == p2.second){
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

class node{
    public:
    int data;
    node* next;
    node* head;
    node* tail;
    vector<int> v;
    node(){
        head = NULL;
        tail = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }

    void push(int data){
        node* newnode = new node(data);
        // v.push_back(newnode->data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        
    }
    void print(){
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        
    }
    
    void answer(){
        map<int,int> mode;
        map<int,int> ::iterator it;
        while (head != NULL)
        {
            mode[head->data]++;
            head = head->next;
        }
        vector<pair<int, int> > v(mode.begin(), mode.end());
        sort(v.begin(), v.end(), csgo);
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second == v[i+1].second)
            {
                cout << v[i].first << " ";
            }else
            {
                cout << v[i].first << "\n";
                break;
            }
            
            
        }
        

    }


};

int main(){
    node ans;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        ans.push(x);
    }
    ans.answer();

    
}