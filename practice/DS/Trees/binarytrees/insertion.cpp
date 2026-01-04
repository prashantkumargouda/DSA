// inserting a new element at the empty position 

#include <iostream>  
#include <queue> 

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

Node* insertNode(Node* root , int data) {
    if( root == NULL ) { 
        Node* root = new Node(data) ;
        return root ;
    } 

    queue<Node*> q ; 
    q.push(root) ; 

    while( !q.empty() ) {
        int len = q.size() ; 

        for(int i=0 ; i<len ; i++) {
            Node* curr = q.front() ; 
            q.pop() ; 

            if( curr -> left != nullptr ) {
                q.push( curr -> left ) ;  
            }else {
                curr -> left = new Node(data) ; 
                return root ; 
            } 
            if( curr -> right != nullptr ) {
                q.push(curr->right) ;
            } 
            else {
                curr -> right = new Node(data) ; 
                return root ; 
            }
        }
    }
} 

void inorder(Node* root) {
    if( root == NULL ) {
        return ; 
    } 

    inorder( root -> left ) ; 
    cout << root -> data << " " ; 
    inorder(root -> right) ;
} 

int main() {
    Node* root = new Node(10);
    root->left = new Node(11);
  	root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);  

    insertNode(root , 12) ; 

    inorder(root) ; 

    return 0 ;
}