// breadth first search traversal 

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 

// creating the adj 
vector<vector<int>> makeCheck() { 
    // the no of edges and no of nodes
    int n, m ; 
    cin >> n >> m ; 

    // adjacecncy list 
    
    vector<vector<int>> adj(n+1) ;  // starting with 1 (1-index)  
    for(int i=0 ; i<m ; i++) {
        // take the elements for input  
        int u , v ; 
        cin >> u >> v  ; 

        adj[u].push_back(v) ; 
        adj[v].push_back(u) ;
    } 

    return adj ; 
}  
 
vector<int> bfs(vector<vector<int>> &adj , int n) {
    // using this adjacency list to form the level order   
    // visited array of size n+1 
    // for 0,1,2,3 ......... x 
    vector<int> vis(n+1 , 0) ;  
    vis[1] = 1 ; 
    queue<int> q ; 
    q.push(1) ; 

    vector<int> bfs ; 
    while( !q.empty() ) {
        int node = q.front() ;
        q.pop() ;

        bfs.push_back(node) ;  

        for(auto it : adj[node]) {
            if( !vis[it] ) {
                vis[it] = 1 ; 
                q.push(it) ; 
            }
        } 

        return bfs ; 
    }
} 

int main() {  

    vector<vector<int>> res = makeCheck() ;  
    int n = 5 ; 
    vector<int> temp = bfs(res , n) ;  

    for(auto i : temp) {
        cout << i << " " ;  
    } 

    cout << endl; 

    return 0 ; 
}