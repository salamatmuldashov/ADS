// #include <iostream>
// #include <map>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node*left;
//     Node*right;

//     Node(int data){
//         this->data=data;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };

// class BST{
//     public:
//     Node* root;
//     map<int, int> m;
//     BST(){
//         root=NULL;
//     }
//     Node*add(Node*node, int data){
//         if(node==NULL){
//             node= new Node(data);
//             return node;
//         }
//         if(data<=node->data){
//             node->left= add(node->left, data);
//         }
//         else{
//             node->right= add(node->right, data);
//         }
//         return node;
//     }

//     void f(int n){
//         for (int i = 1; i < n; i++){
//             m[i] = 0;
//         }
//     }

//     void subtree(Node*node, int n){
//         if(node == NULL) return;
//         int leftcnt = 0;
//         int rightcnt = 0;
//         Node *temp = node;
//         while (temp->left != NULL && leftcnt < n) {leftcnt++; temp = temp->left;}
//         temp = node;
//         while (temp->right != NULL && rightcnt < n) {rightcnt++; temp = temp->right;}
//         if (leftcnt == rightcnt && leftcnt == n) {
//             m[n]++;
//         subtree(node->left, n);
//         subtree(node->right, n);
//     }



// };
// int main(){
// int n;
// cin>> n;
// BST* bst= new BST();
// for (size_t i = 0; i < n; i++)
// {
//     int x;
//     cin>>x;
//     bst->root= bst->add(bst->root, x);
// }
// bst->f(n);
// for (int i = 1; i < n; i++){
//     bst->subtree(bst->root, i);
// }
// for (int i = 1; i < n; i++){
//     cout << bst->m[i] << " ";
// }
// }