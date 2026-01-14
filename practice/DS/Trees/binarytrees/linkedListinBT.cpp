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

bool isCorrect(Node* root , LinkedList* head) {
    
}

int main() {

}