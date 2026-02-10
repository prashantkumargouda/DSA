// bipartite graphs with connected components 
#include <iostream>
#include <queue> 
#include <vector> 

using namespace std ; 

bool check( int start , int V , vector<vector<int>> &adj , vector<int> &vis ) {
    queue<int> q ; 
    q.push(start) ; 

    vis[start] = 0 ; 

    while( !q.empty() ) {
        int node = q.front() ; 
        q.pop() ; 

        for(auto it : adj[node]) {
            if( vis[it] == -1 ){
                vis[it] == !vis[node] ; 
                q.push(it); 
            } 
            else if( vis[it] == vis[node] ) {
                return false ; 
            }
        }
    } 

    return true ; 
} 

bool isBipartite(int V , vector<vector<int>> &edges) {
    vector<int> vis( V , -1 ) ; 

    vector<vector<int>> adj(V) ; 

    for( auto &e : edges ) {
        int u = e[0] ; 
        int v = e[1] ; 

        adj[u].push_back(v) ; 
        adj[v].push_back(u) ; 
    } 

    for(int i=0 ; i<V ; i++) {
        if( vis[i] == -1 ) {
            if( !check(i , V , adj , vis) ) {
                return false ; 
            } 
        }
    } 

    return true ; 
} 

int main(){

}