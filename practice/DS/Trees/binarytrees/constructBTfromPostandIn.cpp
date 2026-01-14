// constructing a binary tree using postOrder and Inorder 

// 106. Construct Binary Tree from Inorder and Postorder Traversal 

// Given two integer arrays inorder and postorder where inorder is the 
// inorder traversal of a binary tree and postorder is the postorder traversal 
// of the same tree, construct and return the binary tree. 

#include <iostream>  
#include <vector> 
#include <unordered_map> 
#include <algorithm>

using namespace std ; 

class Node{
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x) {   
        data = x ; 
        left = right = NULL; 
    }
}; 

Node* constructBinaryTree(vector<int> &postOrder , vector<int> &inOrder , int &postIndex , int inStart , int inEnd, unordered_map<int , int> &inMap) {
    if(inStart > inEnd) {
        return NULL ; 
    } 

    int rootVal = postOrder[postIndex++] ; 
    Node* root = new Node(rootVal) ; 

    int inIndex = inMap[rootVal] ; 

    root -> right = constructBinaryTree(postOrder , inOrder ,postIndex , inIndex +1 , inEnd , inMap ) ; 
    root -> left = constructBinaryTree(postOrder , inOrder , postIndex , inStart ,inIndex - 1 , inMap) ;   

    return root ; 
} 

Node* buildTree(vector<int> &postOrder , vector<int> &inOrder) {
    int n = postOrder.size() ;      

    unordered_map<int , int> inMap ; 
    for(int i=0 ; i<n ; i++) {
        inMap[inOrder[i]] = i ; 
    } 
    
    int postIndex = 0 ;  
    std::reverse(postOrder.begin() , postOrder.end()) ;  

    return constructBinaryTree(postOrder ,inOrder , postIndex , 0 , n-1 , inMap ) ; 
    
} 

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> postOrder = {9,15,7,20,3} ;   
    vector<int> inOrder = {9,3,15,20,7} ; 

    Node* root = buildTree(postOrder , inOrder) ; 

    cout << "Printing inorder for the created binary tree" << endl; 
    printInorder(root) ; 

    return 0 ; 

}