// detect a cycle in a directed graph 

#include <iostream> 
#include <vector> 

using namespace std ; 

bool dfs(int node , vector<int> &vis , vector<vector<int>> &adj , vector<int> &pathVis) {
    vis[node] = 1 ; 
    pathVis[node] = 1 ; 

    // abhi traverse the adjacent nodes like dfs  
    for(auto it : adj[node]) { 
        if( !vis[it] ) {
            if( dfs(it , vis , adj , pathVis) ) return true ; 
        } 
        else if( pathVis[it] ) {
            return true ; 
        }
    } 

    pathVis[node] = 1 ; 
    return false ; 
} 

bool isCycle(int V ,  vector<vector<int>> &edges) {
    // creating the adjacency list 
    vector<vector<int>> adj(V); 

    for(auto &e : edges) {
        int u = e[0] ; 
        int v = e[1] ; 
        
        adj[u].push_back(v) ; 
    } 

    vector<int> vis(V , 0) ; 
    vector<int> pathVis(V , 0) ; 

    for(int i=0 ; i<V ; i++) { 
        if( !vis[i] ) {
            if( dfs(i , vis , adj , pathVis ) ) return true ; 

        }
    } 
    return false ; 
} 

int main(){

}