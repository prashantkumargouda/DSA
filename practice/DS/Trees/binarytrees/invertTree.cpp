// inverting a binary tree 

#include <iostream> 
#include <vector> 
using namespace std ; 

class Node {
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x) {
        data = x ; 
        left = right = NULL ; 
    }
};  

Node* invertTree(Node* root) {
    if( root == NULL ) return NULL ; 

    Node* temp = root -> right ; 
    root -> right = root -> left ; 
    root -> left = temp ; 

    invertTree(root -> left) ; 
    invertTree(root -> right) ; 

    return root ; 
}
void inorder(Node* root , vector<int> &res) {
    if( root == NULL ) return ; 

    inorder(root -> left , res); 
    res.push_back(root-> data) ;  
    inorder(root -> right , res) ; 
} 

int main() {
    Node* root = new Node(4) ; 
    root -> left = new Node(8) ; 
    root -> right = new Node(5) ; 

    root -> left -> right = new Node(1) ; 
    root -> left -> left = new Node(0) ; 

    root -> right -> right = new Node(6) ;  

    Node* temp = invertTree(root) ; 

    vector<int> res ; 
    inorder( temp , res) ; 

    for(int x : res) {
        cout << x << endl; 
    } 

    return 0 ; 

}