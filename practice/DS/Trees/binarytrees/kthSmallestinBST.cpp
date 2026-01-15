// 230. Kth Smallest Element in a BST 

// medium 
// Given the root of a binary search tree, and an integer k, 
// return the kth smallest dataue (1-indexed) of all the dataues of the nodes in the tree.

#include <iostream>  
#include <unordered_map> 
#include <vector> 

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

void inorder( vector<int> &res , Node* root ) {
    if( root == NULL ) return ; 

    inorder(res , root -> left) ; 
    res.push_back(root -> data) ; 
    inorder(res , root -> right) ; 
}
int kthSmallest(Node* root, int k) {
        // finding the inorder 
        // which gives the sorted order ascending 
        // and then return the k-1th element 

    vector<int> res ; 
    inorder(res , root) ; 
    return res[k-1] ; 
}