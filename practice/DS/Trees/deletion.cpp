// deleting a node 

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
        left = right = NULL ;
    }
}; 

void deleteDeepest(Node* root , Node* dNode ) {
    // no need to check for the root node 

    queue<Node*> q ; 
    q.push(root) ; 
    Node* curr ; 
    while( !q.empty() ) {
        curr = q.front() ; 
        q.pop() ; 
 
        if( curr == dNode ) { 
            curr = nullptr ; 
            delete(curr)  ; 
            return  ;
        } 

        if( curr -> right != NULL ) {
            if( curr -> right == dNode ) {
                curr -> right = NULL ;  
                delete(curr -> right) ; 
                return ; 
            } 
            q.push(curr -> right ) ; 
        } 
        if( curr -> left != NULL ) {
            if( curr -> left == dNode ) {
                curr -> left = NULL ; 
                delete(curr -> left) ; 
                return ; 
            } 
            q.push(curr -> left) ; 
        }
    }
} 

Node* deletion(Node* root , int key ) {
    if( root == NULL ) {
        return NULL ;
    } 

    if( root -> left == nullptr && root -> right == nullptr ) {
        if( root -> data == key ) {
            return nullptr ; 
        } 
        else {
            return root ;  // if root is the only node in the tree and it has no child nodes 
        }
    } 

    // checked the root node 
    // now using queue to check for each node and then finding the deepest node also 

    queue<Node*> q ; 
    q.push(root) ;  

    Node* curr ; 
    Node* keyNode ;  

    while( !q.empty() ) {
        curr = q.front() ; 
        q.pop() ; 

        if( curr -> data == key ) {
            keyNode = curr ; 
        } 

        if( curr -> left != nullptr ) {
            q.push(curr -> left) ;
        } 
        if( curr -> right ) {
            q.push(curr -> right) ; 
        }
    }   

    // okay found the keyNode( Node to be deleted ) and deepestNode( curr Node points to it ) 
    if( keyNode != nullptr ) { 
        int x = curr -> data ; 
        keyNode -> data = x ; 
        // now deleting the deepest node  

        deleteDeepest(root , curr)  ; 
    }  
    
    return root ; 
} 

void inorder(Node* root) {
    if( root == NULL ) {
        return ;
    } 

    inorder( root -> left ) ; 
    cout << root -> data << " " ; 
    inorder( root -> right ) ; 
} 

int main() {
    Node* root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
     
    root = deletion(root , 11) ; 

    inorder(root)  ; 

    return 0 ; 
}