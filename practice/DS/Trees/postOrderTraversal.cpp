#include <iostream>
#include <vector> 
#include <stack> 
using namespace std ; 

class Node{
public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int x) {
        data= x ; 
        left = right = nullptr ;
    }
};  

// using two stacks first to get the required result 
vector<int> postOrder1( Node* root ) {
    vector<int> res ; 
    if( root == NULL ) {
        return res ;  
    } 

    stack<Node*> st1 , st2 ; 
    Node* curr ; 
    st1.push(root) ; 

    while( !st1.empty() ) {
        curr = st1.top() ; 
        st1.pop() ; 
        st2.push(curr) ; 

        if( curr -> left != NULL ) {
            st1.push( curr -> left ); 
        } 
        if( curr -> right != NULL ) {
            st1.push( curr -> right ) ;
        }  
    } 

    while( !st2.empty() ) {
        curr = st2.top() ; 
        st2.pop() ; 
        res.push_back( curr -> data ) ; 
    }
    return res ; 
}  

// using a single stack 
// and pushing those elements twice into the stack 
// pehli baar jab milega apne bacho ko process karega 
// dusri baar jab milega khud ko process karega 

vector<int> postOrder2(Node* root) {
    vector<int> res ; 
    stack<Node*> st ; 

    while(true) {
        while( root ) {
            st.push(root) ; 
            st.push(root) ; 
            root = root -> left ;
        } 

        if( st.empty() ) {
            return res ;
        } 
        
        root = st.top() ; 
        st.pop() ; 

        if( !st.empty() && st.top() == root ) { // this means pehli baar check ho raha hai left ke baad root jaana hai 
            root = root -> right ; 
        }
        else{
            res.push_back(root -> data) ;
            root = NULL ;
        } 
    } 

    return res; 
}

vector<int> postOrder3(Node* root) {
    vector<int> res ; 

    if( root == NULL ) {
        return res ;
    } 

    stack<Node*> st ; 

    while( root != nullptr || !st.empty() ) {
        // go to the left most node 
        // and while doing so
        // keep pushing the right node and root node 
        while( root != NULL ) {
            if( root -> right != NULL ) {
                st.push(root->right) ; 
            } 
            st.push(root)  ; 
            root = root -> left ; 
        } 

        // now what should I do buddy 
        root = st.top() ; 
        st.pop() ; 

        if( !st.empty() && root -> right != nullptr && st.top() == root -> right ) {
            st.pop() ; 
            st.push(root) ;
            root = root -> right ; 
        } 
        else{
            res.push_back(root -> data) ; 
            root = nullptr;
        }
    } 

    return res ; 
}
int main() { 
    Node* root = new Node(1) ; 
    root -> left = new Node(2) ; 
    root -> right = new Node(3) ; 

    root -> left -> left = new Node(4) ; 
    root -> left -> right = new Node(5) ; 

    root -> right -> left = new Node(6) ;   
    root -> right -> right = new Node(7) ; 

    vector<int> temp1 = postOrder1(root) ;  
    for(int x : temp1) {
        cout << x << " " ; 
    } 

    cout << endl;   
    vector<int> temp2 = postOrder2(root) ; 
    for(int x : temp2) {
        cout << x << " " ; 
    } 
    cout << endl;   

    vector<int> temp3 = postOrder3(root) ; 
    for(int x : temp3) {
        cout << x << " " ; 
    } 
    cout << endl; 

    return 0 ; 
}