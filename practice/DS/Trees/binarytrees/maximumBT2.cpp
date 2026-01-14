// 998. Maximum Binary Tree II  

// medium 

#include <iostream> 
#include <vector>  
#include <algorithm>  
#include <unordered_map> 

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
} ; 
 
vector<int> inOrder(Node* root , vector<int> &res) {
    if( root == NULL ) return ; 

    inOrder( root -> left , res ) ; 
    res.push_back(root -> data) ; 
    inOrder( root -> right , res ) ;
} 

Node* insertInto(Node* root , int val) { 
    vector<int> res ; 

    inOrder(root , res) ;  
    res.push_back(val) ; 

    int n = res.size() ; 
    // so appended the val value into the inorder list 
    // now construct the tree from this inorder 

    unordered_map<int , int> checkMap ; 

    for(int i=0 ; i<n ; i++){
        checkMap[res[i]] = i ; 
        
    }


}

int main() { 
    Node* root = new Node(5) ; 
    root -> left = new Node(2) ; 
    root -> left -> right = new Node(1) ;

    root -> right = new Node(4) ; 

    int val = 3 ; 

    Node* temp = insertInto(root , val) ; 

}