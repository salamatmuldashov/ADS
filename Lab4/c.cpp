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

node* search(node* root, int k){
    if(root->key == k) return root;
    else if(root->key < k) return search(root->right, k);
    else return search(root->left, k);
}
node* getnode(node* root,int k){
    node* head = search(root,k);
    return head;
}
void print(node* root){
    if(root == NULL)return;
    cout << root->key << ' ';
    print(root->left);
    print(root->right);
}

int main(){
    node* root = NULL;
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    int k;cin >> k;
    node* head = getnode(root,k);
    print(head);




    

    

}