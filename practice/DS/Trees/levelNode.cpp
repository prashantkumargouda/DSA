// trying to find the level of a particular in a binary tree 
// works for unique nodes in the tree 

#include <iostream>  
#include <queue> 

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
} ;   

// Expected approach -1  
// traverse all left and right subtrees 

int getLevel0(Node* root , int target , int level ) {
    if( root == NULL ){
        return -1 ; 
    }  

    // okay if matches bhai return karde 
    if( root -> data == target ) {
        return level ; 
    } 

    int leftLevel = getLevel0( root -> left , target , level + 1 ) ; 

    if( leftLevel != -1 ) { 
        return leftLevel ; 
    } 

    return getLevel0( root -> right , target , level + 1 ) ; 
}

// trying out the expected approach for the problem 

int getLevel(Node* root , int target ) { 
    if( root == NULL ) {
        return -1 ; 
    } 

    int currLevel = 1 ; 
    queue<Node*> q ; 

    q.push(root) ; 

    while( !q.empty() ){
        int len = q.size() ; 

        for(int i=0 ; i<len ; i++){
            Node* curr = q.front() ; 
            q.pop() ; 

            if( curr -> data == target ) {
                return currLevel ; 
            } 
            
            if( curr -> left != nullptr ) {
                q.push(curr -> left);  
            } 
            if( curr -> right != nullptr ) {
                q.push(curr -> right) ; 
            }
        } 
        currLevel++ ; 
    }  

    return -1 ; 
}

int main() { 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 

    cout << getLevel(root , 5) << endl;  

    cout << getLevel0( root , 5 , 1 ) << endl; 

    return 0 ; 

}