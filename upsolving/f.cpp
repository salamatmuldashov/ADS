#include <bits/stdc++.h>

using namespace std;

map<int,vector<int> > mp;
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


void answer(node* root, int level){
    if(root == 0) return;
    mp[level].push_back(root->key);

    answer(root->left, level + 1);
    answer(root->right, level+1);
}
// void answer(node* root, int level){
//     if(root == NULL) return;

//     sum+=(root->key - level);
    
//     answer(root->left,++level);
//     answer(root->right, ++level);

    
// }



int main(){
    node* root = NULL;
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    answer(root, 0);
    int sum = 0;
    map<int,vector<int> > :: iterator it;
    for(it = mp.begin(); it!= mp.end(); it++){
        for(int j = 0; j < it->second.size(); j++){
            sum+=(it->second[j] - it->first);
        }
    }
    
    cout << sum << '\n';

    

}