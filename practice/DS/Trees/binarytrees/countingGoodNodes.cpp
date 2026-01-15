// level medium 
// 1448. Count Good Nodes in Binary Tree 

// Given a binary tree root, a node X in the tree is named good if in the path from root to X 
// there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.

#include <iostream> 
using namespace std ;

class Node{
public :  
    int data  ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ; 
        left = right = NULL ; 
    }
}; 

void counting(Node* root , int &count , int mx ) {


    if( root -> data >= mx ) { 
        count = count + 1 ;
        mx = root -> data ; 
    } 

    if( root -> left ) counting( root -> left , count , mx ) ; 
    if( root -> right ) counting( root -> right , count , mx ) ;
}

int goodNodes(Node* root) {
    if( root == NULL ) return 0 ; 

    int mx = root -> data ; 
    int count = 0 ;  

    counting(root , count , mx ) ;
    return count ; 
}

int main() {
    Node* root = new Node(2) ; 
    root -> right = new Node(4) ; 
    root -> right -> left = new Node(10) ; 

    root -> right -> right = new Node(8) ; 
    root -> right -> right -> left = new Node(4) ; 

    cout << goodNodes(root) << endl; 

    return 0 ;
    
}