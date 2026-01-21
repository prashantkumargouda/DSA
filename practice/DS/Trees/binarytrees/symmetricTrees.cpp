// finding if given tree is symmetric or not 

#include <iostream> 
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
}; 

bool check(Node* left , Node* right) {
    if( !left && !right ) return true ; 
    if( !left || !right ) return false ;  

    return ( left -> data == right -> data ) && check( left -> left , right -> right ) && check(left -> right , right -> left) ; 
}
bool mirror(Node* root) {
    if( root == NULL ) return true ;  
    return check(root -> left , root -> right) ; 
} 

int main() {
    Node* root = new Node(1) ; 
    root -> left = new Node(2) ; 
    root -> right = new Node(2) ; 

    root -> left -> left = new Node(3) ; 
    root -> left -> right = new Node(4) ; 

    root -> right -> left = new Node(4) ; 
    root -> right -> right = new Node(3) ;  

    if( mirror(root) ) cout << "YES" << endl; 
    else cout << "NO" << endl; 

    return 0 ; 
}