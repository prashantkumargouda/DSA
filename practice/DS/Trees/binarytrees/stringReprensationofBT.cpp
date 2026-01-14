// constructing string from a binary tree

#include <iostream> 
#include <vector> 
#include <string> 

using namespace std ;

class Node{
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x) {
        data = x ; 
        left = right = NULL ; 
    }
} ; 

string construct(Node* root) {
    if( root == NULL ) return "" ; 

    string s = to_string( root -> data ) ; 

    if( root -> left || root -> right ) {
        s += '(' + construct(root -> left) + ')' ; 
    } 

    if( root -> right ) {
        s += '(' + construct(root -> right) + ')' ;  
    } 

    return s ; 
}


int main() {
    Node* root = new Node(1) ; 
    root -> left = new Node(2) ; 
    root -> left -> left = new Node(4) ;  
    root -> left -> right = new Node(5) ; 
    root -> right = new Node(3) ;  

    string temp = construct(root) ; 

    cout << temp << endl; 

    return 0 ; 
}