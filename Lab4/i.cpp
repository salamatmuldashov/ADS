#include <bits/stdc++.h>

using namespace std;
struct node
{
    int key;
    int amount;
    node* left;
    node* right;
    node(){
        left = NULL;
        right = NULL;
    }
    node(int key) {
        this->key = key;
        this->amount = 1;
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
    else if (key > root->key)
    {
        insert(root->right, key);
    }    
}
node* find(node* root, int key){
    if(!root) return 0;
    else if(root->key == key) return root;
    else if(root->key < key) return find(root->right, key);
    else return find(root->left, key);
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


int main(){
    node* root = NULL;
    int q;cin >> q;
    while(q--){
        string s; int x;
        cin >> s >> x;
        if(s == "insert"){
            node* cur = find(root, x);
            if(!cur) insert(root, x);
            else cur->amount++;
        }
        if (s == "delete")
        {
            node* cur = find(root,x);
            if(cur) cur->amount--;
        }
        if (s == "cnt"){
            node* cur = find(root, x);
            if (cur) cout << cur->amount << '\n';
            else cout << "0\n";
        }
        
    }

    

}