#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
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


void answer(node* root){
    if(root != NULL){
        if(root->right and root->left){
            cnt++;
        }
        answer(root->left);
        answer(root->right);
    }
    else return;
    
    
}


int main(){
    int n; cin >> n;
    node* root = NULL;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    // inorder(root);
    answer(root);
    cout << cnt << '\n';
    

    

}