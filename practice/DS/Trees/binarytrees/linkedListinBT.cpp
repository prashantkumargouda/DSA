// 1367. Linked List in Binary Tree 
// medium 

// Given a binary tree root and a linked list with head as the first node. 

// Return True if all the elements in the linked list starting from the head 
// correspond to some downward path connected in the binary tree otherwise return False.

// In this context downward path means a path that starts at some node and goes downwards.

#include <iostream> 
using namespace std ; 

class Node{
public :
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ;
        left = right = NULL ;
    }
}; 

class LinkedList{
public : 
    int data ;
    LinkedList* next ; 

    LinkedList(int x){
        data = x ; 
        next = NULL ;
    }
}; 

bool match(Node* root , LinkedList* head) { 
    if( head == nullptr ) return true ;  
    if( root == nullptr ) return true ; 

    if( root -> data != head -> data ) return false ; 

    return match( root -> left , head -> next ) || match( root -> right , head -> next ) ; 
} 

bool check(Node* root , LinkedList* head) {
    if( root == NULL ) return false ; 

    if( match( root , head ) ) return true ; 

    return check( root -> left , head ) || check( root -> right , head ) ; 
}

int main() {
    // creating the binary tree
    Node* root = new Node(1) ; 
    root -> left = new Node(4) ; 
    root -> right = new Node(4) ; 

    root -> left -> right = new Node(2) ;  
    root -> left -> right -> left = new Node(1) ;  

    root -> right -> left = new Node(2) ; 
    root -> right -> left -> left = new Node(6) ; 
    root -> right -> left -> right = new Node(8) ; 

    root -> right -> left -> right -> left = new Node(1) ; 
    root -> right -> left -> left -> right = new Node(3) ; 

    // creating the linked list  
    LinkedList* head = new LinkedList(4) ; 
    head -> next = new LinkedList(2) ; 
    head -> next -> next = new LinkedList(8) ; 

    cout << "Checking if true " << endl; 

    if( check(root ,head) ) {
        cout << "TRUE" << endl;
    } 
    else{
        cout << "FALSE" << endl;
    } 

    return 0 ; 
}