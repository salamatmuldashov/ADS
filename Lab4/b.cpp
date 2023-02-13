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
int size(node* root){
    if(root == NULL)return 0;

    return 1 + size(root->left) + size(root->right);
    

}

void search(node* root, int key){
    if (root->key == key)
    {
       cout << size(root) << '\n';
    }
    else if (root->key < key)
    {
         search(root->right, key);
    }else
    {
        search(root->left, key);
    }
    
    
    
}

int main(){
    node* root = NULL;
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    int k;cin >> k;

    search(root, k);

    

}