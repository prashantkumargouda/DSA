// 222. Count Complete Tree Nodes 
// easy 
// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last, 
// is completely filled in a complete binary tree, 
// and all nodes in the last level are as far left as possible. 
// It can have between 1 and 2h nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity. 

#include <iostream> 
#include <vector> 
using namespace std ; 

class Node{
public :  
    int data  ; 
    Node* left ; 
    Node* right ; 

    Node(int x){
        data = x ; 
        left = right = NULL ; 
    }
}; 

void checkCount(Node* root , int level ,vector<vector<int>> &res ) {
    if( root == NULL ) {
        return ; 
    }  
    if( level >= res.size() ) {
        res.push_back({}) ; 
    } 
    res[level].push_back(root -> data) ; 
    
    checkCount( root -> left , level + 1 ,res ) ; 
    checkCount( root -> right , level + 1 , res ) ; 
}

int countNodes(Node* root) {
    if( root == NULL ) return 0 ; 

    vector<vector<int>> res ;

    checkCount(root , 0 , res) ; 

    int count = 0 ; 
    for( auto &e : res ){
        for(int i=0 ; i<e.size() ; i++ ){
            count++ ;
        }
    } 
     
    return count ; 
}

int main() {
    Node* root = new Node(1) ; 
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    cout << countNodes(root) << endl; 

    return 0 ;
}