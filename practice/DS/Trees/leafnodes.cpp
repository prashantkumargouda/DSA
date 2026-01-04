// printing the leaf nodes of a tree from left to right using dfs and bfs(using stack) 

#include <iostream>  
#include <stack> 
using namespace std ; 

class Node {
public :  
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ; 
        left = right = NULL ; 
    }
}; 

// using dfs 
void printLeaf(Node* root) {
    if( root == NULL ) {
        return ; 
    } 

    if( root -> right == NULL && root -> left == NULL ) {
        cout << root -> data << " " ;  
        return ; 
    } 

    if( root -> left ) printLeaf(root -> left) ; 
    if( root -> right ) printLeaf( root -> right ) ; 
}  

// using bfs 
// we will use a stack for this problem 

void printLeaf1(Node* root) {
    if( root == NULL ) {
        return ; 
    } 

    stack<Node*> st ;  
    st.push(root) ; 

    while( !st.empty() ) {
        Node *curr = st.top() ; 
        st.pop() ; 

        if( curr -> right == NULL && curr -> left == NULL ) {
            cout << curr -> data << " " ;  
        }  

        if( curr -> right ) st.push(curr -> right ) ; 
        if( curr -> left ) st.push(curr -> left) ;  
    } 
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    printLeaf(root) ; 
    cout << endl; 
    printLeaf1(root) ; 

    return 0; 
}