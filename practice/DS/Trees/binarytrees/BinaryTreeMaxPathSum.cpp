// 124. Binary Tree Maximum Path Sum 
// hard  

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path. 

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
} ;

int check(Node* root , int &res){
    if(!root) return 0 ; 

    int num1 = check(root -> left , res) ; 
    int num2 = check(root -> right , res) ; 
     
    int sum = root -> data + num1 + num2 ; 

    res = max( res , sum ) ; 

    if( sum < 0 ) return 0 ; 
    else {
        return max( num1 , num2 ) + root -> data ; 
    } 
} 

int findMaxPath(Node* root){
    if( !root ) return 0 ; 

    int res = root -> data ; 
    check(root , res) ; 
    return res ;
} 

int main() {
    Node* root = new Node(-10) ; 
    root -> left = new Node(9) ; 

    root -> right = new Node(20) ; 
    root -> right -> left = new Node(15) ; 

    root -> right -> right = new Node(7) ; 

    cout << findMaxPath(root) << endl; 

    return 0 ; 

}