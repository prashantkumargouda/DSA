// 654. Maximum Binary Tree  

// medium 

// You are given an integer array nums with no duplicates. 
// A maximum binary tree can be built recursively from nums using the following algorithm:

// Create a root node whose value is the maximum value in nums.
// Recursively build the left subtree on the subarray prefix to the left of the maximum value.
// Recursively build the right subtree on the subarray suffix to the right of the maximum value.
// Return the maximum binary tree built from nums.

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
};  

Node* build( vector<int> &nums , int start , int end , unordered_map<int , int> checkMap) {
    if( start > end ) {
        return NULL ; 
    } 

    int newVal = *max_element( nums.begin() + start , nums.begin() + end + 1) ;  
    Node* root = new Node(newVal) ;  

    int index = checkMap[newVal] ; 
    root -> left = build(nums , start , index -1  , checkMap ) ; 
    root -> right = build( nums ,index + 1 , end , checkMap) ; 

    return root ; 
} 
 
Node* construct(vector<int> &nums) { 
    int n = nums.size() ; 
    unordered_map<int , int> checkMap ; 

    for(int i=0 ; i<n ; i++) {
        checkMap[nums[i]] = i ; 
    }

    return build(nums, 0 , n-1 , checkMap ) ; 
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() { 
    vector<int> nums = {3,2,1,6,0,5} ; 

    Node* root = construct(nums) ;  

    cout << "printing the maximum tree " << endl; 

    printInorder(root) ; 
    cout << endl; 

    return 0 ; 
}