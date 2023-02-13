#include <bits/stdc++.h>

using namespace std;
int sum = 0;
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
vector<int> v;
void reverse_inorder(node* root){
    if (root == NULL)return;
    reverse_inorder(root->right);
    v.push_back(root->key);
    reverse_inorder(root->left);    
}


int main(){
    node* root = NULL;
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    reverse_inorder(root);
    int sum = v[0];
    cout << sum << " ";
    for(int i = 1; i < v.size();i++){
        sum+=v[i];
        cout << sum << " ";
    }


    

}