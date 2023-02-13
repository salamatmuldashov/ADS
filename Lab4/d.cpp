#include <bits/stdc++.h>

using namespace std;
struct node
{
    int key;
    node* left;
    node* right;
    node(){
        left = NULL;
        right = NULL;
    }
    node(int key) {
        this->key = key;
    }
};

void insert(node* &root, int key){
    if(root == NULL){ 
    root = new node(key);
    return;
    }
    if (key < root->key)
    {
       insert(root->left, key);
    }
    else
    {
        insert(root->right, key);
    }
    
    
}
void inorder(node* root){
    if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
}
// map<int,int> mp;

// void answer(node* root, int level = 1){
//     if(root == 0) return;
//     mp[level] += root->key;

//     answer(root->left, level + 1);
//     answer(root->right, level+1);
// }
vector<int> v;
void answer(node* root, int level = 1){
    if(root == 0) return;
    queue<node*> l;
    l.push(root);
    while (l.size())
    {
        int size = l.size();
        int cursum = 0;
        while (size > 0)
        {
            node* cur = l.front();
            cursum+=cur->key;
            l.pop();
            if(cur->left) l.push(cur->left);
            if(cur->right)l.push(cur->right);
            size--;
        }
        
        v.push_back(cursum);
    }
    
    
}

int main(){
    node* root = NULL;
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    answer(root);
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    

    

}