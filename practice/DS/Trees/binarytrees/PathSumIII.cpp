// 437. Path Sum III

// Medium

// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes). 


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
 
void check(Node* root , int sum , int &count , int targetSum) {
    if(!root) return ; 

    sum += root -> data ; 
    if( sum == targetSum ) count++ ;   

    check(root->left , sum , count , targetSum) ; 
    check(root->right , sum , count , targetSum) ; 
}  

int pathSum(Node* root , int targetSum) {
    if (!root) return 0;

    int count = 0;
    check(root, 0, targetSum, count);

    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);

    return count; 
}

int main() {
    Node* root = new Node(10) ; 
    root -> left = new Node(5) ; 
    root -> left -> left = new Node(3) ; 
    root -> left -> left = new Node(3) ; 

    root -> left -> left -> right = new Node(-2) ; 
    root -> left -> right = new Node(2) ;  
    root -> left -> right -> right = new Node(2) ;  
    
    root -> right = new Node(-3) ;  
    root -> right -> right = new Node(11) ;   

    cout << pathSum(root , 8) << endl;

    return 0 ; 

}