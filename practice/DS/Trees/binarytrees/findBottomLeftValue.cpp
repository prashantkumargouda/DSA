// Given the root of a binary tree, return the leftmost dataue in the last row of the tree. 

#include <iostream> 
#include <queue> 

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

int findBottomLeftValue1(Node* root) {
        // trying out the res method 

    if( root == NULL ) {
        return -1 ; 
    } 

    vector<vector<int>> res ; 
    queue<Node*> q ; 

    q.push(root) ; 
    int level = 0 ; 

    while( !q.empty() ) {
        int len = q.size() ; 
        res.push_back({}) ; 
        for(int i=0 ; i<len ; i++) {
            Node* curr = q.front() ; 
            q.pop() ; 
            
            res[level].push_back(curr -> data) ;
            if( curr -> left != nullptr ) {
                q.push(curr -> left)  ;
            } 
            if( curr -> right != nullptr ) {
                q.push(curr -> right) ;
            } 
        } 
        level++ ; 
    }  
    return res[level-1][0] ; 
}
int findBottomLeftValue2(Node* root) {
    queue<Node*> q;
    q.push(root);

    int ans = root->data;

    while (!q.empty()) {
        int len = q.size();
        ans = q.front()->data;   // leftmost of this level

        for (int i = 0; i < len; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return ans;
}

// bhai we need to find the left most element of the last row 
int findBottomLeftValue3(Node* root) {
    queue<Node*> q;
    q.push(root);

    Node* curr = root;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr->right) q.push(curr->right);
        if (curr->left)  q.push(curr->left);
    }
    return curr->data;
}


int main() {
    Node* root = new Node(2) ; 
    root -> left = new Node(1) ; 
    root -> right = new Node(3) ; 

    cout << findBottomLeftValue1(root) << endl; 
    cout << findBottomLeftValue3(root) << endl; 
    cout << findBottomLeftValue2(root) << endl; 
    return 0 ; 
}