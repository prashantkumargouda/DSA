// shortest path in a directed acyclic graph 

// 1. finding the topo sort for the DAG first 
// 2. then using a distance vector to find the shortest distance and return the vector  

#include <iostream>  
#include <vector> 
#include <stack> 

using namespace std ;  

void topoSort(int node , vector<vector<pair<int , int>>> &adj , vector<int> &vis , stack<int> st) {
    vis[node] = 1 ; 

    for(auto it : adj[node]) { 
        int v = it.first ; 
        if( !vis[v] ) { 
            topoSort(v , adj , vis , st) ; 
        }
    } 

    st.push(node) ; 
} 

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // given the number of nodes = V  
    // the number of edges = E  
    // the edges vector 

    // forming the adjacency list 

    vector<vector<pair<int,int>>>  adj(V) ; 

    for(int i=0 ; i<E ; i++) {
        int u = edges[i][0] ; 
        int v = edges[i][1] ; 
        int wt = edges[i][2] ; 

        adj[u].push_back({v,wt}) ;  
    }  


    vector<int> vis(V) ; 
    stack<int> st ;

    for(int i=0 ; i<V ; i++) {
        if( !vis[i] ) {
            topoSort( i , adj ,  vis , st) ;
        }
    } 

    vector<int> dis(V , INT_MAX) ; 

    // using this dis to return the solution 

    dis[0] = 0 ;  
    while( !st.empty() ) {
        int node = st.top() ;
        st.pop() ; 

        for(auto it : adj[node]) {
            int v = it.first ; 
            int wt = it.second ; 

            if( dis[node] + wt < dis[v] ) {
                dis[v] = dis[node] + wt ; 
            }
        }
    } 

    return dis ;
}   

int main() { 
    
}