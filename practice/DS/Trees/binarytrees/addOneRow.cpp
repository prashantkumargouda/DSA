// 623. Add One Row to Tree 

// Given the root of a binary tree and two integers val and depth, 
// add a row of nodes with value val at the given depth depth.

// Note that the root node is at depth 1.

// The adding rule is:
// 1.Given the integer depth, for each not null tree node cur at the depth depth - 1, 
//   create two tree nodes with value val as cur's left subtree root and right subtree root. 

// 2.cur's original left subtree should be the left subtree of the new left subtree root. 

// 3.cur's original right subtree should be the right subtree of the new right subtree root.

// 4.If depth == 1 that means there is no depth depth - 1 at all, then create a tree node 
//   with value val as the new root of the whole original tree, and the original tree is 
//   the new root's left subtree. 


#include <iostream> 
#include <vector>  
#include <queue> 

using namespace std ; 

class Node{
public : 
    int data;  
    Node* left ; 
    Node* right ; 
 
    Node(int x) {
        data = x ; 
        left = right = NULL ;
    }
}; 

void check(Node* root , int val , int depth , int level){ 

    if( root == NULL ) return ; 

    if( level == depth - 1 ) { 
        Node* newLeft = new Node(val); 
        Node* newRight = new Node(val); 

        newLeft -> left = root -> left ; 
        newRight -> right = root -> right ; 
        
        root -> left = newLeft ; 
        root -> right = newRight ;  
        return  ; 
    }

    check( root -> left, val , depth , level + 1 ) ; 
    check( root -> right, val , depth , level + 1 ) ;

}    
 
Node* addOneRow(Node* root , int val , int depth ) {

    if( depth == 1 ) {
        Node* newNode = new Node(val) ; 
        newNode -> left = root ;  

        return newNode ; 
    }
    
    check(root , val , depth , 1) ; 
    return root ;
}  
 
Node* addOneRow1(Node* root , int val , int depth) { 

    if( depth == 1 ) {
        Node* newNode = new Node(val) ; 
        newNode -> left = root ; 

        return newNode ; 
    }

    queue<Node*> q ;   
    int level = 1 ; 
    
    q.push(root) ;  

    while( !q.empty() ) {
        int len = q.size() ; 

        if( level == depth -1 ) {
            for(int i=0 ; i<len ; i++) {
                Node* curr = q.front() ; 
                q.pop() ; 

                Node* newLeft = new Node(val) ; 
                Node* newRight = new Node(val) ; 

                newLeft -> left = curr -> left ; 
                newRight -> right = curr -> right ;

                curr -> left = newLeft ; 
                curr -> right = newRight ; 
            }  
            break ; 
        } 

        for(int i=0 ; i<len ; i++) { 
            Node* curr = q.front() ;
            q.pop() ; 
            if( curr -> left ) q.push(curr -> left) ; 
            if( curr -> right ) q.push(curr -> right) ; 
        }
        level++ ; 
    } 

    return root ; 
}

void levelOrder(Node* root , int level , vector<vector<int>> &res){
    
    if( root == NULL ) {
        return ;
    } 
    
    if( res.size() <= level ) {
        res.push_back({}) ; 
    } 
    
    res[level].push_back(root -> data) ; 
    
    levelOrder(root -> left , level + 1 , res) ; 
    levelOrder(root -> right , level + 1 , res) ;   
  
} 

int main() {
    Node* root = new Node(4) ; 
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 
    
    root -> left -> left = new Node(5) ; 
    root -> left -> right = new Node(6) ; 

    root -> right -> right = new Node(8) ; 
    root -> right -> left = new Node(7) ;  

    addOneRow(root , 1 , 3) ;  

    vector<vector<int>> res ;
        
    levelOrder(root , 0 , res) ;   
    
    for(auto &e : res) {
        for(int x : e) {
            cout << x << " ";
        } 
        cout << endl; 
    } 
    
    return 0 ; 
}   