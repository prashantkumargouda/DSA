// dfs traversal 

// create your adjacency list 
// create the dfs function 

#include <iostream>  
#include <vector> 
using namespace std ; 

vector<vector<int>> makeCheck(int n , int m) { 
    vector<vector<int>> adj(n+1) ;  // to return 

    for(int i=0 ; i<m ; i++) {
        int u , v ; 
        cin >> u >> v ; 

        adj[u].push_back(v) ; 
        adj[v].push_back(u) ; 
    } 
    
    return adj ; 
}    
 
void dfs(int node , vector<vector<int>> adj , vector<int> &ls , vector<int> &vis) {
    vis[node] = 1 ; 
    ls.push_back(node) ; 

    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it , adj , ls , vis) ; 
        }
    } 
}    

