// finding the height or depth of a binary tree 

// 2 methods 
// recursive and another one is level order traversal 

#include <iostream>  
#include <queue> 

using namespace std ; 

class Node{
public:
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ; 
        left = right = nullptr ;
    }
}; 

int height(Node* root) {
    if( root == nullptr ) {
        return -1 ;
    } 

    int lheight = height(root -> left) ;
    int rheight = height(root -> right) ; 

    return max( lheight , rheight ) + 1 ;
} 

int qheight(Node* root) {
    // visiting all the nodes possible 
    // making use of a queue to do so 

    queue<Node*> q ; 

    int currLevel = 0; 
    q.push(root) ; 
    
    while(!q.empty()) {
        int len = q.size() ;  

        for(int i=0 ; i<len ; i++){
            Node* curr = q.front() ; 
            q.pop() ; 

            if( curr -> left != nullptr ) {
                q.push( curr -> left ) ; 
            } 
            if( curr -> right != nullptr ) {
                q.push( curr -> right ) ; 
            }
        } 
        currLevel++ ; 
    } 

    return currLevel-1 ; 

} 

int main(){
    Node* root = new Node(12) ; 
    root -> left = new Node(8) ;
    root -> right = new Node(18) ; 

    root -> left -> left = new Node(5) ; 

    root -> left -> right = new Node(11) ; 

    cout << height(root) << endl; 
    cout << qheight(root) << endl; 
    return 0 ; 

} 








































































































// bhai just chase your dreams 
// and see yourself where you stand 
// try to do something great and something which you are not imagining at this point of your life 
// to be great you need to work like the greats    

