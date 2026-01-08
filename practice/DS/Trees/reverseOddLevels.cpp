// 2415. Reverse Odd Levels of Binary Tree
// Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

// For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
// Return the root of the reversed tree.

// A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

// The level of a node is the number of edges along the path between it and the root node. 


#include <iostream> 
#include <vector> 
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

Node* reverseOddLevels(Node* root) { 
    bool reverse = false ; 

    queue<Node*> q ; 
    q.push(root) ; 

    while( !q.empty() ) {
        int qs = q.size() ; 
        vector<Node*> res(qs) ; 
        for(int i=0 ; i<qs ; i++) {
            Node* curr = q.front() ;
            q.pop() ;
            
            if( curr -> left ) q.push(curr -> left) ; 
            if( curr -> right ) q.push(curr -> right) ; 

            if( !reverse ) {
                res[i] = curr ; 
                if( i >= qs / 2 ) {
                    swap( res[i] -> data , res[qs - 1 - i] -> data ) ; 
                }
            } 
        } 

        reverse = !reverse ;  
    } 

    return root ; 
} 

int main() {

}