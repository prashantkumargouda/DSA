#include <iostream> 
#include <vector> 

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

void check(Node* root , vector<vector<int>> &res ,vector<int> &temp ,int target , int sum ){
    if(!root) return ;  

    sum += root -> data ; 

    temp.push_back(root -> data) ;

    if(!root -> left && !root -> right && sum == target ) { 
        res.push_back(temp) ;  
        temp.pop_back(); 
        return ; 
    } 
    check(root -> left , res , temp , target , sum ) ;  
    check(root -> right , res, temp , target , sum ) ;   

    temp.pop_back() ; 
    return ; 
} 

vector<vector<int>> pathSum(Node* root , int targetSum) { 
    vector<vector<int>> res  ; 
    if(!root) return res;  
    vector<int> temp ; 
    check(root , res , temp , targetSum , 0 ) ; 

    return res ; 
} 

int main() {
    Node* root = new Node(5) ;  
    root -> left = new Node(4) ; 
    root -> right = new Node(8) ; 

    root -> left -> left = new Node(11) ;
    root -> left -> left -> left = new Node(7) ; 

    root -> left -> left -> right = new Node(2) ; 

    root -> right -> left = new Node(13) ; 
    root -> right -> right = new Node(4) ; 

    root -> right -> right -> left = new Node(5) ;
    root -> right -> right -> right = new Node(1) ;  

    Node* root1 = new Node(1) ; 
    root1 -> left = new Node(2) ; 
    root1 -> right = new Node(3) ; 

    vector<vector<int>> res1 = pathSum(root1 , 5) ; 
    vector<vector<int>> res = pathSum(root , 22) ;  

    for(auto &e : res1) {
        for(auto &i : e) {
            cout << i << " " ;
        } 
        cout << endl; 
    }

    return 0 ; 
}