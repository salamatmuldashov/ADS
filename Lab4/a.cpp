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
// node *insert(node* root, int key){
//     if(root == NULL) {
//         return new node(key);
//     }

//     if (key < root->key)
//     {
//        root->left = insert(root->left, key);
//     }
//     else
//     {
//         root->right = insert(root->right, key);
//     }
//     return root;
//     }
    
    void inorder(node* root){
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
        
    }

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



int main(){
    node* root = NULL;
    int n,q;cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        insert(root,x);
    }
    while (q--)
    {
        string s;
        cin >> s;
        node* cur = root;
        bool ok = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
            {
                cur = cur->left;
            }
            else if (s[i] == 'R')
            {
                cur = cur->right;
            }
            if (cur == 0)
            {
                cout << "NO\n";
                ok = false;
                break;
            }
            
        }
        if (ok)cout << "YES\n";
        
        
        
        

        
        // if (cur != NULL)
        // {
        //     cout << "YES\n"; 
        // }else cout << "NO\n";
        
        


    }
    

}
