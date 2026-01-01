// invert a binary tree 

#include <iostream>
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

Node* invertTree(Node* root) {
    if( root == nullptr ) {
        return  ;
    } 

    Node* temp = root -> left ; 
    root -> left = root -> right ; 
    root -> right = temp ; 

    invertTree(root -> left) ; 
    invertTree(root -> right) ;  

    return root ; 
}