//  trying to find the largest node in each row 

#include <iostream>  
#include <queue>  
#include <climits> 
#include <algorithm> 

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

vector<int> largestValues(Node* root) { 
    vector<int> res ; 

    if( root == NULL ){
        return res ; 
    }
    queue<Node*> q ; 
    q.push(root) ; 

    while( !q.empty() ) {
        int len = q.size() ; 
        int maxi = INT_MIN ; 

        for(int i=0 ; i<len ; i++) {
            Node* curr = q.front() ; 
            q.pop() ; 

            maxi = max(curr -> data, maxi) ; 

            if( curr -> left != NULL ) {
                q.push(curr -> left) ; 
            } 
            if( curr -> right != NULL ) {
                q.push(curr -> right) ; 
            }
        }   

        res.push_back(maxi) ; 
    } 

    return res ; 
}

int main() {
    Node* root = new Node(1) ; 
    root -> left = new Node(3) ; 
    root -> right = new Node(2) ; 

    root -> left -> left = new Node(5) ; 
    root -> left -> right = new Node(3) ;  

    root -> right -> right = new Node(9) ; 


    vector<int> temp = largestValues(root) ; 

    for(int x : temp) {
        cout << x << " ";
    } 

    cout << endl; 

    return 0 ; 
}