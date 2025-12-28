#include <iostream>
#include <vector> 
#include <stack> 
using namespace std ; 

class Node{
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x) {
        data= x ; 
        left = right = nullptr ;
    }
};  

// using two stacks first to get the required result 
vector<int> postOrder( Node* root ) {
    vector<int> res ; 
    if( root == NULL ) {
        return res ;  
    } 

    stack<Node*> st1 , st2 ; 
    Node* curr ; 
    st1.push(root) ; 

    while( !st1.empty() ) {
        curr = st1.top() ; 
        st1.pop() ; 
        st2.push(curr) ; 

        if( curr -> left != NULL ) {
            st1.push( curr -> left ); 
        } 
        if( curr -> right != NULL ) {
            st1.push( curr -> right ) ;
        }  
    } 

    while( !st2.empty() ) {
        curr = st2.top() ; 
        st2.pop() ; 
        res.push_back( curr -> data ) ; 
    }
    return res ; 
} 

int main() { 
    Node* root = new Node(1) ; 
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(5) ; 

    root -> right -> left = new Node(6) ;   
    root -> right -> right = new Node(7) ; 

    vector<int> temp = postOrder(root) ;  

    for(int x : temp) {
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}