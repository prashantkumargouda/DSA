// 103. Binary Tree Zigzag Level Order Traversal 
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' 
// values. (i.e., from left to right, then right to left for the next level and alternate between). 

// medium 

#include <iostream>  
#include <vector> 
#include <queue> 

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

vector<vector<int>> zigzagLevelOrder(Node* root) { 
    vector<vector<int>> res ; 
    if( root == NULL ) return res;  

    queue<Node*> q ; 
    q.push( root ) ; 

    int level = 0 ; 
    while( !q.empty() ) {
        int size = q.size() ; 
        res.push_back({}) ; 
        
        for(int i=0 ; i<size ; i++) {
            Node* curr = q.front() ; 
            q.pop() ; 
            
            res[level].push_back(curr -> data) ; 
            if( level % 2 == 0 ) {
                if( curr -> right ) q.push( curr -> right ) ; 
                if( curr -> left ) q.push( curr -> left  ) ; 
            } 
            else {
                if( curr -> left ) q.push( curr -> left  ) ;  
                if( curr -> right ) q.push( curr -> right ) ;
            }
        }   
        level++ ; 
    }  

    return res ; 
}

int main() { 
    Node* root = new Node(3) ;
    root -> left = new Node(9) ; 
    root -> right = new Node(20) ; 

    root -> right -> left = new Node(15) ; 
    root -> right -> right = new Node(7) ; 

    vector<vector<int>> temp = zigzagLevelOrder(root) ; 

    for( vector<int> t : temp ) {
        for(int x : t ) {
            cout << x << " " ;
        } 
        cout << endl; 
    }
    
    return 0 ; 
}