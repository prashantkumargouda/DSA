// trying out preorder traversal on a binary tree 

#include <iostream> 
#include <vector> 

using namespace std ; 

class Node{
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ; 
        left = right = NULL ;
    }
}; 

void preorder(Node* node , vector<int> &res) {
    if( node == NULL ) {
        return ;
    } 

    res.push_back( node -> data ) ; 
    preorder( node -> left , res ) ;  
    preorder( node -> right ,  res ) ; 

} 

// using the iterative method 
vector<int> preOrder(Node* root) {
    vector<int> res ; 

    Node* curr = root ; 

    while( curr != NULL ) {
        if( curr -> left == NULL ) { // if there is not left subtree 
            res.push_back(curr -> data) ; 
            curr = curr -> right ;  
        } 
        else {
            // if there is a left subtree 
            Node* prev = curr -> left ; 
            // finding the inorder predecessor and linking it to the curr / root  
            while( prev -> right != NULL && prev -> right != curr ) {
                prev = prev -> right ; 
            } 

            if( prev -> right == NULL ) {
                prev -> right = curr ; 
                res.push_back(curr -> data) ; 
                curr = curr -> left ; 
            } 
            else {
                prev -> right = NULL ; // already visited 
                curr = curr -> right ; 
            }
        }
    } 

    return res ;
}
int main() {
    Node* root = new Node(1) ;  
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(5) ; 

    root -> right -> right = new Node(6) ; 

    vector<int> res = preOrder(root) ; ; 


    for(int x : res) {
        cout << x << " " ; 
    } 

    cout << endl; 
    return 0 ; 
}