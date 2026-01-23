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

void inorder(Node* root , vector<int> &res) {
    if( root == NULL ) return ; 

    inorder(root -> left, res) ; 
    res.push_back(root -> data) ; 
    inorder(root -> right , res) ; 
}

int check(Node* root , int &count ,int value, unordered_map<int , int> &checkMap) {
    if( !root ) return 0;  

    if( !root -> left && !root -> right ) {
        checkMap[root -> data] = max( checkMap[root -> data] , count ) ; 
    } 

    if( root -> data == value ) count += 1 ; 
    

}
int longestPath(Node* root) {
    if(!root) return 0 ; 

    unordered_map<int , int> checkMap ;  
    vector<int> res ; 
    inorder(root , res) ; 

    // checkMap prepared 
    for(int i : res) {
        checkMap[i] = 0 ; 
    }  

    int count = 0 ; 
    int n = max( check( root -> left , count , root -> data , checkMap ) , check( root -> right , count , root -> data , checkMap ) ) ;   

} 

int main(){

}