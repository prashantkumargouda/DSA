// trying out DFS in a binary tree 
// this is dfs for a connected and undirected graph 

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

void dfsRec(vector<vector<int>> &adj , vector<int> &visited ,int s, vector<int> &res) {
    // now what to do bhai 
    visited[s] = true ; 
    res.push_back(s) ; 

    for(int i : adj[s] ) {
        if( visited[i] == false ) { // if the node is not yet visited 
            dfsRec(adj , visited , i , res ) ; 
        }
    } 
} 

vector<int> dfs(vector<vector<int>> adj) {
    vector<int> visited( adj.size() , false ) ;  // a visited vector with all values marked as false  
    vector<int> res ; // to return the result 

    dfsRec(adj , visited , 0 , res ) ; 

    return res ; 
}
void addEdge(vector<vector<int>> &adj , int u , int v ) {
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}  

int main() {
    int V = 5 ; 

    vector<vector<int>> adj(V) ; 

    addEdge( adj , 1 , 2 ) ;
    addEdge( adj , 1 , 0 ) ; 
    addEdge( adj , 2 , 0 ) ;
    addEdge( adj , 2 , 3 ) ;
    addEdge( adj , 2 , 4 ) ; 

    vector<int> res = dfs(adj) ;   

    for(int i : res) {
        cout << i << " " ; 
    } 
    
    cout << endl; 
    return 0 ; 
}