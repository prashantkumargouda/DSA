// performing dfs on a disconnected graph 

#include <iostream>  
#include <vector> 
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

void dfsRec(vector<vector<int>> &adj , vector<bool> &visited , int s , vector<int> &res) {
    visited[s] = true ;  
    res.push_back(s) ; 

    // iske baad we check for the elements to which it is connected 
    for(int i: adj[s]) {
        if(visited[i] == false) {
            dfsRec(adj , visited , i , res) ;
        }
    }
}

vector<int> dfs(vector<vector<int>> adj) {
    // here we loop through all the vertices to find the 
    // elements which are not connected and not yet visited 
    // and then visit those nodes 

    vector<bool> visited(adj.size() , false) ; 
    vector<int> res ; 

    // here we check for each element present in the adj 
    // and visit that element 

    for(int i=0 ; i<adj.size() ; i++) {
        if( visited[i] == false ) {
            dfsRec(adj , visited , i , res ) ; 
        }
    }

    return res ;
}

void addEdge(vector<vector<int>> &adj , int u , int v ) {
    // using this adjacent matrix to form the binary tree  
    // and this is a disconnected tree being traversed using dfs 
    adj[u].push_back(v) ; 
    adj[v].push_back(u) ;
} 

int main(){
    int V = 6;
    vector<vector<int>> adj(V);
    
    // creating adjacency list
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 5, 4);

    vector<int> res = dfs(adj); 
    
    for (auto it : res)
        cout << it << " ";
        
    return 0;
}