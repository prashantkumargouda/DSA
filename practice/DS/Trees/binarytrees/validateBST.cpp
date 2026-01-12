#include <iostream> 
#include <climits> 

using namespace std ; 

class TreeNode {
public : 
    int data ; 
    TreeNode* left ;
    TreeNode* right ; 

    TreeNode(int x) {
        data = x ; 
        left = right = NULL ; 
    } 
} ; 

bool check(TreeNode* root , long minVal , long maxVal ) {
        if( root == NULL ) return true;     

        if( root -> data <= minVal || root -> data >= maxVal ) {
            return false ; 
        } 

        return  check(root -> left , minVal , root -> data ) && 
                check( root -> right , root -> data , maxVal ) ; 
    } 

bool isValidBST(TreeNode* root) {
        return check(root , LONG_MIN , LONG_MAX ) ; 
} 

int main(){
    TreeNode* root = new TreeNode(5) ; 
    root -> left = new TreeNode(1) ; 
    root -> right = new TreeNode(4) ; 
    root -> right -> left = new TreeNode(3); 

    root -> right -> right = new TreeNode(6) ;  

    cout << isValidBST(root) << endl; 

    return 0 ; 

}