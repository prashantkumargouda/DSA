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

void inOrder1(Node* node , vector<int> &res ) {
    if( node == NULL ) {
        return ; 
    } 

    inOrder1( node -> left , res ) ;     
    res.push_back( node -> data ) ; 
    inOrder1( node -> right , res ) ; 
}

vector<int> inOrder2(Node* root) {
    vector<int> inorder ;  

    Node* curr = root ; 

    while( curr != nullptr ) {
        if( curr -> left == NULL ) {
            inorder.push_back(curr ->data ) ; 
            curr = curr -> right ; 
        } 
        else {
            Node* prev = curr -> left  ; 
            while( prev -> right != NULL && prev -> right != curr ) {
                prev = prev -> right ; 
            } 

            if( prev -> right == NULL ) {
                prev -> right = curr ; 
                curr = curr -> left ; 
            } 
            else {
                prev -> right = NULL ; 
                inorder.push_back(curr -> data) ;  
                curr = curr -> right ; 
            }
        }
    } 

    return inorder ; 

}

int main() {
    Node* root = new Node(1) ; 

    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(5) ; 

    root -> right -> right = new Node(6) ;  

    vector<int> res ;
    inOrder1( root , res) ; 
    for(int x : res ){
        cout << x << " " ; 
    } 

    cout << endl;  

    vector<int> temp = inOrder2(root) ; 

    for(int x : temp) {
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ;
    
}