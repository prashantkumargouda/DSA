// 2265. Count Nodes Equal to Average of Subtree
// counting the number of nodes equal to the average of nodes in its subtree 
// medium 

#include <iostream> 
#include <vector> 
#include <unordered_map> 

using namespace std ; 

class Node {
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x) {
        data = x ; 
        left = right = NULL ; 
    }
}; 

int nodeCount = 0; 

int check(Node* root , int &count , int &avg) {
    if( root == NULL ) return 0 ; 

    avg += root -> data ; 
    count += 1 ;
    check(root -> left ,count , avg) ; 
    check(root -> right ,count , avg ) ; 

    return avg ; 
}

int averageofSubTree(Node* root) {
    if( root == NULL ) return 0 ; 

    int count = 0 ; 
    int avg = 0 ; 

    int x = check(root , count , avg ) ; 
    if( root -> data == x/count) {
        nodeCount += 1 ; 
    } 

    if( root -> left ) averageofSubTree(root -> left) ; 
    if( root -> right ) averageofSubTree( root -> right ) ; 

    return nodeCount ; 
    
}

int main() {
    Node* root = new Node(4) ; 
    root -> left = new Node(8) ; 
    root -> right = new Node(5) ; 

    root -> left -> right = new Node(1) ; 
    root -> left -> left = new Node(0) ; 

    root -> right -> right = new Node(6) ; 

    int x = averageofSubTree(root) ; 

    cout << x << endl; 

    return 0 ; 

}