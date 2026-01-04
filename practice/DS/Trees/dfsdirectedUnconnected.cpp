// dfs on a directed disconnected graph 

#include <iostream> 
#include <vector> 

using namespace std ;  

void dfsRec(vector<vector<int>> &adj , vector<bool> &visited , int s ) {
    visited[s] = true ; 

    cout << s << " " ; 
    for(int e : adj[s] ) {
        if( visited[e] == false ){
            dfsRec(adj , visited , e) ;
        }
    }
}  

void dfs(vector<vector<int>> adj) {
    vector<bool> visited( adj.size() , false ) ; 

    // we do this process for each element 
    // to solve the problem of disconneted graph 
    for(int i=0 ; i<adj.size() ; i++) {
        if( visited[i] == false ) {
            dfsRec(adj , visited , i ) ; 
        }
    }
}

void addEdge(vector<vector<int>> &adj , int u , int v) { 
    // directed so only added once 
    adj[u].push_back(v) ;
} 

int main() {  
    int v = 6 ;  
    // using this adjacency list for the graph 
    vector<vector<int>> adj(v) ;  

    // using the edges 
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};  
    
    for(vector<int> e : edges ) {
        addEdge(adj , e[0] , e[1] ) ;   
    }

    dfs(adj) ; 

    return 0 ; 

}