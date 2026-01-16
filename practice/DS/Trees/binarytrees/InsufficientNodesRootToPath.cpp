// 1080. Insufficient Nodes in Root to Leaf Paths 
// medium 

#include <iostream> 
#include <vector> 

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

Node* check(Node* root , int limit , int sum) {
    if( root == NULL ) return NULL ; 

    sum += root -> data ; 

    // deletion of leaf node if sum is less than limit 
    if( !root -> left && !root -> right ) {
        if( sum < limit ) {
            return nullptr ; 
        }
        return root ; 
    } 

    root -> left = check( root -> left , limit , sum ) ; 
    root -> right = check( root -> right , limit , sum ) ; 

    // if all the nodes through this from root to leaf are sum < limit then it is insufficient so deleted 

    if( !root -> left && !root -> right ){
        return nullptr ; 
    } 

    return root ; 

} 

Node* sufficientNodes(Node* root , int limit) {
    return check(root , limit , 0) ;  
}

vector<int> inorder(Node* root , vector<int> &res) {
    if( root == NULL ) return {} ; 

    inorder(root -> left , res) ; 
    res.push_back(root -> data) ; 
    inorder( root -> right , res) ; 
}

int main() {
    Node* root = new Node(1) ; 
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(-99) ; 

    root -> right -> left = new Node(-99) ; 
    root -> right -> right = new Node(7) ; 

    root -> right -> left -> left = new Node(12) ; 
    root -> right -> left -> right = new Node(13) ; 

    root -> right -> right -> left = new Node(-99) ; 
    root -> right -> right -> right = new Node(14) ; 

    vector<int> res ; 
    int limit = 1 ; 
    Node* temp = sufficientNodes(root , limit)  ; 

    vector<int> temp1 = inorder(temp , res) ; 
    
    for(int x : temp1) {
        cout << x << " "; 
    } 

    cout << endl; 

    return 0 ; 

}