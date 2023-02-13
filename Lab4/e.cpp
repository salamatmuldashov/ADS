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

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->key << ' ';
    inorder(root->right);
}

node* insert(node* root, int key){
    node* newnode = new node(key);
    return newnode;
}
void sasuke(node* root, int x, int y, int z){
    if(root->key == x){
        if(z == 0) root->left = insert(root->left,y);
        if(z == 1) root->right = insert(root->left,y);
    }
    else{
        if(root->left) sasuke(root->left, x, y, z);
        if(root->right) sasuke(root->right, x, y, z);
    }
    
}
vector<int> v;
void answer(node* root, int level = 1){
    if(root == 0) return;
    queue<node*> l;
    l.push(root);
    while (l.size())
    {
        int size = l.size();
        int cnt = 0;
        while (size > 0)
        {
            node* cur = l.front();
            cnt++;
            l.pop();
            if(cur->left) l.push(cur->left);
            if(cur->right)l.push(cur->right);
            size--;
            
        }
        
        v.push_back(cnt);
    }
    
    
}


int main(){
    node* root = new node(1);
    int n;cin >> n;
    for(int i = 0; i < n-1; i++){
        int x,y,z; cin >> x >> y >> z;
        sasuke(root,x,y,z);
    }
    // cout << '\n';
    // inorder(root);
    // cout << '\n';
    answer(root);

    cout << *max_element(v.begin(), v.end());
    
    

}
//          1
//         / \
//        3    2
//       / \    \
//      5   6    4
// //       1
// //      / 
// //     2
// //    / \
// //   3   4