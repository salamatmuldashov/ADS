#include <bits/stdc++.h>

using namespace std;
map<int,int> m;
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
int leftheight(node* root){
    if(root == NULL)return 0;
    int l = 0;
    while (root->left != NULL)
    {
        l++;
        root= root->left;
    }

    return l;
    
}

int rightheight(node* root){
    if(root == NULL) return 0;

    int r = 0;
    while(root->right != NULL){
        r++;
        root = root->right;
    }

    return r;
}

void answer(node* root){
    if(root == NULL) return;
    int l = leftheight(root);
    int r = rightheight(root);
    
    for(int i = 1; i <= min(l,r); i++){
        m[i]++;
    }

    answer(root->left);
    answer(root->right);
    
    
}

void print(node* root, int n){
    answer(root);

    for(int i = 1; i < n; i++){
        cout << m[i] << " ";
    }

    cout << '\n';
}
int main(){
    int n; cin >> n;
    node* root = NULL;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    print(root, n);


    

    

}