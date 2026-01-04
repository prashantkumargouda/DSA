// 107. Binary Tree Level Order Traversal II
// traversing the array in reverse order 

#include <iostream>  
#include <queue>  
#include <algorithm> 

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

// this is the dfs method 
// we take all the levels  
// and then reverse and return the array  

vector<vector<int>> levelOrder1(Node* root) { 
    vector<vector<int>> res;  
    if( root == NULL ) {
        return res ;
    } 

    queue<Node*> q ; 
    q.push(root) ; 

    int currLevel = 0 ; 
    while( !q.empty() ) {
        int size = q.size() ; 
        res.push_back({}) ; 

        for(int i=0 ; i<size ; i++) {
            Node* curr = q.front() ;
            q.pop() ; 
            res[currLevel].push_back(curr -> data) ; 

            if( curr -> left ) q.push(curr -> left) ; 
            if( curr -> right ) q.push(curr -> right) ; 
        } 
        currLevel++ ;
    }

    reverse(res.begin() , res.end() ) ;   // this is not going to return a new vector and it is part of algorithm
    return res ; 
} 

// second method 
// using dfs 
// where we pass on the levels too to store the values at their required levels 
void levelOrder2(Node* root , int level , vector<vector<int>> res) {
    if( root == NULL ) return ; 
    if( level == res.size() ) res.push_back({}) ;  // add a bracket for that level 

    if( root -> left ) levelOrder2(root -> left , level + 1 , res); 
    if( root -> right ) levelOrder2(root -> right , level + 1 , res);  
} 

// this is the third method 

int findMaxLen(Node* root) { // to find the height of binary tree
    if( root == NULL ) return  ; 

    return 1+max( findMaxLen(root -> left) , findMaxLen( root -> right) )  ; 
}

void leftOrderRec(Node* root , vector<vector<int>> res, int level) {
    if( root == NULL ) return  ; 

    res[level].push_back(root -> data) ;  
    leftOrderRec(root -> left , res, level -1 ) ; 
    leftOrderRec( root -> right , res , level -1 ) ; 
} 

vector<vector<int>> levelOrderBottom(Node* root) {
    vector<vector<int>> res ; 

    if( root == NULL ) return ; 

    int count = findMaxLen( root ) ; 

    for(int i=0 ; i<count ; i++){
        vector<int> temp ; 
        res.push_back(temp) ; 
    } 

    leftOrderRec(root , res , count -1 ) ; 

} 

