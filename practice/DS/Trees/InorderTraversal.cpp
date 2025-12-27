// trying out inorder traversal in a binary tree 
#include <iostream>
#include <vector> 
using namespace std ; 

class Node {
public : 
    int data ; 
    Node* left ; 
    Node* right ;  

    Node(int x) {
        data = x ; 
        left = right = NULL ; 
    }
};  

void inorder(Node* node , vector<int> &res ) {
    if( node == NULL ) {
        return ; 
    } 

    inorder( node -> left , res ) ;     
    res.push_back( node -> data ) ; 
    inorder( node -> right , res ) ; 
}

int main() {
    Node* root = new Node(1) ; 

    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(5) ; 

    root -> right -> right = new Node(6) ;  

    vector<int> res ;
    inorder( root , res) ; 

    for(int x : res ){
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ;
    
}