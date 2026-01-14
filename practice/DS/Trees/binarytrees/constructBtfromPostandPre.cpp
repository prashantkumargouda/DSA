// constructing a binary tree from postOrder and preOrder 
 
#include <iostream> 
#include <vector> 
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
}; 

Node* constructBinaryTree(vector<int> &postorder , vector<int> &preorder , int &preindex , int poststart , int postend , unordered_map<int,int> postMap) {
    if( preindex >= preorder.size() || poststart > postend )  {
        return ; 
    }     

    Node* root = new Node(preorder[preindex++]);

    if( poststart == postend ) return root ; 

    int leftRootVal = preorder[preindex];
    int postIndex = postMap[leftRootVal];

    root -> left = constructBinaryTree(postorder , preorder , preindex , poststart , postIndex , postMap ) ; 
    root -> right = constructBinaryTree(postorder , preorder , preindex , postIndex +1 , postend - 1 , postMap ) ; 
    return root ; 
}
Node* buildTree(vector<int> &postorder , vector<int> &preorder ) {
    int n = postorder.size() ; 

    unordered_map<int, int> postMap ; 

    for(int i=0 ; i<n ; i++) {
        postMap[postorder[i]] = i ; 
    } 

    int preindex = 0 ; 

    return constructBinaryTree(postorder , preorder , preindex , 0  ,n-1 ,postMap) ; 
}
int main() {

}