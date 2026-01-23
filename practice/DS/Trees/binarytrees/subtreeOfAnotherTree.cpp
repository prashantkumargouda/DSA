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

bool check(Node* root , Node* subRoot ){ 
    if( !root && !subRoot ) return true ; 

    if( !root || !subRoot ) return false ; 

    if( root -> data == subRoot -> data) {
        return check( root -> left , subRoot -> right ) || check( root -> right , subRoot -> right ) ; 
    } 
 
    return false ; 

}

bool isSubTree(Node* root , Node* subRoot) {
    if( !root || !subRoot ) return false ; 
    if( check(root , subRoot) ) return true ; 

    return check( root -> left , subRoot ) || check( root -> right , subRoot ) ; 
} 

int main() {
    Node* root = new Node(3) ; 
    root -> left = new Node(4) ; 
    root -> left -> left = new Node(1) ; 
    root -> left -> right = new Node(2) ;  

    root -> right = new Node(5) ;  

    Node* root1 = new Node(4) ; 
    root1 -> left = new Node(1) ; 
    root1 -> right = new Node(2) ;  

    if (isSubTree( root , root1 ) ) cout << "YES" << endl; 

    else cout << "NO" << endl; 

}