#include <iostream>  
#include <vector> 
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
} ; 

bool check(Node* root , vector<int>& res , int x ){
    if( root == NULL ) return false ; 

    res.push_back( root -> data ) ; 

    if( root -> data == x ) {
        return true ; 
    } 

    if( check( root -> left , res , x ) || check( root -> right , res , x ) ) {
        return true ;
    } 

    res.pop_back() ; 
    return false ; 
}

vector<int> solution(Node* root , int x) { 
    vector<int> res ; 
    if( root == NULL ) return res ; 

    check(root , res , x) ; 

    return res ;
}
int main() {
    Node* root = new Node(1) ;  
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(5) ;

    root -> left -> right -> left = new Node(6)  ; 
    root -> left -> right -> right = new Node(7) ; 

    vector<int> res = solution(root , 7) ; 

    for( auto &e : res ) {
        cout << e << endl; 
    }  

    return 0 ; 

}