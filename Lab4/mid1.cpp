// #include <bits/stdc++.h>

// using namespace std;

// map<int, int> mp;

// struct Node{
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->val = val;
//         left = right = nullptr;
//     }
// };

// class BST{
// private:
//     Node* root;

//     Node* insert(Node* cur, int val){
//         if (!cur) return new Node(val);
        
//         if (val < cur -> val) cur -> left = insert(cur -> left, val);
//         if (val > cur -> val) cur -> right = insert(cur -> right, val);

//         return cur;
//     }

//     void height(Node * cur) {
//         Node * temp = cur;
//         int l = 0, r = 0;
//         while(temp != NULL) {
//             temp = temp -> left;
//             l++;
//         }
//         temp = cur;
//         while(temp != NULL) {
//             temp = temp -> right;
//             r++;
//         } 
//         for(int i = 1; i <= min(l, r); ++i) mp[i]++;
//     }

//     void inOrder(Node* cur){
//         if (cur){
//             inOrder(cur -> left);
//             cout << cur -> val << " ";
//             inOrder(cur -> right);
//         }
//     }

//     void count_height(Node * current) {
//         if(current != nullptr) {
//             count_height(current->left);
//             count_height(current->right);
//             height(current);
//         }
//     }

//     // int height(Node* cur){
//     //     if (!cur) return 0;

//     //     return max(height(cur -> left), height(cur -> right)) + 1;
//     // }

// public:
//     BST(){
//         root = nullptr;
//     }

//     void insert(int val){
//         root = insert(root, val);
//     } 

//     void inOrder(){
//         inOrder(root);
//     }   

//     void count_height(){
//         return count_height(root);
//     }
   
// };

// int main(){
//     int n;
//     cin >> n;

//     BST tree;
//     for (int i = 0; i < n; i++){
//         int x;
//         cin >> x;
//         tree.insert(x);
//     }
//     // tree.inOrder();
//     // cout << endl;
//     tree.count_height();
//     for(int i = 2; i <= n; ++i) cout << mp[i] << " ";
// }


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
void answer(node* root){
        node* temp = root;
        int l = 0, r = 0;
        while(temp != NULL) {
            temp = temp -> left;
            l++;
        }
        temp = root;
        while(temp != NULL) {
            temp = temp -> right;
            r++;
        } 

        // cout << l << " " << r << "\n";
        for(int i = 1; i <= min(l,r); ++i) m[i]++;
    
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
int size(node* root){
    if(root == NULL)return 0;

    return 1 + size(root->left) + size(root->right);
    

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
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x;cin >> x;
        insert(root, x);
    }
    answer(root);
    for(int i = 2; i <= n;i++)cout << m[i] << " ";

    

}