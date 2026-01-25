// 257. Binary Tree Paths

// Easy

// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children. 

#include <iostream> 
#include <vector> 
#include <string>  

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

void check(Node* root , string s , vector<string> &res) { 
    s += to_string(root -> data) ;  

    if(root -> left) {
        check( root -> left , s+"->" , res) ; 
    } 
    if(root -> right) {
        check( root -> right , s+"->" , res) ; 
    } 

    if( !root -> left && !root -> right ) {
        res.push_back(s) ; 
    }
} 

vector<string> binaryTreePaths(Node* root){ 
    vector<string> res ; 
    if( !root ) return res ; 
 
    check(root , "" , res ) ; 
    return res ; 
}
int main() {
    Node* root = new Node(1) ; 
    root -> left =  new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> right = new Node(5) ; 

    vector<string> res = binaryTreePaths(root) ;  

    for(auto &e : res) {
        cout << e << endl;  
    } 

    cout << endl;  

    return 0 ; 

}