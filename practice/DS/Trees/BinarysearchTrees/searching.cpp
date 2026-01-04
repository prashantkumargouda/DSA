// Given the root of a Binary Search Tree and a value key, find if key is present in the BST or not.  
//    6
    //   / \
    //  2   8
    //     / \
    //    7   9 

#include <iostream>
using namespace std ; 

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};
 
bool searchingBinary(Node* root , int key ) {
    if( root == NULL ) {
        return false ;
    } 
    
    if( root -> data == key ) {
        return true ;    
    } 

    if( key > root -> data ) {
        return searchingBinary(root -> right , key) ; 
    } 
    else {
        return searchingBinary(root-> left , key) ; 
    }
}

bool searchingBinary1(Node* root , int key ) {
    if( root == NULL ) {
        return false ;
    } 

    while( root != nullptr ) {
        if( root -> data == key ){
            return true ; 
        } 

        else if (key > root->data)
            root = root->right;
        else
            root = root->left;
    }
}

int main() { 
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    
    // Searching for key in BST
    cout << searchingBinary(root, key) << endl;
}