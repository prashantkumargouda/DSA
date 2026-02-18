#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std ; 

    bool dfs(int node ,vector<int> &vis , vector<vector<int>> &adj , vector<int> &check , vector<int> &pathVis) {
        vis[node] = 1 ; 
        pathVis[node] = 1 ; 

        check[node] = 0 ; 

        for(auto it : adj[node]) {
            if( !vis[it] ) {
                if( dfs(it , vis , adj , check , pathVis ) ) { 
                    return true ; 
                } 
            }
            else if( pathVis[it] ) {
                return true ; 
            } 
        } 
        
        check[node] = 1 ; 
        pathVis[node] = 0 ;  

        return false ;
    } 

vector<int> safeNodes(int V , vector<vector<int>> &edges) { 
    vector<vector<int>> adj(V) ; 

    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]) ; 
    } 

    vector<int> vis(V , 0) ;
    vector<int> check(V , 0) ; 

    vector<int> pathVis(V,0) ; 

    for(int i=0 ; i<V ; i++) {
        if( !vis[i] ) {
            dfs( i , vis , adj , check , pathVis ) ; 
        }
    } 

    vector<int> safe ; 

    for(int i=0 ; i<V ; i++) {
        if( check[i] == 1 ) safe.push_back(i); 
    } 

    return safe ; 
} 

int main() {
    int V = 5 ; 
    vector<vector<int>> edges = {{1,0} , {1,2} , {1,3} , {1,4} ,{ 2,3} , {3,4} } ; 

    vector<int> temp = safeNodes(V , edges) ; 
    for(auto it : temp ) {
        cout << it << " " ; 
    } 

    return 0 ; 
}