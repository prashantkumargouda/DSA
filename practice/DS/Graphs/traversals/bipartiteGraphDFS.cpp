// bipartite graph using DFS  

#include <iostream> 
#include <vector> 

using namespace std ;

bool dfs(int start , int col , vector<vector<int>> &adj , vector<int> &color) {
    color[start] = col ; 

    for(auto it : adj[start]) {
        if( color[it] == -1 ) {
            if( dfs(it , !col , adj , color )) return false ; 
        } 
        else if( color[it] == col ) {
            return false ; 
        }
    }  
    return true ; 
}
bool isBipartite(int V , vector<vector<int>> &edges) {
    vector<int> color(V , -1) ; 

    vector<vector<int>> adj ; 

    for(auto &e : edges) {
        int u = e[0] ; 
        int v = e[1] ; 

        adj[u].push_back(v) ; 
        adj[v].push_back(u) ; 
    }

    for(int i=0 ; i<V ; i++) {
        if(color[i] == -1) {
            if( !dfs( i , 0 , adj , color ) ) {
                return false ; 
            } 
        }
    } 

    return true ; 
}
int main(){

}