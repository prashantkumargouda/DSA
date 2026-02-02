// detecting cycle in an undirected graph 
// using bfs 

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 

bool detect(int src , vector<int> adj[] , vector<int> &vis) {
    vis[src] = 1 ;  // marked source as already visited 

    queue<pair<int , int>> q ; 
    q.push({src , -1}) ; 

    while(!q.empty()) {
        int node = q.front().first ;  
        int check = q.front().second ; 
        q.pop() ; 

        for(auto it : adj[node]) {
            if( !vis[it] ) {
                vis[it] = 1 ; 
                q.push({it , node}) ; 
            }  
            else if( node != vis[it] ) {
                return true ; 
            } 
        }
    } 

    return false ;  
} 

bool isCycle(int V , vector<int> adj[]) {
    vector<int> vis(V , 0) ;

    for(int i=0 ; i<V ; i++) {
        if( !vis[i] ) {
            if(detect(i , adj , vis)) {
                return true ; 
            }
        }
    } 

    return false ; 
} 

int main() {

}