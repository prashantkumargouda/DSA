// constructing a binary tree using preorder and Inorder traversal of the tree 

// 105. Construct Binary Tree from Preorder and Inorder Traversal 

// level : medium  

// topics : 
// Array
// Hash Table
// Divide and Conquer
// Tree
// Binary Tree 

#include <iostream> 
#include <vector> 
#include <unordered_map> 

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

Node* buildTree(vector<int> &preOrder , vector<int> &inOrder , int &preIndex , int inStart , int inEnd , unordered_map<int , int> &inMap) {
    if(inStart > inEnd) return NULL ; 

    // picking the root node from preOrder vector 
    int rootVal = preOrder[preIndex++] ; 
    Node* root = new Node(rootVal) ; 

    // finding the same root val in inOrder 
    int inIndex = inMap[rootVal] ; 
    
    root -> left = buildTree(preOrder, inOrder, preIndex , inStart , inIndex -1 , inMap ) ; 
    root -> right = buildTree(preOrder , inOrder , preIndex , inIndex +1 , inEnd , inMap ) ; 

    return root ; 
}  

Node* constructBinaryTree(vector<int> &preOrder , vector<int> &inOrder) {
    int n = preOrder.size() ; 
    unordered_map<int , int> inMap ; 

    for(int i=0 ; i<n ; i++) {
        inMap[inOrder[i]] = i ;
    } 

    int preIndex = 0 ;
    return buildTree(preOrder , inOrder , preIndex , 0 , n-1 , inMap ) ; 
} 

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
    vector<int> preOrder = {3,9,20,15,7} ; 
    vector<int> inOrder = {9,3,15,20,7} ;  
    
    Node* root = constructBinaryTree(preOrder , inOrder) ; 

    cout << "Printing inorder for the created binary tree" << endl; 

    printInorder(root) ; 

    return 0 ;
}

