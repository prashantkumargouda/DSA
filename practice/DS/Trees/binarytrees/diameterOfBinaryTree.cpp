// 543. Diameter of Binary Tree 
// medium 

// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them. 

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

int res = 0 ;  

int check(Node* root ) {
    if( root == nullptr ) return 0 ; 

    int num1 = check( root -> left ) ; 
    int num2 = check( root -> right ) ; 

    res = max( res , num1 + num2 ) ; 
    return max(num1 , num2) + 1 ;  
} 

int diameter(Node* root) {
    if( !root ) return 0 ;  

    check( root) ; 
    return res ; 
}

int main() {    
    Node* root = new Node(1) ; 
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(5) ; 

    root -> left -> right -> left = new Node(4) ; 
    root -> left -> right -> right = new Node(6) ; 

    root -> right = new Node(3) ;

    cout << diameter(root) << endl; 

    return 0 ; 
}