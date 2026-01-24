// 129. Sum Root to Leaf Numbers
// Medium

// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children. 

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

void check( Node* root , int &sum , int x ) {
    if( !root ) return ; 

    int data = x * 10 + root -> data ; 

    if( !root -> left && !root -> right ) {
        sum += data ;
        return ; 
    } 

    check( root -> left , sum , data ) ; 
    check( root -> right , sum , data ) ; 
} 

int sumOfleaf(Node* root) {
    if( !root ) return 0 ; 

    int sum = 0 ; 
    check( root , sum , 0 ) ;  

    return sum ; 
}

int main(){
    Node* root = new Node(4) ; 
    root -> left = new Node(9) ; 
    root -> right = new Node(0) ; 

    root -> left -> left = new Node(5) ; 
    root -> left -> right = new Node(1) ; 

    cout << sumOfleaf(root) << endl; 

    return 0 ; 
}