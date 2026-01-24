// 112. Path Sum
// Easy

// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children. 

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

bool check(Node* root , int target , int sum) {
    if( !root ) return false ; 

    sum += root -> data ; 

    if( !root -> left && !root -> right && sum == target ) {
        return true ;  
    } 

    return check(root -> left , target , sum ) || check( root -> right , target , sum)  ; 
}    

bool hasPathSum(Node* root , int targetSum) {
    return check( root , targetSum , 0 )  ; 
} 

int main() {    
    Node* root = new Node(5) ;  
    root -> left = new Node(4) ; 
    root -> right = new Node(8) ; 

    root -> left -> left = new Node(11) ;
    root -> left -> left -> left = new Node(7) ; 

    root -> left -> left -> right = new Node(2) ; 

    if(hasPathSum(root , 22) ) {
        cout << "YES" << endl; 
    } 
    else {
        cout << "NO" << endl; 
    } 

    return 0 ; 
}