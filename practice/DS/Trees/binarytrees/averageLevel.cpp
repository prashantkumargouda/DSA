// finding the average of each level of a binary tree 

#include <iostream> 
#include <queue> 

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

vector<double> averageOfLevels(Node* root) {
    vector<double> res ; 

    if(root == NULL) return res ;  

    double avg = 0 ;  

    queue<Node*> q ;    
    q.push(root) ; 

    while( !q.empty() ) {
        int size = q.size() ; 
        double total = 0 ; 
        for(int i=0 ; i<size ; i++) {
            Node* curr = q.front() ; 
            q.pop() ; 

            total += curr -> data ; 

            if( curr -> left ) q.push(curr -> left) ; 
            if( curr -> right) q.push(curr -> right) ; 
        }    
        avg = total / size ; 

        res.push_back(avg) ; 
    }
    return res ; 
}  

int main(){ 
    Node* root = new Node(3) ; 
    root -> left = new Node(9) ;
    root -> right = new Node(20) ; 
    root -> right -> left = new Node(15) ; 
    root -> right -> right = new Node(7) ; 

    vector<double> temp = averageOfLevels(root) ; 

    for(auto &e : temp) {
        cout << e << " " ;  
   }
   
   return 0 ; 
}