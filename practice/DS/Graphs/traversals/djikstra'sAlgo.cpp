// using the djisktras algorithm  
// to find the minimum cost distance from the source node to target node 

// given a weighted undirected graph and a source vertex src. 
// We need to find the shortest path distances from the source vertex to all other vertices in the graph. 

// Input: src = 0, adj[][] = [[[1, 4], [2, 8]],         
//                                             [[0, 4], [4, 6], [2,3]], 
//                                             [[0, 8], [3, 2], [1,3]], 
//                                             [[2, 2], [4, 10]], 
//                                             [[1, 6], [3, 10]]] 

#include <iostream>  
#include <vector> 
#include <queue> 

using namespace std ; 

vector<int> findShortest(int V , vector<vector<int>> &edges , int src){
    vector<vector<pair<int, int>>> adj(V) ; 
    vector<int> dis(V) ; 

    for(auto &e : edges) {
        int u = e[0] ; 
        int v = e[1] ; 
        int wt = e[2] ;
         
        adj[u].push_back({v , wt}) ;
        adj[v].push_back({u , wt}) ;
    }  

    priority_queue< pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ; 
    
    dis[src] = 0 ; 
    pq.push({0 , src}) ; 

    while( !pq.empty() ) {
        int node = pq.top().second ; 
        int dist = pq.top().first ; 

        pq.pop() ; 
        if( dist > dis[node] ) continue ;  

        for(auto &it : adj[node]) {
            int v = it.first ; 
            int wt = it.second ; 

            if( dist + wt < dis[v] ) {
                dis[v] = dist + wt ;  
                pq.push({ dis[v] , v }) ; 
            } 
        }
    } 

    return dis ; 
} 

int main() { 

}