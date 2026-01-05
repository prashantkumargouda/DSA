#include <iostream> 
#include <deque> 
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
}; 

vector<vector<int>> zigzag(Node* root) {
    vector<vector<int>> res ; 
    if( root == NULL ) return res; 

    deque<Node*> dq ; 
    dq.push_back(root) ;  

    bool reverse = false ; 

    while( !dq.empty() ) {
        int size = dq.size() ; 
        vector<int> level ; 

        for(int i=0 ; i<size ; i++){
            if( !reverse ) {
                Node* curr = dq.front() ; 
                dq.pop_front() ; 

                level.push_back(curr -> data) ; 
                if( curr -> left ) dq.push_back(curr -> left) ; 
                if( curr -> right ) dq.push_back(curr -> right) ; 
            } 
            else {
                Node* curr = dq.back() ; 
                dq.pop_back() ; 

                level.push_back(curr -> data) ; 
                if( curr -> right ) dq.push_front( curr -> right) ; 
                if( curr -> left ) dq.push_front(curr -> left) ; 
            }
        }  

        res.push_back(level) ;
        reverse = !reverse ; 
    } 

    return res ; 
} 

int main() {
    Node* root = new Node(3) ;
    root -> left = new Node(9) ;

    root -> right = new Node(20) ; 
    root -> right -> left = new Node(15) ; 

    root -> right -> right = new Node(7) ; 

    vector<vector<int>> temp = zigzag(root) ; 

    for(auto &e : temp) {
        for(int x:e) {
            cout << x << " " ; 
        }   
        cout << endl; 
    } 

    return 0 ; 
} 