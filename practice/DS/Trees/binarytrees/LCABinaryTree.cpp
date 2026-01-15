// 236. Lowest Common Ancestor of a Binary Tree  
// medium 
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “
// The lowest common ancestor is defined between two nodes p and q as 
// the lowest node in T that has both p and q as descendants 
// (where we allow a node to be a descendant of itself).”


#include <iostream>  
#include <unordered_map> 
#include <vector> 

using namespace std ; 

class Node{
public :  
    int data  ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ; 
        left = right = NULL ; 
    }
}; 

Node* lcaBinaryTree(Node* root , Node* p , Node* q) {
    if( root == NULL ) return NULL ; 

    if( root == p || root == q ) {
        return root ; 
    } 

    Node* leftLca = lcaBinaryTree(root -> left , p , q ) ;
    Node* rightLca = lcaBinaryTree( root -> right , p , q ) ; 

    if( leftLca != NULL && rightLca != NULL ) return root ; 
    return leftLca == NULL ? rightLca : leftLca ; 

} 

int main() {
    Node* root = new Node(3) ; 
    root -> left = new Node(5) ; 
    root -> right = new Node(1) ; 

    root -> left -> left = new Node(6); 
    root -> left -> right = new Node(2) ; 

    root -> right -> left = new Node(0) ; 
    root -> right -> right = new Node(8) ; 

    root -> left -> right -> left = new Node(7) ; 
    root -> left -> right -> right = new Node(4) ; 

    Node* temp = lcaBinaryTree(root , root -> left, root -> left -> right -> right ) ;

    cout << temp -> data << endl; 

    return 0 ; 
}