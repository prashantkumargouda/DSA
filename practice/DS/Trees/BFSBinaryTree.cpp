// level order binary tree traversal 

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 

class Node{
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    // constructor 
    Node(int x) {
        data = x ;
        left = right = NULL ; 
    }
} ; 

// using recursion 
// approach 1  O(n) time and O(n) space 

void levelOrderRec(Node* root , int level , vector<vector<int>> &res ) {
    if( root == NULL ) return ; 

    if( res.size() <= level ) {
        res.push_back({}) ; 
    } 

    res[level].push_back( root -> data ) ; 

    levelOrderRec( root -> left , level + 1 , res )  ; 
    levelOrderRec( root -> right , level + 1 , res ) ;  
} 

vector<vector<int>> levelOrder(Node* node){
    vector<vector<int>> res ;

    levelOrderRec( node , 0 , res ) ; 
    return res ; 
}  
 
// Expected approach 
// using queue so iterative 
// okay using queue to get O(n) and O(n) time and space  

vector<vector<int>> levelOrder2(Node* root){
    vector<vector<int>> res ; 
    
    int currLevel = 0 ; 
    queue<Node*> q ;  

    q.push(root) ; 

    while( !q.empty() ) {
        int len = q.size() ; 
        res.push_back({}) ;  // adding an empty vector for the nested vector each time we reach a new level  

        for(int i=0 ; i<len ; i++) { 
            Node* curr = q.front() ;  // got the first element from the queue 
            q.pop() ;  

            res[currLevel].push_back(curr -> data) ; 

            if( curr -> left != nullptr ) {
                q.push( curr -> left)  ; 
            }
            if( curr -> right != nullptr ) {
                q.push( curr -> right ) ; 
            }  
        } 
        currLevel++ ;
    } 

    return res ;
} 

int main() {
    Node* root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11); 

    vector<vector<int>> temp = levelOrder(root) ; 

    for( vector<int> level : temp ) {
        cout << " " ;
        for(int x : level) {
            cout << x << " " ; 
        } 
        cout << "|" ; 
    } 

    cout << endl; 
    
    vector<vector<int>> temp1 = levelOrder2(root) ; 

    for( vector<int> level : temp1 ) {
        cout << " " ;
        for(int x : level) {
            cout << x << " " ; 
        } 
        cout << "|" ; 
    } 

    cout << endl; 
    return 0 ; 
}