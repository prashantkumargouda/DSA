// finding the height or depth of a binary tree 

// 2 methods 
// recursive and another one is level order traversal 

#include <iostream> 
using namespace std ; 

class Node{
public:
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ; 
        left = right = nullptr ;
    }
}; 

int height(Node* root) {
    if( root == nullptr ) {
        return -1 ;
    } 

    int lheight = height(root -> left) ;
    int rheight = height(root -> right) ; 

    return max( lheight , rheight ) + 1 ;
} 

int main(){
    Node* root = new Node(12) ; 
    root -> left = new Node(8) ;
    root -> right = new Node(18) ; 

    root -> left -> left = new Node(5) ; 

    root -> left -> right = new Node(11) ; 

    cout << height(root) << endl; 

    return 0 ; 

}