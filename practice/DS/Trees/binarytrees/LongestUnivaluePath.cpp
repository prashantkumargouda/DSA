// 687. Longest Univalue Path 
// medium 

// Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

// The length of the path between two nodes is represented by the number of edges between them.  

#include <iostream>   
#include <unordered_map> 
#include <algorithm> 

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

int res = 0 ; 
int check(Node* root , int x) {
    if( !root ) return 0 ; 
    if( root -> data != x ) return 0 ; 

    int num1 = check(root -> left , root -> data) ;  
    int num2 = check(root -> right , root -> data) ;  

    res = max( res , num1 + num2) ; 

    return max(num1 , num2) + 1 ; 
} 

int longestPath(Node* root) {
    if(!root) return 0 ; 

    check(root , root -> data) ; 
    return res ;
}

int main(){
    Node* root = new Node(1) ; 
    root -> left = new Node(4) ; 
    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(4) ; 

    root -> right = new Node(5) ; 
    root -> right -> right = new Node(5) ; 

    cout << longestPath(root) << endl; 

    return 0 ; 
}   