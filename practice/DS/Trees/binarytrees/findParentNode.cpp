// given a binary tree and a node 
// we need to find the parent node if exists 
// else return -1  

#include <iostream> 
using namespace std ; 

class Node{
public:  
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x) {
        data = x ;
        left = right = NULL ; 
    }
}; 

int findParent(Node* root , int target , int parent ) {
    if( root == NULL ) {
        return -1 ; 
    } 

    // okay so the simple idea is to use recursion 
    // and pass on the parent for each of the nodes when going to the following subtree  

    // and return -1 if the root is the target element  

    if( root -> data == target ) {
        return parent ; 
    } 

    int leftCheck = findParent(root -> left , target , root -> data)  ; 
    if( leftCheck != -1 ) {
        return leftCheck ; 
    } 

    return findParent(root -> right , target , root -> data )  ; 
} 

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    cout << findParent(root , 3 , -1 ) ; 

    return 0 ; 
}
